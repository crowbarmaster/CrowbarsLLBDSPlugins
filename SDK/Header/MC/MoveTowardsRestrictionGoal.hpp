/**
 * @file  MoveTowardsRestrictionGoal.hpp
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
 * @brief MC class MoveTowardsRestrictionGoal.
 *
 */
class MoveTowardsRestrictionGoal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOVETOWARDSRESTRICTIONGOAL
public:
    class MoveTowardsRestrictionGoal& operator=(class MoveTowardsRestrictionGoal const &) = delete;
    MoveTowardsRestrictionGoal(class MoveTowardsRestrictionGoal const &) = delete;
    MoveTowardsRestrictionGoal() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   230989438
     */
    virtual ~MoveTowardsRestrictionGoal();
    /**
     * @vftbl  1
     * @hash   -2111630872
     */
    virtual void __unk_vfn_1() = 0;
    /**
     * @vftbl  2
     * @symbol ?canContinueToUse@MoveTowardsRestrictionGoal@@UEAA_NXZ
     * @hash   834308746
     */
    virtual bool canContinueToUse();
    /**
     * @vftbl  3
     * @hash   -1364347549
     */
    virtual void __unk_vfn_3();
    /**
     * @vftbl  4
     * @symbol ?start@MoveTowardsRestrictionGoal@@UEAAXXZ
     * @hash   393306853
     */
    virtual void start();
    /**
     * @symbol ??0MoveTowardsRestrictionGoal@@QEAA@AEAVMob@@@Z
     * @hash   -1314713927
     */
    MCAPI MoveTowardsRestrictionGoal(class Mob &);

//protected:
    /**
     * @symbol ?_getMob@MoveTowardsRestrictionGoal@@IEBAAEBVMob@@XZ
     * @hash   1093933206
     */
    MCAPI class Mob const & _getMob() const;
    /**
     * @symbol ?_randomizeWantedPositionTowardsRestriction@MoveTowardsRestrictionGoal@@IEAA_NAEBVVec3@@@Z
     * @hash   2027763895
     */
    MCAPI bool _randomizeWantedPositionTowardsRestriction(class Vec3 const &);

protected:

};