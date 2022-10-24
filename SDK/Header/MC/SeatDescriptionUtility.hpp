/**
 * @file  SeatDescriptionUtility.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

/**
 * @brief MC class SeatDescriptionUtility.
 *
 */
class SeatDescriptionUtility {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SEATDESCRIPTIONUTILITY
public:
    class SeatDescriptionUtility& operator=(class SeatDescriptionUtility const &) = delete;
    SeatDescriptionUtility(class SeatDescriptionUtility const &) = delete;
    SeatDescriptionUtility() = delete;
#endif

public:
    /**
     * @symbol ?getSeatDescriptionOfPassenger@SeatDescriptionUtility@@SAAEBUSeatDescription@@AEBV?$vector@USeatDescription@@V?$allocator@USeatDescription@@@std@@@std@@HH@Z
     * @hash   1158611573
     */
    MCAPI static struct SeatDescription const & getSeatDescriptionOfPassenger(std::vector<struct SeatDescription> const &, int, int);
    /**
     * @symbol ?setValuesToSynchedActorData@SeatDescriptionUtility@@SAXAEAVSynchedActorData@@AEBVVec3@@AEBUSeatDescription@@M@Z
     * @hash   -728593641
     */
    MCAPI static void setValuesToSynchedActorData(class SynchedActorData &, class Vec3 const &, struct SeatDescription const &, float);

};