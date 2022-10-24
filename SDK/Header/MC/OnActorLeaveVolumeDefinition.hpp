/**
 * @file  OnActorLeaveVolumeDefinition.hpp
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
 * @brief MC structure OnActorLeaveVolumeDefinition.
 *
 */
struct OnActorLeaveVolumeDefinition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ONACTORLEAVEVOLUMEDEFINITION
public:
    struct OnActorLeaveVolumeDefinition& operator=(struct OnActorLeaveVolumeDefinition const &) = delete;
    OnActorLeaveVolumeDefinition(struct OnActorLeaveVolumeDefinition const &) = delete;
    OnActorLeaveVolumeDefinition() = delete;
#endif

public:
    /**
     * @symbol ?initialize@OnActorLeaveVolumeDefinition@@QEBAXAEAVEntityContext@@AEAVOnActorLeaveVolumeComponent@@@Z
     * @hash   -15738289
     */
    MCAPI void initialize(class EntityContext &, class OnActorLeaveVolumeComponent &) const;
    /**
     * @symbol ?NAME@OnActorLeaveVolumeDefinition@@2V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B
     * @hash   1447671869
     */
    MCAPI static std::string const NAME;
    /**
     * @symbol ?bindType@OnActorLeaveVolumeDefinition@@SAXXZ
     * @hash   2105528275
     */
    MCAPI static void bindType();

};