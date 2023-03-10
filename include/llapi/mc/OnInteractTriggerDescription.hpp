/**
 * @file  OnInteractTriggerDescription.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class OnInteractTriggerDescription.
 *
 */
class OnInteractTriggerDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ONINTERACTTRIGGERDESCRIPTION
public:
    class OnInteractTriggerDescription& operator=(class OnInteractTriggerDescription const &) = delete;
    OnInteractTriggerDescription(class OnInteractTriggerDescription const &) = delete;
    OnInteractTriggerDescription() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @symbol  __unk_destructor_0
     */
    virtual ~OnInteractTriggerDescription();
    /**
     * @vftbl  1
     * @symbol  ?getName\@OnInteractTriggerDescription\@\@UEBAAEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@XZ
     */
    virtual std::string const & getName() const;
    /**
     * @vftbl  4
     * @symbol  ?isNetworkComponent\@OnInteractTriggerDescription\@\@UEBA_NXZ
     */
    virtual bool isNetworkComponent() const;
    /**
     * @vftbl  5
     * @symbol  ?buildNetworkTag\@OnInteractTriggerDescription\@\@UEBA?AV?$unique_ptr\@VCompoundTag\@\@U?$default_delete\@VCompoundTag\@\@\@std\@\@\@std\@\@XZ
     */
    virtual std::unique_ptr<class CompoundTag> buildNetworkTag() const;
    /**
     * @vftbl  6
     * @symbol  ?initializeFromNetwork\@OnInteractTriggerDescription\@\@UEAAXAEBVCompoundTag\@\@\@Z
     */
    virtual void initializeFromNetwork(class CompoundTag const &);
    /**
     * @symbol  ?NameID\@OnInteractTriggerDescription\@\@2V?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@B
     */
    MCAPI static std::string const NameID;

};