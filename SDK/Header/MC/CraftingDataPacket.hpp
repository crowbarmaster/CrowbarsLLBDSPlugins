/**
 * @file  CraftingDataPacket.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class CraftingDataPacket.
 *
 */
class CraftingDataPacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CRAFTINGDATAPACKET
public:
    class CraftingDataPacket& operator=(class CraftingDataPacket const &) = delete;
    CraftingDataPacket(class CraftingDataPacket const &) = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -1485755906
     */
    virtual ~CraftingDataPacket();
    /**
     * @vftbl  1
     * @symbol ?getId@CraftingDataPacket@@UEBA?AW4MinecraftPacketIds@@XZ
     * @hash   1342178922
     */
    virtual enum MinecraftPacketIds getId() const;
    /**
     * @vftbl  2
     * @symbol ?getName@CraftingDataPacket@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   -419703529
     */
    virtual std::string getName() const;
    /**
     * @vftbl  3
     * @symbol ?write@CraftingDataPacket@@UEBAXAEAVBinaryStream@@@Z
     * @hash   862596016
     */
    virtual void write(class BinaryStream &) const;
    /**
     * @vftbl  6
     * @symbol ?_read@CraftingDataPacket@@EEAA?AW4StreamReadResult@@AEAVReadOnlyBinaryStream@@@Z
     * @hash   1709521136
     */
    virtual enum StreamReadResult _read(class ReadOnlyBinaryStream &);
    /**
     * @symbol ??0CraftingDataPacket@@QEAA@XZ
     * @hash   -776033744
     */
    MCAPI CraftingDataPacket();
    /**
     * @symbol ?prepareFromRecipes@CraftingDataPacket@@SA?AV?$unique_ptr@VCraftingDataPacket@@U?$default_delete@VCraftingDataPacket@@@std@@@std@@AEBVRecipes@@_N@Z
     * @hash   593956178
     */
    MCAPI static std::unique_ptr<class CraftingDataPacket> prepareFromRecipes(class Recipes const &, bool);

};