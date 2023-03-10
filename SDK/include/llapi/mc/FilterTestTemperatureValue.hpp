/**
 * @file  FilterTestTemperatureValue.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"
#include "FilterTest.hpp"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class FilterTestTemperatureValue.
 *
 */
class FilterTestTemperatureValue : public FilterTest {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FILTERTESTTEMPERATUREVALUE
public:
    class FilterTestTemperatureValue& operator=(class FilterTestTemperatureValue const &) = delete;
    FilterTestTemperatureValue(class FilterTestTemperatureValue const &) = delete;
    FilterTestTemperatureValue() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @symbol  __unk_destructor_0
     */
    virtual ~FilterTestTemperatureValue();
    /**
     * @vftbl  2
     * @symbol  ?evaluate\@FilterTestTemperatureValue\@\@UEBA_NAEBUFilterContext\@\@\@Z
     */
    virtual bool evaluate(struct FilterContext const &) const;
    /**
     * @vftbl  4
     * @symbol  ?getName\@FilterTestTemperatureValue\@\@UEBA?AV?$basic_string_span\@$$CBD$0?0\@gsl\@\@XZ
     */
    virtual class gsl::basic_string_span<char const, -1> getName() const;

};