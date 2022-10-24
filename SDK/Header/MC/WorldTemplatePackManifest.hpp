/**
 * @file  WorldTemplatePackManifest.hpp
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
 * @brief MC class WorldTemplatePackManifest.
 *
 */
class WorldTemplatePackManifest {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_WORLDTEMPLATEPACKMANIFEST
public:
    class WorldTemplatePackManifest& operator=(class WorldTemplatePackManifest const &) = delete;
    WorldTemplatePackManifest(class WorldTemplatePackManifest const &) = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -1026737278
     */
    virtual ~WorldTemplatePackManifest();
    /**
     * @vftbl  1
     * @symbol ?clone@WorldTemplatePackManifest@@UEBA?AV?$unique_ptr@VPackManifest@@U?$default_delete@VPackManifest@@@std@@@std@@XZ
     * @hash   -1655975102
     */
    virtual std::unique_ptr<class PackManifest> clone() const;
    /**
     * @symbol ??0WorldTemplatePackManifest@@QEAA@XZ
     * @hash   1939079968
     */
    MCAPI WorldTemplatePackManifest();
    /**
     * @symbol ??0WorldTemplatePackManifest@@QEAA@$$QEAVPackManifest@@@Z
     * @hash   1149775261
     */
    MCAPI WorldTemplatePackManifest(class PackManifest &&);
    /**
     * @symbol ?getGameType@WorldTemplatePackManifest@@QEBA?AW4GameType@@XZ
     * @hash   856698422
     */
    MCAPI enum GameType getGameType() const;
    /**
     * @symbol ?setGameType@WorldTemplatePackManifest@@QEAAXW4GameType@@@Z
     * @hash   -913548632
     */
    MCAPI void setGameType(enum GameType);

};