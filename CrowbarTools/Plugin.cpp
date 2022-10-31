#include "pch.h"
#include <llapi/Global.h>
#include <llapi/LoggerAPI.h>
#include <llapi/DynamicCommandAPI.h>
#include <llapi/LLAPI.h>
#include <llapi/MC/Actor.hpp>
#include <llapi/MC/Player.hpp>
#include <llapi/MC/ArmorItem.hpp>
#include <llapi/MC/Level.hpp>
#include <llapi/MC/Inventory.hpp>
#include <llapi/MC/Mob.hpp>
#include <llapi/MC/ItemStack.hpp>
#include <llapi/MC/SlotData.hpp>
#include <llapi/MC/ListTag.hpp>
#include <llapi/EventAPI.h>
#include <llapi/MC/Block.hpp>
#include <llapi/RegCommandAPI.h>
#include <vector>
#include <string>
#include "SimpleIni.h"

using namespace RegisterCommandHelper;
using namespace std;

Logger logger("CrowbarTools");
bool keepAligned = false;
bool TeleLearn = false;
BlockInstance BlockX;
BlockInstance BlockY;
BlockInstance BlockZ;
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
    for (int i = 0; i < 4; i++) {
        try {
            ItemStack item = destPlayer->getArmor((ArmorSlot)i);
            if(debugOutput) logger.info("Armor: " + item.toDebugString());
            srcPlayer->setArmor((ArmorSlot)i, item);
        }
        catch (exception e) {
            logger.error("Could not set player equip.");
            return;
        }
    }
    srcPlayer->setOffhandSlot(destPlayer->getOffhandSlot());
    srcPlayer->updateEquipment();
    srcPlayer->sendInventory(false);
    logger.info("Armor has been synced.");
}

void SendPlayerToServer(Player* targetPlayer, string ipAddress, int port) {
    targetPlayer->transferServer(ipAddress, port);
}

class CrowToolsCommands : public Command {
    enum class Cmds :int {
        sethotbar,
        setinventory,
        copyhotbar,
        copyinventory,
        autoinventory,
        tele2server,
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
        default:
            break;
        }
    }
public:
    static void setup(CommandRegistry* registry) {
        registry->registerCommand("crowtools", "Collection of tools by Crowbarmast3r.", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
        registry->addEnum<Cmds>("Inventory",
        {
            {"copyhotbar", Cmds::copyhotbar},
            {"copyinventory", Cmds::copyinventory},
            {"sethotbar", Cmds::sethotbar},
            {"setinventory", Cmds::setinventory},
            {"autoinventory", Cmds::autoinventory},
        });
        registry->addEnum<Cmds>("Teleport",
            {
                    {"tele2server", Cmds::tele2server},
            });
        registry->registerOverload<CrowToolsCommands>("crowtools",
            makeMandatory<CommandParameterDataType::ENUM>(&CrowToolsCommands::cmdOp, "function", "Inventory"),
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
