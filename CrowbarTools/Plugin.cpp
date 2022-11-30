#include "pch.h"
#include <llapi/Global.h>
#include <llapi/LoggerAPI.h>
#include <llapi/DynamicCommandAPI.h>
#include <llapi/FormUI.h>
#include <llapi/LLAPI.h>
#include <llapi/mc/Actor.hpp>
#include <llapi/mc/Player.hpp>
#include <llapi/mc/SimulatedPlayer.hpp>
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
map<string, string> playerInvSyncMap = map<string, string>();
bool copyBagLock = false;
bool debugOutput = false;

void CopyHotBar(Player* srcPlayer, Player* destPlayer) {
    for (int i = 0; i < 9; i++) {
        ItemStack temp(srcPlayer->getInventory().getItem(i));
        if (debugOutput) {
            logger.debug("Hotbar item in slot: {0}\r\n{1}", i, temp.toDebugString());
        }
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
        if (debugOutput) {
            logger.debug("Inventory item in slot: {0}\r\n{1}", i, temp.toDebugString());
        }
        destPlayer->getInventory().setItem(i, temp);
    }
    destPlayer->sendInventory(false);
    logger.info("Inventory has been synced.");
    copyBagLock = false;
}

void CopyPlayerArmor(Player* srcPlayer, Player* destPlayer) {
    for (int i = 0; i < ARMOR_SLOT_COUNT; i++) {
        ItemStack newArm(srcPlayer->getArmor((ArmorSlot)i));
        if (debugOutput) {
            logger.debug("Armor item in slot: {0}\r\n{1}", i, newArm.toDebugString());
        }
        destPlayer->setArmor((ArmorSlot)i, newArm);
    }
    ItemStack offHand = srcPlayer->getOffhandSlot();
    if (debugOutput) {
        logger.debug("Off-hand item: {0}", offHand.toDebugString());
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
    auto result = IniFile.LoadFile(configPath.c_str());
    if (result != 0) {
        IniFile.SetValue("Settings", "DebugEnabled", "false");
        SaveConfig();
    }
    return true;
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

void VerifyPlayerAllowed(Player* player) {
    string foundPlayer = IniFile.GetValue("Allowlist", player->getXuid().c_str(), "deny");
    if (foundPlayer == "deny") {
        player->kick("You have been denied access to this server. Contact server admin.");
    }
}

void AddPlayerAllow(Player* player) {
    IniFile.SetValue("AllowList", player->getXuid().c_str(), player->getRealName().c_str());
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

void PlayerAllowForm(Player* targetPlayer) {
    list<CSimpleIniA::Entry> values = list<CSimpleIniA::Entry>();
    if (!IniFile.GetAllKeys("AllowList", values)) {
        IniFile.SetValue("AllowList", targetPlayer->getXuid().c_str(), targetPlayer->getRealName().c_str());
    }
    CustomForm form = CustomForm("Allowlist Editor");
    list<CSimpleIniA::Entry> entryList;
    IniFile.GetAllKeys("Allowlist", entryList);
    vector<string> regPlayers = vector<string>();
    for (CSimpleIniA::Entry& entry : entryList) {
        regPlayers.push_back(entry.pItem);
    }
    form.addDropdown("RegPlay", "Registered players", regPlayers);
    form.addInput("NewPlayer", "new player:", "XUID>>PlayerName");
    form.addToggle("SaveToggle", "Save registration");
    form.addToggle("DelToggle", "Delete registration");
    form.sendTo(targetPlayer, [](Player* pl, std::map<string, std::shared_ptr<Form::CustomFormElement>> mp) {
        string playerXuid = pl->getXuid();
        if (mp.empty()) {
            return;
        }
        list<CSimpleIniA::Entry> allowedPlayers;
        IniFile.GetAllKeys("AllowList", allowedPlayers);
        bool saveToggle = mp["SaveToggle"]->getBool();
        bool delToggle = mp["DelToggle"]->getBool();
        string newPly = mp["NewPlayer"]->getString();
        string dropPly = mp["RegPlay"]->getString();
        if ((saveToggle && delToggle) || (!saveToggle && !delToggle)) {
            return;
        }
        if (saveToggle) {
            if (newPly == "") {
                return;
            }
            vector<string> splitStr = TerminatedStringToVector(newPly, ">>");
            if (splitStr.size() != 2) {
                return;
            }
            IniFile.SetValue("AllowList", splitStr[0].c_str(), splitStr[1].c_str());
        }
        if (delToggle && dropPly != pl->getXuid()) {
            IniFile.Delete("Allowlist", dropPly.c_str());
        }
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

void RunTests(Player* caller) {
    Player* sim = caller->getLevel().getPlayer("ServerTestes");
    vector<Player*> playerList = Level::getAllPlayers();
    for (Player* ply : playerList) {
        logger.info("Player getName: " + ply->getName());
        logger.info("Player getRealName: " + ply->getRealName());
        logger.info("Player getXuid: " + ply->getXuid());
        if (ply->getName() == "ServerTestes") {
            sim = ply;
        }
    }
    if (sim == nullptr) {
        SimulatedPlayer* newPlayer = SimulatedPlayer::create("ServerTestes", *new BlockPos(0, 0, 70));
        newPlayer->setXuid("012345678912345");
        sim = newPlayer;
    }
    CopyHotBar(caller, sim);
    for (int i = 0; i < 9; i++) {
        logger.debug("Sim player item {0} contains {1}", i, sim->getInventory().getItem(i).toDebugString());
    }
    CopyPlayerBag(caller, sim);
    int invSize = caller->getInventory().getSize();
    for (int i = 0; i < caller->getInventory().getSize(); i++) {
        logger.debug("Sim player inventory item {0} contains {1}", i, sim->getInventory().getItem(i).toDebugString());
    }
    CopyPlayerArmor(caller, sim);
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
        runCmdList,
        runTests
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
            CopyPlayerArmor(caller, playerTarget);
            break;
        case CrowToolsCommands::Cmds::setArmor:
            logger.info("Syncing " + caller->getRealName() + "'s armor...");
            CopyPlayerArmor(playerTarget, caller);
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
            logger.info("Syncing " + caller->getRealName() + "'s inventory...");
            CopyPlayerBag(playerTarget, caller);
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
        case CrowToolsCommands::Cmds::runTests:
            RunTests(caller);
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
            {"runtests", Cmds::runTests},
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
    string debug = IniFile.GetValue("Settings", "DebugEnabled", "false");
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
            logger.debug("Source Player object test: " + src->getXuid());
            logger.debug("Target Player object test: " + tgt->getXuid());
        }
        ItemStack oldItem = ItemStack(*ev.mPreviousItemStack);
        ItemStack newItem = ItemStack(*ev.mNewItemStack);
        string newItemName = newItem.getName();
        if (newItemName == "") {
            if (debugOutput) {
                logger.debug("Old ItemStack: " + oldItem.toDebugString());
                logger.debug("Slot: {0}", ev.mSlot);
            }
            tgt->getInventory().setItem(ev.mSlot, newItem.EMPTY_ITEM);
        }
        else {
            if (debugOutput) {
                logger.debug("New ItemStack: " + newItem.toDebugString());
                logger.debug("Slot: {0}", ev.mSlot);
            }
            tgt->getInventory().setItem(ev.mSlot, newItem);
        }
        tgt->sendInventory(true);
        return true;
        });

     Event::PlayerStartDestroyBlockEvent::subscribe([](const Event::PlayerStartDestroyBlockEvent& ev) {
        if (debugOutput) {
            logger.debug("PlayerStartDestroyBlockEvent");
            BlockInstance block = ev.mBlockInstance;
            logger.debug(block.getPosition().toString());
        }
        return true;
    });

    Event::RegCmdEvent::subscribe([](const Event::RegCmdEvent& ev) {
        CrowToolsCommands::setup(ev.mCommandRegistry);
        return true;
    });
}
