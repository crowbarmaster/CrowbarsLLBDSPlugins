/**
 * @file  PlayerRespawnTelemetryData.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Social.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class PlayerRespawnTelemetryData.
 *
 */
class PlayerRespawnTelemetryData {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PLAYERRESPAWNTELEMETRYDATA
public:
    class PlayerRespawnTelemetryData& operator=(class PlayerRespawnTelemetryData const &) = delete;
    PlayerRespawnTelemetryData(class PlayerRespawnTelemetryData const &) = delete;
#endif

public:
    /**
     * @symbol ??0PlayerRespawnTelemetryData@@QEAA@XZ
     * @hash   -151828632
     */
    MCAPI PlayerRespawnTelemetryData();
    /**
     * @symbol ?WriteEventData@PlayerRespawnTelemetryData@@QEBAXAEAVEvent@Events@Social@@@Z
     * @hash   -305383102
     */
    MCAPI void WriteEventData(class Social::Events::Event &) const;
    /**
     * @symbol ?setChangedDimension@PlayerRespawnTelemetryData@@QEAAX_N@Z
     * @hash   714020732
     */
    MCAPI void setChangedDimension(bool);
    /**
     * @symbol ?setJumpDistance@PlayerRespawnTelemetryData@@QEAAXN@Z
     * @hash   1155981408
     */
    MCAPI void setJumpDistance(double);
    /**
     * @symbol ?setLongJumpCount@PlayerRespawnTelemetryData@@QEAAXI@Z
     * @hash   1719986192
     */
    MCAPI void setLongJumpCount(unsigned int);
    /**
     * @symbol ?setPositionSourceType@PlayerRespawnTelemetryData@@QEAAXI@Z
     * @hash   1543857634
     */
    MCAPI void setPositionSourceType(unsigned int);
    /**
     * @symbol ?setSearchTime@PlayerRespawnTelemetryData@@QEAAXN@Z
     * @hash   -1822526848
     */
    MCAPI void setSearchTime(double);
    /**
     * @symbol ?setShortJumpCount@PlayerRespawnTelemetryData@@QEAAXI@Z
     * @hash   -1231433406
     */
    MCAPI void setShortJumpCount(unsigned int);

//private:

private:
    /**
     * @symbol ?mEventName@PlayerRespawnTelemetryData@@0V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B
     * @hash   681539567
     */
    MCAPI static std::string const mEventName;

};