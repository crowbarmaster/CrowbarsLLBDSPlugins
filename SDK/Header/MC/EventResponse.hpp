/**
 * @file  EventResponse.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "JsonUtil.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class EventResponse.
 *
 */
class EventResponse {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_EVENTRESPONSE
public:
    class EventResponse& operator=(class EventResponse const &) = delete;
    EventResponse(class EventResponse const &) = delete;
    EventResponse() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   80919625
     */
    virtual ~EventResponse();
    /**
     * @vftbl  1
     * @symbol ?getName@EventResponse@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   761208430
     */
    virtual std::string const & getName() const;
    /**
     * @vftbl  2
     * @hash   986322882
     */
    virtual void __unk_vfn_2() = 0;
    /**
     * @vftbl  3
     * @symbol ?buildSchema@EventResponse@@UEBAXAEAV?$shared_ptr@V?$JsonSchemaObjectNode@VEmptyClass@JsonUtil@@UEventResponseCollection@@@JsonUtil@@@std@@AEBV?$Factory@VEventResponse@@$$V@@@Z
     * @hash   320833068
     */
    virtual void buildSchema(class std::shared_ptr<class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, struct EventResponseCollection>> &, class Factory<class EventResponse> const &) const;

};