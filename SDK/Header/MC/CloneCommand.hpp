/**
 * @file  CloneCommand.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Command.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class CloneCommand.
 *
 */
class CloneCommand : public Command {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CLONECOMMAND
public:
    class CloneCommand& operator=(class CloneCommand const &) = delete;
    CloneCommand(class CloneCommand const &) = delete;
    CloneCommand() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -1066992008
     */
    virtual ~CloneCommand();
    /**
     * @vftbl  1
     * @symbol ?execute@CloneCommand@@UEBAXAEBVCommandOrigin@@AEAVCommandOutput@@@Z
     * @hash   727398981
     */
    virtual void execute(class CommandOrigin const &, class CommandOutput &) const;
    /**
     * @symbol ?setup@CloneCommand@@SAXAEAVCommandRegistry@@@Z
     * @hash   -590066740
     */
    MCAPI static void setup(class CommandRegistry &);

};