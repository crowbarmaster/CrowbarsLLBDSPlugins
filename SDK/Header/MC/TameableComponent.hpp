/**
 * @file  TameableComponent.hpp
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
 * @brief MC class TameableComponent.
 *
 */
class TameableComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TAMEABLECOMPONENT
public:
    class TameableComponent& operator=(class TameableComponent const &) = delete;
    TameableComponent(class TameableComponent const &) = delete;
#endif

public:
    /**
     * @symbol ??0TameableComponent@@QEAA@XZ
     * @hash   -1824448262
     */
    MCAPI TameableComponent();
    /**
     * @symbol ?getInteraction@TameableComponent@@QEAA_NAEAVActor@@AEAVPlayer@@AEAVActorInteraction@@@Z
     * @hash   -1771590545
     */
    MCAPI bool getInteraction(class Actor &, class Player &, class ActorInteraction &);
    /**
     * @symbol ?tame@TameableComponent@@QEAAXAEAVActor@@AEAVPlayer@@@Z
     * @hash   1582714359
     */
    MCAPI void tame(class Actor &, class Player &);

//private:
    /**
     * @symbol ?_attemptToTame@TameableComponent@@AEAA_NAEAVActor@@AEAVPlayer@@@Z
     * @hash   -243711110
     */
    MCAPI bool _attemptToTame(class Actor &, class Player &);
    /**
     * @symbol ?_canTame@TameableComponent@@AEAA_NAEAVActor@@AEAVPlayer@@@Z
     * @hash   2041641362
     */
    MCAPI bool _canTame(class Actor &, class Player &);

private:

};