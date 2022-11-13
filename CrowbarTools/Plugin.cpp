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

Logger logger("CrowbarTools");
bool keepAligned = false;
bool TeleLearn = false;
BlockInstance BlockX;
BlockInstance BlockY;
BlockInstance BlockZ;
map<string, vector<string>> playerCommandList = map<string, vector<string>>();
bool debugOutput = false;

void CopyHotBar(Player* srcPlayer, Player* destPlayer) {
    for (int i = 0; i < 9; i++) {
        ItemStack temp(destPlayer->getInventory().getItem(i));
        srcPlayer->getInventory().setItem(i, temp);
    }
    srcPlayer->sendInventory(false);
    logger.info("Hot bar has been synced.");
}

void CopyPlayerBag(Player* srcPlayer, Player* destPlayer) {
    Container& inv = destPlayer->getInventory();
    for (int i = 0; i < inv.getSize(); i++) {
        ItemStack temp(inv.getItem(i));
        srcPlayer->getInventory().setItem(i, temp);
    }
    srcPlayer->sendInventory(false);
    logger.info("Inventory has been synced.");
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

void CommandEditForm(Player* targetPlayer) {
    if (playerCommandList[targetPlayer->getXuid()].size() == 0) {
        playerCommandList[targetPlayer->getXuid()].push_back("None");
    }
    CustomForm form = CustomForm("Command Editor");
    form.addLabel("CurCmdLbl", "Current commands:");
    form.addDropdown("Cmds", "Command List", playerCommandList[targetPlayer->getXuid()]);
    form.addInput("NewCmd", "NewCmd:");
    form.addToggle("SaveToggle", "Save Command");
    form.addToggle("DelToggle", "Delete Command");
    form.sendTo(targetPlayer, [](Player* pl, std::map<string, std::shared_ptr<Form::CustomFormElement>> mp) {
        string playerXuid = pl->getXuid();
        if (mp.empty()) {
            return;
        }
        bool saveToggle = mp["SaveToggle"]->getBool();
        bool delToggle = mp["DelToggle"]->getBool();
        string newCmd = mp["NewCmd"]->getString();
        string dropCmd = mp["Cmds"]->getString();
        if ((saveToggle && delToggle) || (!saveToggle && !delToggle)) {
            return;
        }
        if (playerCommandList[playerXuid].size() == 1 && playerCommandList[playerXuid][0] == "None") {
            playerCommandList[playerXuid].erase(playerCommandList[playerXuid].begin());
        }
        if (saveToggle) {
            if (newCmd == "") {
                return;
            }
            size_t termPos = 0;
            size_t curPos = 0;
            string term = ">>";
            string parsed;
            if (newCmd.find(term, curPos) == string::npos) {
                playerCommandList[playerXuid].push_back(newCmd);
            }
            else
            {
                while (newCmd.find(term, curPos) != string::npos) {
                    termPos = newCmd.find(term, curPos);
                    parsed = newCmd.substr(curPos, termPos - curPos);
                    curPos = termPos + term.length();
                    if (!playerCommandList.contains(playerXuid)) {
                        playerCommandList.insert(pair<string, vector<string>>(pl->getXuid(), vector<string>()));
                        playerCommandList[playerXuid].push_back(parsed);
                    }
                    else {
                        playerCommandList[playerXuid].push_back(parsed);
                    }
                }
                parsed = newCmd.substr(curPos, newCmd.length() - curPos);
                playerCommandList[playerXuid].push_back(parsed);
            }
        }
        if (delToggle && dropCmd != "None") {
                for (int i = 0; i < playerCommandList[playerXuid].size(); i++) {
                    if (playerCommandList[playerXuid][i] == dropCmd) {
                        playerCommandList[playerXuid].erase(playerCommandList[playerXuid].begin() + i);
                    }
                }
        }
        });

}

void RunCommandList(Player* targetPlayer) {
    if (playerCommandList[targetPlayer->getXuid()].size() != 0) {
        for (string cmd : playerCommandList[targetPlayer->getXuid()]) {
            targetPlayer->runcmd(cmd);
            Sleep(500);
        }
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
            logger.info("Syncing " + caller->getRealName() + "'s armor...");
            CopyPlayerArmor(caller, playerTarget);
            break;
        case CrowToolsCommands::Cmds::setArmor:
            caller = playerTarget;
            playerTarget = ori.getPlayer();
            logger.info("Syncing " + caller->getRealName() + "'s armor...");
            CopyPlayerArmor(caller, playerTarget);
            break;
        case CrowToolsCommands::Cmds::copyhotbar:
            logger.info("Syncing " + caller->getRealName() + "'s hotbar...");
            CopyHotBar(caller, playerTarget);
            break;
        case CrowToolsCommands::Cmds::sethotbar:
            caller = playerTarget;
            playerTarget = ori.getPlayer();
            logger.info("Syncing " + caller->getRealName() + "'s hotbar...");
            CopyHotBar(caller, playerTarget);
            break;
        case CrowToolsCommands::Cmds::copyinventory:
            logger.info("Syncing " + caller->getRealName() + "'s inventory...");
            CopyPlayerBag(caller, playerTarget);
            break;
        case CrowToolsCommands::Cmds::setinventory:
            caller = playerTarget;
            playerTarget = ori.getPlayer();
            logger.info("Syncing " + caller->getRealName() + "'s inventory...");
            CopyPlayerBag(caller, playerTarget);
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

    Event::PlayerInventoryChangeEvent::subscribe_ref([](const Event::PlayerInventoryChangeEvent& ev) {
        if (debugOutput) {
            logger.info("PlayerInventoryChangeEvent");
            for (int i = 0; i < ev.mPlayer->getInventory().getContainerSize(); i++) {
                logger.info(ev.mPlayer->getInventory().getSlot(i)->toDebugString());
            }
            logger.info(ev.mNewItemStack->toDebugString());
        }
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
