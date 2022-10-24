/**
 * @file  BeaconBlockActor.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class BeaconBlockActor.
 *
 */
class BeaconBlockActor {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BEACONBLOCKACTOR
public:
    class BeaconBlockActor& operator=(class BeaconBlockActor const &) = delete;
    BeaconBlockActor(class BeaconBlockActor const &) = delete;
    BeaconBlockActor() = delete;
#endif

public:
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_BEACONBLOCKACTOR
    /**
     * @symbol ?_getUpdatePacket@BeaconBlockActor@@MEAA?AV?$unique_ptr@VBlockActorDataPacket@@U?$default_delete@VBlockActorDataPacket@@@std@@@std@@AEAVBlockSource@@@Z
     * @hash   1430205125
     */
    MCVAPI std::unique_ptr<class BlockActorDataPacket> _getUpdatePacket(class BlockSource &);
    /**
     * @symbol ?_onUpdatePacket@BeaconBlockActor@@MEAAXAEBVCompoundTag@@AEAVBlockSource@@@Z
     * @hash   -1626590083
     */
    MCVAPI void _onUpdatePacket(class CompoundTag const &, class BlockSource &);
    /**
     * @symbol ?getContainer@BeaconBlockActor@@UEAAPEAVContainer@@XZ
     * @hash   1908175667
     */
    MCVAPI class Container * getContainer();
    /**
     * @symbol ?getContainer@BeaconBlockActor@@UEBAPEBVContainer@@XZ
     * @hash   1480453807
     */
    MCVAPI class Container const * getContainer() const;
    /**
     * @symbol ?getContainerSize@BeaconBlockActor@@UEBAHXZ
     * @hash   1735679275
     */
    MCVAPI int getContainerSize() const;
    /**
     * @symbol ?getItem@BeaconBlockActor@@UEBAAEBVItemStack@@H@Z
     * @hash   -712554768
     */
    MCVAPI class ItemStack const & getItem(int) const;
    /**
     * @symbol ?getMaxStackSize@BeaconBlockActor@@UEBAHXZ
     * @hash   -1294285590
     */
    MCVAPI int getMaxStackSize() const;
    /**
     * @symbol ?getName@BeaconBlockActor@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   -1620389777
     */
    MCVAPI std::string getName() const;
    /**
     * @symbol ?hasAlphaLayer@BeaconBlockActor@@UEBA_NXZ
     * @hash   287582105
     */
    MCVAPI bool hasAlphaLayer() const;
    /**
     * @symbol ?load@BeaconBlockActor@@UEAAXAEAVLevel@@AEBVCompoundTag@@AEAVDataLoadHelper@@@Z
     * @hash   -626086253
     */
    MCVAPI void load(class Level &, class CompoundTag const &, class DataLoadHelper &);
    /**
     * @symbol ?removeItem@BeaconBlockActor@@UEAAXHH@Z
     * @hash   -868049166
     */
    MCVAPI void removeItem(int, int);
    /**
     * @symbol ?save@BeaconBlockActor@@UEBA_NAEAVCompoundTag@@@Z
     * @hash   1370857970
     */
    MCVAPI bool save(class CompoundTag &) const;
    /**
     * @symbol ?serverInitItemStackIds@BeaconBlockActor@@UEAAXHHV?$function@$$A6AXHAEBVItemStack@@@Z@std@@@Z
     * @hash   2056562245
     */
    MCVAPI void serverInitItemStackIds(int, int, class std::function<void (int, class ItemStack const &)>);
    /**
     * @symbol ?setItem@BeaconBlockActor@@UEAAXHAEBVItemStack@@@Z
     * @hash   1537465685
     */
    MCVAPI void setItem(int, class ItemStack const &);
    /**
     * @symbol ?startOpen@BeaconBlockActor@@UEAAXAEAVPlayer@@@Z
     * @hash   -546119924
     */
    MCVAPI void startOpen(class Player &);
    /**
     * @symbol ?stopOpen@BeaconBlockActor@@UEAAXAEAVPlayer@@@Z
     * @hash   477341484
     */
    MCVAPI void stopOpen(class Player &);
    /**
     * @symbol ?tick@BeaconBlockActor@@UEAAXAEAVBlockSource@@@Z
     * @hash   1082252892
     */
    MCVAPI void tick(class BlockSource &);
#endif
    /**
     * @symbol ??0BeaconBlockActor@@QEAA@AEBVBlockPos@@@Z
     * @hash   -1209958273
     */
    MCAPI BeaconBlockActor(class BlockPos const &);
    /**
     * @symbol ?checkShapeAndAchievement@BeaconBlockActor@@QEAAXAEAVBlockSource@@@Z
     * @hash   -76678476
     */
    MCAPI void checkShapeAndAchievement(class BlockSource &);
    /**
     * @symbol ?getBeaconData@BeaconBlockActor@@QEAA?AVCompoundTag@@XZ
     * @hash   -887870652
     */
    MCAPI class CompoundTag getBeaconData();
    /**
     * @symbol ?isEffectAvailable@BeaconBlockActor@@QEBA_NH@Z
     * @hash   394858677
     */
    MCAPI bool isEffectAvailable(int) const;
    /**
     * @symbol ?isSecondaryAvailable@BeaconBlockActor@@QEBA_NXZ
     * @hash   1082167604
     */
    MCAPI bool isSecondaryAvailable() const;
    /**
     * @symbol ?setPrimaryEffect@BeaconBlockActor@@QEAA_NH@Z
     * @hash   2139238483
     */
    MCAPI bool setPrimaryEffect(int);
    /**
     * @symbol ?setSecondaryEffect@BeaconBlockActor@@QEAA_NH@Z
     * @hash   127556623
     */
    MCAPI bool setSecondaryEffect(int);
    /**
     * @symbol ?isPaymentItem@BeaconBlockActor@@SA_NAEBVItemDescriptor@@@Z
     * @hash   -2029682061
     */
    MCAPI static bool isPaymentItem(class ItemDescriptor const &);

//private:
    /**
     * @symbol ?_applyEffects@BeaconBlockActor@@AEAAXAEAVBlockSource@@@Z
     * @hash   466604049
     */
    MCAPI void _applyEffects(class BlockSource &);
    /**
     * @symbol ?_getEffectTier@BeaconBlockActor@@AEBAHH@Z
     * @hash   1448938095
     */
    MCAPI int _getEffectTier(int) const;
    /**
     * @symbol ?_isEffectValid@BeaconBlockActor@@AEBA_NH@Z
     * @hash   -288270494
     */
    MCAPI bool _isEffectValid(int) const;
    /**
     * @symbol ?_isSecondaryEffectValid@BeaconBlockActor@@AEBA_NH@Z
     * @hash   -936067084
     */
    MCAPI bool _isSecondaryEffectValid(int) const;
    /**
     * @symbol ?_loadClientSideState@BeaconBlockActor@@AEAAXAEAVLevel@@AEBVCompoundTag@@AEAVDataLoadHelper@@@Z
     * @hash   1387168002
     */
    MCAPI void _loadClientSideState(class Level &, class CompoundTag const &, class DataLoadHelper &);
    /**
     * @symbol ?_saveClientSideState@BeaconBlockActor@@AEBA_NAEAVCompoundTag@@@Z
     * @hash   1334146031
     */
    MCAPI bool _saveClientSideState(class CompoundTag &) const;

private:

};