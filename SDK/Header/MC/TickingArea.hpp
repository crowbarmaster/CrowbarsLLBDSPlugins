/**
 * @file  TickingArea.hpp
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
 * @brief MC class TickingArea.
 *
 */
class TickingArea {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TICKINGAREA
public:
    class TickingArea& operator=(class TickingArea const &) = delete;
    TickingArea(class TickingArea const &) = delete;
    TickingArea() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -2058578016
     */
    virtual ~TickingArea();
    /**
     * @vftbl  1
     * @symbol ?getId@TickingArea@@UEBAAEBVUUID@mce@@XZ
     * @hash   -980802206
     */
    virtual class mce::UUID const & getId() const;
    /**
     * @vftbl  2
     * @symbol ?getName@TickingArea@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   1520898487
     */
    virtual std::string const & getName() const;
    /**
     * @vftbl  3
     * @symbol ?getEntityId@TickingArea@@UEBAAEBUActorUniqueID@@XZ
     * @hash   505833001
     */
    virtual struct ActorUniqueID const & getEntityId() const;
    /**
     * @vftbl  4
     * @symbol ?isEntityOwned@TickingArea@@UEBA_NXZ
     * @hash   -852109122
     */
    virtual bool isEntityOwned() const;
    /**
     * @vftbl  5
     * @hash   -64722971
     */
    virtual void __unk_vfn_5();
    /**
     * @vftbl  6
     * @hash   -63799450
     */
    virtual void __unk_vfn_6();
    /**
     * @vftbl  7
     * @symbol ?getBounds@TickingArea@@UEBAAEBUBounds@@XZ
     * @hash   -679849922
     */
    virtual struct Bounds const & getBounds() const;
    /**
     * @vftbl  8
     * @symbol ?isAlwaysActive@TickingArea@@UEBA_NXZ
     * @hash   1053852949
     */
    virtual bool isAlwaysActive() const;
    /**
     * @vftbl  9
     * @symbol ?getMaxDistToPlayers@TickingArea@@UEBAMXZ
     * @hash   684660975
     */
    virtual float getMaxDistToPlayers() const;
    /**
     * @vftbl  10
     * @hash   1038440163
     */
    virtual void __unk_vfn_10();
    /**
     * @vftbl  11
     * @hash   1039363684
     */
    virtual void __unk_vfn_11();
    /**
     * @vftbl  12
     * @symbol ?getDescription@TickingArea@@UEBA?AUTickingAreaDescription@@XZ
     * @hash   -832490522
     */
    virtual struct TickingAreaDescription getDescription() const;
    /**
     * @vftbl  13
     * @symbol ?getLoadMode@TickingArea@@UEBA?AW4TickingAreaLoadMode@@XZ
     * @hash   -516329096
     */
    virtual enum TickingAreaLoadMode getLoadMode() const;
    /**
     * @vftbl  14
     * @symbol ?setLoadMode@TickingArea@@UEAAXW4TickingAreaLoadMode@@AEAVLevelStorage@@@Z
     * @hash   -565111682
     */
    virtual void setLoadMode(enum TickingAreaLoadMode, class LevelStorage &);
    /**
     * @vftbl  15
     * @symbol ?isPreloadDone@TickingArea@@UEBA_NXZ
     * @hash   479681047
     */
    virtual bool isPreloadDone() const;
    /**
     * @vftbl  16
     * @symbol ?tick@TickingArea@@UEAAXAEBUTick@@_N@Z
     * @hash   -1214986595
     */
    virtual void tick(struct Tick const &, bool);
    /**
     * @vftbl  17
     * @symbol ?tickSeasons@TickingArea@@UEAAXAEAVRandom@@@Z
     * @hash   -668341655
     */
    virtual void tickSeasons(class Random &);
    /**
     * @vftbl  18
     * @symbol ?updatePosition@TickingArea@@UEAAXAEBVVec3@@@Z
     * @hash   1376388843
     */
    virtual void updatePosition(class Vec3 const &);
    /**
     * @vftbl  19
     * @symbol ?updateAndCenter@TickingArea@@UEAAXAEAVLevelStorage@@UTick@@@Z
     * @hash   869024062
     */
    virtual void updateAndCenter(class LevelStorage &, struct Tick);
    /**
     * @vftbl  20
     * @symbol ?findOwner@TickingArea@@UEAAPEAVActor@@AEAE@Z
     * @hash   537490371
     */
    virtual class Actor * findOwner(unsigned char &);
    /**
     * @vftbl  21
     * @symbol ?entityHasBeenFound@TickingArea@@UEBA_NXZ
     * @hash   -2067593739
     */
    virtual bool entityHasBeenFound() const;
    /**
     * @vftbl  22
     * @symbol ?setEntityFound@TickingArea@@UEAAXXZ
     * @hash   -424221406
     */
    virtual void setEntityFound();
    /**
     * @vftbl  23
     * @symbol ?isRemoved@TickingArea@@UEAA_NXZ
     * @hash   695624829
     */
    virtual bool isRemoved();
    /**
     * @vftbl  24
     * @symbol ?remove@TickingArea@@UEAAXAEAVLevelStorage@@@Z
     * @hash   -1405939276
     */
    virtual void remove(class LevelStorage &);
    /**
     * @vftbl  25
     * @symbol ?onComponentChanged@TickingArea@@UEAAXIM_NAEAVLevelStorage@@@Z
     * @hash   1422851156
     */
    virtual void onComponentChanged(unsigned int, float, bool, class LevelStorage &);
    /**
     * @vftbl  26
     * @symbol ?updateBlockSourceCurrentTick@TickingArea@@UEAAXAEBUTick@@@Z
     * @hash   -1159600475
     */
    virtual void updateBlockSourceCurrentTick(struct Tick const &);
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_TICKINGAREA
    /**
     * @symbol ?getBlockSource@TickingArea@@UEAAAEAVBlockSource@@XZ
     * @hash   -1303657631
     */
    MCVAPI class BlockSource & getBlockSource();
    /**
     * @symbol ?getBlockSource@TickingArea@@UEBAAEBVBlockSource@@XZ
     * @hash   -1736472547
     */
    MCVAPI class BlockSource const & getBlockSource() const;
    /**
     * @symbol ?getView@TickingArea@@UEAAAEAVITickingAreaView@@XZ
     * @hash   -245436036
     */
    MCVAPI class ITickingAreaView & getView();
    /**
     * @symbol ?getView@TickingArea@@UEBAAEBVITickingAreaView@@XZ
     * @hash   1026031160
     */
    MCVAPI class ITickingAreaView const & getView() const;
#endif
    /**
     * @symbol ??0TickingArea@@QEAA@AEAVDimension@@VUUID@mce@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBUBounds@@_NW4TickingAreaLoadMode@@@Z
     * @hash   223357778
     */
    MCAPI TickingArea(class Dimension &, class mce::UUID, std::string const &, struct Bounds const &, bool, enum TickingAreaLoadMode);
    /**
     * @symbol ??0TickingArea@@QEAA@AEAVDimension@@VUUID@mce@@AEBUBounds@@UActorUniqueID@@M@Z
     * @hash   504696335
     */
    MCAPI TickingArea(class Dimension &, class mce::UUID, struct Bounds const &, struct ActorUniqueID, float);
    /**
     * @symbol ??0TickingArea@@QEAA@AEAVDimension@@VUUID@mce@@AEBUBounds@@UActorUniqueID@@@Z
     * @hash   -422146158
     */
    MCAPI TickingArea(class Dimension &, class mce::UUID, struct Bounds const &, struct ActorUniqueID);

//private:
    /**
     * @symbol ??0TickingArea@@AEAA@AEAVDimension@@VUUID@mce@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UActorUniqueID@@AEBUBounds@@_NM5W4TickingAreaLoadMode@@@Z
     * @hash   -2052881454
     */
    MCAPI TickingArea(class Dimension &, class mce::UUID, std::string const &, struct ActorUniqueID, struct Bounds const &, bool, float, bool, enum TickingAreaLoadMode);
    /**
     * @symbol ?_center@TickingArea@@AEAAXAEAVLevelStorage@@@Z
     * @hash   1796910951
     */
    MCAPI void _center(class LevelStorage &);
    /**
     * @symbol ?_save@TickingArea@@AEAAXAEAVLevelStorage@@@Z
     * @hash   1219005567
     */
    MCAPI void _save(class LevelStorage &);

private:

};