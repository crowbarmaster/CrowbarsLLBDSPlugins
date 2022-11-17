#include "pch.h"
#include <llapi/Global.h>
#include <llapi/LoggerAPI.h>
#include <llapi/DynamicCommandAPI.h>
#include <llapi/FormUI.h>
#include <llapi/LLAPI.h>
#include <llapi/mc/Actor.hpp>
#include <llapi/mc/Player.hpp>
#include <llapi/mc/ArmorItem.hpp>
#include <llapi/mc/Level.hpp>
#include <llapi/mc/Inventory.hpp>
#include <llapi/mc/Mob.hpp>
#include <llapi/mc/ItemStack.hpp>
#include <llapi/mc/SlotData.hpp>
#include <llapi/mc/ListTag.hpp>
#include <llapi/EventAPI.h>
#include <llapi/mc/Block.hpp>
#include <llapi/RegCommandAPI.h>
#include <map>
#include <vector>
#include <string>
#include "SimpleIni.h"

using namespace RegisterCommandHelper;
using namespace Form;
using namespace std;

constexpr auto ARMOR_SLOT_COUNT = 4;

enum class ArmorSlot : int32_t {
    Head = 0,
    Chest = 1,
    Legs = 2,
    Feet = 3
};

CSimpleIniA IniFile;

string configPath = "plugins/CrowbarTools.ini";
Logger logger("CrowbarTools");
string sourceXUID;
string targetXUID;
map<string, string> playerInvSyncMap = map<string, string>();
bool copyBagLock = false;
bool debugOutput = false;

void CopyHotBar(Player* srcPlayer, Player* destPlayer) {
    for (int i = 0; i < 9; i++) {
        ItemStack temp(srcPlayer->getInventory().getItem(i));
        destPlayer->getInventory().setItem(i, temp);
    }
    destPlayer->sendInventory(false);
    logger.info("Hot bar has been synced.");
}

void CopyPlayerBag(Player* srcPlayer, Player* destPlayer) {
    copyBagLock = true;
    Container& inv = srcPlayer->getInventory();
    for (int i = 0; i < inv.getSize(); i++) {
        ItemStack temp(inv.getItem(i));
        destPlayer->getInventory().setItem(i, temp);
    }
    destPlayer->sendInventory(false);
    logger.info("Inventory has been synced.");
    copyBagLock = false;
}

void CopyPlayerArmor(Player* srcPlayer, Player* destPlayer) {
    for (int i = 0; i < ARMOR_SLOT_COUNT; i++) {
        ItemStack newArm(srcPlayer->getArmor((ArmorSlot)i));
        destPlayer->setArmor((ArmorSlot)i, newArm);
    }
    destPlayer->setOffhandSlot(srcPlayer->getOffhandSlot());
    destPlayer->updateEquipment();
    destPlayer->sendInventory(false);
    logger.info("Armor has been synced.");
}

bool SaveConfig() {
    return IniFile.SaveFile(configPath.c_str()) == 0;
}

bool LoadConfig() {
    IniFile.Reset();
    return IniFile.LoadFile(configPath.c_str()) == 0;
}

vector<string> TerminatedStringToVector(string input, string term) {
    vector<string> output = vector<string>();
    size_t curPos = 0;
    size_t termPos = 0;
    string parsed;
    if (input.find(term) == string::npos) {
        output.push_back(input);
        return output;
    }
    while (input.find(term, curPos) != string::npos) {
        termPos = input.find(term, curPos);
        parsed = input.substr(curPos, termPos - curPos);
        curPos = termPos + term.length();

        output.push_back(parsed);
    }
    if (curPos != input.length()) {
        output.push_back(input.substr(curPos, input.length() - curPos));
    }
    return output;
}

string VectorToTerminatedString(vector<string> input, string term) {
    string output;
    for (string entry : input) {
        output.append(entry);
        output.append(term);
    }
    return output;
}

void CommandEditForm(Player* targetPlayer) {
    list<CSimpleIniA::Entry> values = list<CSimpleIniA::Entry>();
    if (!IniFile.GetAllValues("CmdList", targetPlayer->getXuid().c_str(), values)) {
        IniFile.SetValue("CmdList", targetPlayer->getXuid().c_str(), "None");
    }
    CustomForm form = CustomForm("Command Editor");
    form.addLabel("CurCmdLbl", "Current commands:");
    form.addDropdown("Cmds", "Command List", TerminatedStringToVector(IniFile.GetValue("CmdList", targetPlayer->getXuid().c_str()), ">>"));
    form.addInput("NewCmd", "NewCmd:");
    form.addToggle("SaveToggle", "Save Command");
    form.addToggle("DelToggle", "Delete Command");
    form.sendTo(targetPlayer, [](Player* pl, std::map<string, std::shared_ptr<Form::CustomFormElement>> mp) {
        string playerXuid = pl->getXuid();
        if (mp.empty()) {
            return;
        }
        vector<string> currentCmds = TerminatedStringToVector(IniFile.GetValue("CmdList", pl->getXuid().c_str()), ">>");
        bool saveToggle = mp["SaveToggle"]->getBool();
        bool delToggle = mp["DelToggle"]->getBool();
        string newCmd = mp["NewCmd"]->getString();
        string dropCmd = mp["Cmds"]->getString();
        if ((saveToggle && delToggle) || (!saveToggle && !delToggle)) {
            return;
        }
        if (currentCmds.size() == 1 && currentCmds[0] == "None") {
            currentCmds.erase(currentCmds.begin());
        }
        if (saveToggle) {
            if (newCmd == "") {
                return;
            }
            vector<string> splitStr = TerminatedStringToVector(newCmd, ">>");
            for (string entry : splitStr) {
                currentCmds.push_back(entry);
            }
        }
        if (delToggle && dropCmd != "None") {
                for (int i = 0; i < currentCmds.size(); i++) {
                    if (currentCmds[i] == dropCmd) {
                        currentCmds.erase(currentCmds.begin() + i);
                    }
                }
        }
        IniFile.SetValue("CmdList", pl->getXuid().c_str(), VectorToTerminatedString(currentCmds, ">>").c_str());
        SaveConfig();
        });
}

void RunCommandList(Player* targetPlayer) {
    vector<string> currentCmds = TerminatedStringToVector(IniFile.GetValue("CmdList", targetPlayer->getXuid().c_str()), ">>");
    if (currentCmds.size() != 0) {
        for (string cmd : currentCmds) {
            targetPlayer->runcmd(cmd);
            Sleep(500);
        }
    }
}

void RemoveInvMapEntry(string key) {
    auto entry = playerInvSyncMap.find(key);
    if (entry != playerInvSyncMap.end()) {
        playerInvSyncMap.erase(entry);
    }
}

void SendPlayerToServer(Player* targetPlayer, string ipAddress, int port) {
    targetPlayer->transferServer(ipAddress, port);
}

class CrowToolsCommands : public Command {
    enum class Cmds :int {
        setArmor,
        sethotbar,
        setinventory,
        copyArmor,
        copyhotbar,
        copyinventory,
        autoinventory,
        tele2server,
        editForm,
        runCmdList
    } cmdOp;
    string targetAddress;
    int targetPort;
    bool send2ServerSet = false;
    CommandSelector<Player> target;
    virtual void execute(CommandOrigin const& ori, CommandOutput& outp) const
    {
        auto result = target.results(ori);
        if (result.count() > 1 || result.empty()) {
            return;
        }
        Player* caller = ori.getPlayer();
        Player* playerTarget = *result.begin();
        switch (cmdOp)
        {
        case CrowToolsCommands::Cmds::copyArmor:
            logger.info("Syncing " + playerTarget->getRealName() + "'s armor...");
            CopyPlayerArmor(playerTarget, caller);
            break;
        case CrowToolsCommands::Cmds::setArmor:
            logger.info("Syncing " + caller->getRealName() + "'s armor...");
            CopyPlayerArmor(caller, playerTarget);
            break;
        case CrowToolsCommands::Cmds::copyhotbar:
            logger.info("Syncing " + playerTarget->getRealName() + "'s hotbar...");
            CopyHotBar(playerTarget, caller);
            break;
        case CrowToolsCommands::Cmds::sethotbar:
            logger.info("Syncing " + caller->getRealName() + "'s hotbar...");
            CopyHotBar(caller, playerTarget);
            break;
        case CrowToolsCommands::Cmds::copyinventory:
            logger.info("Syncing " + playerTarget->getRealName() + "'s inventory...");
            CopyPlayerBag(caller, playerTarget);
            break;
        case CrowToolsCommands::Cmds::setinventory:
            caller = playerTarget;
            playerTarget = ori.getPlayer();
            logger.info("Syncing " + caller->getRealName() + "'s inventory...");
            CopyPlayerBag(caller, playerTarget);
            break;
        case CrowToolsCommands::Cmds::autoinventory:
            playerInvSyncMap[playerTarget->getXuid()] = caller->getXuid();
            CopyPlayerBag(playerTarget, caller);
            break;
        case CrowToolsCommands::Cmds::tele2server:
            if (send2ServerSet) {
                SendPlayerToServer(playerTarget, targetAddress, targetPort);
            } else {
                SendPlayerToServer(caller, targetAddress, targetPort);
            }
            break;
        case CrowToolsCommands::Cmds::editForm:
            CommandEditForm(ori.getPlayer());
            break;
        case CrowToolsCommands::Cmds::runCmdList:
            RunCommandList(ori.getPlayer());
            break;
        default:
            break;
        }
    }
public:
    static void setup(CommandRegistry* registry) {
        registry->registerCommand("crowtools", "Collection of tools by Crowbarmast3r.", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
        registry->addEnum<Cmds>("PlayerCommands",
        {
            {"copyarmor", Cmds::copyArmor},
            {"copyhotbar", Cmds::copyhotbar},
            {"copyinventory", Cmds::copyinventory},
            {"setarmor", Cmds::setArmor},
            {"sethotbar", Cmds::sethotbar},
            {"setinventory", Cmds::setinventory},
            {"autoinventory", Cmds::autoinventory},
        });
        registry->addEnum<Cmds>("Teleport",
            {
                    {"tele2server", Cmds::tele2server},
            });
        registry->addEnum<Cmds>("Window",
            {
                    {"editform", Cmds::editForm},
                    {"runcmdlist", Cmds::runCmdList},
            });
        registry->registerOverload<CrowToolsCommands>("crowtools",
            makeMandatory<CommandParameterDataType::ENUM>(&CrowToolsCommands::cmdOp, "function", "Window"));

        registry->registerOverload<CrowToolsCommands>("crowtools",
            makeMandatory<CommandParameterDataType::ENUM>(&CrowToolsCommands::cmdOp, "function", "PlayerCommands"),
            makeMandatory(&CrowToolsCommands::target, "target"));

        registry->registerOverload<CrowToolsCommands>("crowtools", makeMandatory<CommandParameterDataType::ENUM>(&CrowToolsCommands::cmdOp, "function", "Teleport"),
            makeMandatory(&CrowToolsCommands::targetAddress, "address"),
            makeMandatory(&CrowToolsCommands::targetPort, "port"),
            makeOptional(&CrowToolsCommands::target, "targetPlayer", &CrowToolsCommands::send2ServerSet)
            );

    }
};

// Main

void entry()
{
    if (!LoadConfig()) {
        logger.warn("Could not open CrowbarTools.ini from the plugins folder.");
    }
    string debug = IniFile.GetValue("Settings", "DebugEnabled");
    debugOutput = debug == "true" ? true : false;
    Event::PlayerInventoryChangeEvent::subscribe([](const Event::PlayerInventoryChangeEvent& ev) {
        if (!playerInvSyncMap.contains(ev.mPlayer->getXuid())) {
            return true;
        }
        string regXUID = playerInvSyncMap[ev.mPlayer->getXuid()];
        if (regXUID == "") {
            return true;
        }
        string srcXUID = ev.mPlayer->getXuid();
        Player* src = ev.mPlayer;
        Player* tgt = ev.mPlayer->getLevel().getPlayerByXuid(regXUID);
        if (tgt == nullptr) {
            playerInvSyncMap.erase(ev.mPlayer->getXuid());
            return true;
        }
        if (debugOutput) {
            logger.info("Source Player object test: " + src->getXuid());
            logger.info("Target Player object test: " + tgt->getXuid());
        }
        ItemStack oldItem = ItemStack(*ev.mPreviousItemStack);
        ItemStack newItem = ItemStack(*ev.mNewItemStack);
        string newItemName = newItem.getName();
        if (newItemName == "") {
            if (debugOutput) {
                logger.info("Old ItemStack: " + oldItem.toDebugString());
                logger.info("Slot: {0}", ev.mSlot);
            }
            tgt->getInventory().setItem(ev.mSlot, newItem.EMPTY_ITEM);
        }
        else {
            if (debugOutput) {
                logger.info("New ItemStack: " + newItem.toDebugString());
                logger.info("Slot: {0}", ev.mSlot);
            }
            tgt->getInventory().setItem(ev.mSlot, newItem);
        }
        tgt->sendInventory(true);
        return true;
        });

     Event::PlayerStartDestroyBlockEvent::subscribe([](const Event::PlayerStartDestroyBlockEvent& ev) {
        if (debugOutput) {
            logger.info("PlayerStartDestroyBlockEvent");
            BlockInstance block = ev.mBlockInstance;
            logger.info(block.getPosition().toString());
        }
        return true;
    });

    Event::RegCmdEvent::subscribe([](const Event::RegCmdEvent& ev) {
        CrowToolsCommands::setup(ev.mCommandRegistry);
        return true;
    });
}
