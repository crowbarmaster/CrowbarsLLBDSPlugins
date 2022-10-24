/**
 * @file  Timer.hpp
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
 * @brief MC class Timer.
 *
 */
class Timer {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TIMER
public:
    class Timer& operator=(class Timer const &) = delete;
    Timer(class Timer const &) = delete;
    Timer() = delete;
#endif

public:
    /**
     * @symbol ??0Timer@@QEAA@MV?$function@$$A6A_JXZ@std@@@Z
     * @hash   -27938869
     */
    MCAPI Timer(float, class std::function<__int64 (void)>);
    /**
     * @symbol ?advanceTime@Timer@@QEAAXM@Z
     * @hash   869162774
     */
    MCAPI void advanceTime(float);
    /**
     * @symbol ?getTicks@Timer@@QEBA_KXZ
     * @hash   784106945
     */
    MCAPI unsigned __int64 getTicks() const;
    /**
     * @symbol ?getTimeScale@Timer@@QEBAMXZ
     * @hash   1050532050
     */
    MCAPI float getTimeScale() const;
    /**
     * @symbol ?resetTimePassed@Timer@@QEAAXXZ
     * @hash   617790365
     */
    MCAPI void resetTimePassed();
    /**
     * @symbol ?setTimeScale@Timer@@QEAAXM@Z
     * @hash   -659481936
     */
    MCAPI void setTimeScale(float);
    /**
     * @symbol ?stepTick@Timer@@QEAAXH@Z
     * @hash   1754418598
     */
    MCAPI void stepTick(int);
    /**
     * @symbol ?stepping@Timer@@QEBA_NXZ
     * @hash   1334741398
     */
    MCAPI bool stepping() const;

};