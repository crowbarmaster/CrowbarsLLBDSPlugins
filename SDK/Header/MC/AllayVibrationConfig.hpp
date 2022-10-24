/**
 * @file  AllayVibrationConfig.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

/**
 * @brief MC class AllayVibrationConfig.
 *
 */
class AllayVibrationConfig {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ALLAYVIBRATIONCONFIG
public:
    class AllayVibrationConfig& operator=(class AllayVibrationConfig const &) = delete;
    AllayVibrationConfig(class AllayVibrationConfig const &) = delete;
    AllayVibrationConfig() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   826374245
     */
    virtual ~AllayVibrationConfig();
    /**
     * @vftbl  1
     * @symbol ?onSignalReceive@AllayVibrationConfig@@UEAAXAEAVBlockSource@@VBlockPos@@AEBVGameEvent@@PEAVActor@@M3@Z
     * @hash   -685808797
     */
    virtual void onSignalReceive(class BlockSource &, class BlockPos, class GameEvent const &, class Actor *, float, class Actor *);
    /**
     * @vftbl  2
     * @symbol ?isValidVibration@AllayVibrationConfig@@UEAA_NAEBVGameEvent@@@Z
     * @hash   -1277615933
     */
    virtual bool isValidVibration(class GameEvent const &);
    /**
     * @vftbl  3
     * @symbol ?shouldListen@AllayVibrationConfig@@UEAA_NAEAVBlockSource@@AEBVGameEvent@@AEBUGameEventContext@@@Z
     * @hash   -1932384702
     */
    virtual bool shouldListen(class BlockSource &, class GameEvent const &, struct GameEventContext const &);
    /**
     * @symbol ??0AllayVibrationConfig@@QEAA@AEAVActor@@G@Z
     * @hash   -448973446
     */
    MCAPI AllayVibrationConfig(class Actor &, unsigned short);

};