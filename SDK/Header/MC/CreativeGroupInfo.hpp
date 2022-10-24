/**
 * @file  CreativeGroupInfo.hpp
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
 * @brief MC class CreativeGroupInfo.
 *
 */
class CreativeGroupInfo {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CREATIVEGROUPINFO
public:
    class CreativeGroupInfo& operator=(class CreativeGroupInfo const &) = delete;
    CreativeGroupInfo() = delete;
#endif

public:
    /**
     * @symbol ??0CreativeGroupInfo@@QEAA@PEAVCreativeItemRegistry@@W4CreativeItemCategory@@AEBVHashedString@@IAEBVItemInstance@@@Z
     * @hash   355218044
     */
    MCAPI CreativeGroupInfo(class CreativeItemRegistry *, enum CreativeItemCategory, class HashedString const &, unsigned int, class ItemInstance const &);
    /**
     * @symbol ??0CreativeGroupInfo@@QEAA@AEBV0@@Z
     * @hash   -2002162927
     */
    MCAPI CreativeGroupInfo(class CreativeGroupInfo const &);
    /**
     * @symbol ?addCreativeItem@CreativeGroupInfo@@QEAAXPEAVCreativeItemEntry@@@Z
     * @hash   -1367669125
     */
    MCAPI void addCreativeItem(class CreativeItemEntry *);
    /**
     * @symbol ?getIcon@CreativeGroupInfo@@QEBA?BVItemInstance@@XZ
     * @hash   -242744036
     */
    MCAPI class ItemInstance const getIcon() const;
    /**
     * @symbol ?getIndex@CreativeGroupInfo@@QEBAIXZ
     * @hash   -687529400
     */
    MCAPI unsigned int getIndex() const;
    /**
     * @symbol ?getName@CreativeGroupInfo@@QEBA?BV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   1899328812
     */
    MCAPI std::string const getName() const;

};