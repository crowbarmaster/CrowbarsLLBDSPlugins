/**
 * @file  MoveTowardsHomeRestrictionGoal.hpp
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
 * @brief MC class MoveTowardsHomeRestrictionGoal.
 *
 */
class MoveTowardsHomeRestrictionGoal {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOVETOWARDSHOMERESTRICTIONGOAL
public:
    class MoveTowardsHomeRestrictionGoal& operator=(class MoveTowardsHomeRestrictionGoal const &) = delete;
    MoveTowardsHomeRestrictionGoal(class MoveTowardsHomeRestrictionGoal const &) = delete;
    MoveTowardsHomeRestrictionGoal() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -120664673
     */
    virtual ~MoveTowardsHomeRestrictionGoal();
    /**
     * @vftbl  1
     * @symbol ?canUse@MoveTowardsHomeRestrictionGoal@@UEAA_NXZ
     * @hash   -1101552565
     */
    virtual bool canUse();
    /**
     * @vftbl  2
     * @hash   -1407555070
     */
    virtual void __unk_vfn_2();
    /**
     * @vftbl  3
     * @hash   -1406631549
     */
    virtual void __unk_vfn_3();
    /**
     * @vftbl  4
     * @hash   673480820
     */
    virtual void __unk_vfn_4();
    /**
     * @vftbl  5
     * @hash   -1362500507
     */
    virtual void __unk_vfn_5();
    /**
     * @vftbl  6
     * @hash   642453974
     */
    virtual void __unk_vfn_6();
    /**
     * @vftbl  7
     * @symbol ?appendDebugInfo@MoveTowardsHomeRestrictionGoal@@UEBAXAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
     * @hash   247917925
     */
    virtual void appendDebugInfo(std::string &) const;
    /**
     * @symbol ??0MoveTowardsHomeRestrictionGoal@@QEAA@AEAVMob@@@Z
     * @hash   1865972616
     */
    MCAPI MoveTowardsHomeRestrictionGoal(class Mob &);

};