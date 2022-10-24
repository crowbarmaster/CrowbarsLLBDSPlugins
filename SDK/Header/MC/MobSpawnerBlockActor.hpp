/**
 * @file  MobSpawnerBlockActor.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BlockActor.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class MobSpawnerBlockActor.
 *
 */
class MobSpawnerBlockActor : public BlockActor {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOBSPAWNERBLOCKACTOR
public:
    class MobSpawnerBlockActor& operator=(class MobSpawnerBlockActor const &) = delete;
    MobSpawnerBlockActor(class MobSpawnerBlockActor const &) = delete;
    MobSpawnerBlockActor() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -211640806
     */
    virtual ~MobSpawnerBlockActor();
    /**
     * @vftbl  1
     * @symbol ?load@MobSpawnerBlockActor@@UEAAXAEAVLevel@@AEBVCompoundTag@@AEAVDataLoadHelper@@@Z
     * @hash   -597017577
     */
    virtual void load(class Level &, class CompoundTag const &, class DataLoadHelper &);
    /**
     * @vftbl  2
     * @symbol ?save@MobSpawnerBlockActor@@UEBA_NAEAVCompoundTag@@@Z
     * @hash   -1236269914
     */
    virtual bool save(class CompoundTag &) const;
    /**
     * @vftbl  7
     * @symbol ?tick@MobSpawnerBlockActor@@UEAAXAEAVBlockSource@@@Z
     * @hash   1055842640
     */
    virtual void tick(class BlockSource &);
    /**
     * @vftbl  12
     * @hash   -383143003
     */
    virtual void __unk_vfn_12();
    /**
     * @vftbl  13
     * @symbol ?onRemoved@MobSpawnerBlockActor@@UEAAXAEAVBlockSource@@@Z
     * @hash   -1292456244
     */
    virtual void onRemoved(class BlockSource &);
    /**
     * @vftbl  16
     * @hash   -379448919
     */
    virtual void __unk_vfn_16();
    /**
     * @vftbl  28
     * @hash   -348972726
     */
    virtual void __unk_vfn_28();
    /**
     * @vftbl  29
     * @hash   -312330757
     */
    virtual void __unk_vfn_29();
    /**
     * @vftbl  30
     * @hash   -292013295
     */
    virtual void __unk_vfn_30();
    /**
     * @vftbl  32
     * @hash   -325884701
     */
    virtual void __unk_vfn_32();
    /**
     * @vftbl  33
     * @hash   -324961180
     */
    virtual void __unk_vfn_33();
    /**
     * @vftbl  34
     * @hash   -324037659
     */
    virtual void __unk_vfn_34();
    /**
     * @vftbl  35
     * @symbol ?_getUpdatePacket@MobSpawnerBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
     * @hash   -685842071
     */
    virtual std::unique_ptr<class BlockActorDataPacket> _getUpdatePacket(class BlockSource &);
    /**
     * @vftbl  36
     * @symbol ?_onUpdatePacket@MobSpawnerBlockActor@@MEAAXAEBVCompoundTag@@AEAVBlockSource@@@Z
     * @hash   -41385607
     */
    virtual void _onUpdatePacket(class CompoundTag const &, class BlockSource &);
    /**
     * @symbol ??0MobSpawnerBlockActor@@QEAA@AEBVBlockPos@@@Z
     * @hash   -103644909
     */
    MCAPI MobSpawnerBlockActor(class BlockPos const &);
    /**
     * @symbol ?getSpawner@MobSpawnerBlockActor@@QEAAAEAVBaseMobSpawner@@XZ
     * @hash   -547852674
     */
    MCAPI class BaseMobSpawner & getSpawner();

};