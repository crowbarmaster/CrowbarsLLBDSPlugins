/**
 * @file  OpenDoorAnnotationComponent.hpp
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
 * @brief MC class OpenDoorAnnotationComponent.
 *
 */
class OpenDoorAnnotationComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_OPENDOORANNOTATIONCOMPONENT
public:
    class OpenDoorAnnotationComponent& operator=(class OpenDoorAnnotationComponent const &) = delete;
    OpenDoorAnnotationComponent(class OpenDoorAnnotationComponent const &) = delete;
#endif

public:
    /**
     * @symbol ??0OpenDoorAnnotationComponent@@QEAA@XZ
     * @hash   -1030360846
     */
    MCAPI OpenDoorAnnotationComponent();
    /**
     * @symbol ??0OpenDoorAnnotationComponent@@QEAA@$$QEAV0@@Z
     * @hash   1408598965
     */
    MCAPI OpenDoorAnnotationComponent(class OpenDoorAnnotationComponent &&);
    /**
     * @symbol ?checkPath@OpenDoorAnnotationComponent@@QEAAXAEAVMob@@@Z
     * @hash   -359050006
     */
    MCAPI void checkPath(class Mob &);
    /**
     * @symbol ?initFromDefinition@OpenDoorAnnotationComponent@@QEAAXAEAVActor@@@Z
     * @hash   1117063554
     */
    MCAPI void initFromDefinition(class Actor &);
    /**
     * @symbol ?onComponentRemoved@OpenDoorAnnotationComponent@@QEAAXAEAVEntityContext@@@Z
     * @hash   -646342278
     */
    MCAPI void onComponentRemoved(class EntityContext &);

//private:
    /**
     * @symbol ?_cleanUp@OpenDoorAnnotationComponent@@AEAAXAEAVMob@@@Z
     * @hash   1934182593
     */
    MCAPI void _cleanUp(class Mob &);

private:

};