/**
 * @file  TickingAreaListBase.hpp
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
 * @brief MC class TickingAreaListBase.
 *
 */
class TickingAreaListBase {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_TICKINGAREALISTBASE
public:
    class TickingAreaListBase& operator=(class TickingAreaListBase const &) = delete;
    TickingAreaListBase(class TickingAreaListBase const &) = delete;
    TickingAreaListBase() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -948534065
     */
    virtual ~TickingAreaListBase();
    /**
     * @vftbl  1
     * @symbol ?removeDistantEntityAreasAndCheckForRemoved@TickingAreaListBase@@UEAA_NAEBV?$vector@VVec3@@V?$allocator@VVec3@@@std@@@std@@V?$function@$$A6AXAEBVITickingArea@@@Z@3@AEAVLevelStorage@@@Z
     * @hash   -1351060417
     */
    virtual bool removeDistantEntityAreasAndCheckForRemoved(std::vector<class Vec3> const &, class std::function<void (class ITickingArea const &)>, class LevelStorage &);
    /**
     * @symbol ?add@TickingAreaListBase@@QEAAXV?$unique_ptr@VITickingArea@@U?$default_delete@VITickingArea@@@std@@@std@@@Z
     * @hash   -811005342
     */
    MCAPI void add(std::unique_ptr<class ITickingArea>);
    /**
     * @symbol ?countEntityTickingAreas@TickingAreaListBase@@QEBAIXZ
     * @hash   -1942414360
     */
    MCAPI unsigned int countEntityTickingAreas() const;
    /**
     * @symbol ?countStandaloneTickingAreas@TickingAreaListBase@@QEBAIXZ
     * @hash   -862673140
     */
    MCAPI unsigned int countStandaloneTickingAreas() const;
    /**
     * @symbol ?destroyAreas@TickingAreaListBase@@QEAAXXZ
     * @hash   1627123387
     */
    MCAPI void destroyAreas();
    /**
     * @symbol ?empty@TickingAreaListBase@@QEBA_NXZ
     * @hash   1153583340
     */
    MCAPI bool empty() const;
    /**
     * @symbol ?findStandaloneAreasContaining@TickingAreaListBase@@QEAA?AV?$vector@V?$shared_ptr@VITickingArea@@@std@@V?$allocator@V?$shared_ptr@VITickingArea@@@std@@@2@@std@@AEBVBlockPos@@@Z
     * @hash   673306276
     */
    MCAPI std::vector<class std::shared_ptr<class ITickingArea>> findStandaloneAreasContaining(class BlockPos const &);
    /**
     * @symbol ?findStandaloneAreasNamed@TickingAreaListBase@@QEBA?AV?$vector@V?$shared_ptr@VITickingArea@@@std@@V?$allocator@V?$shared_ptr@VITickingArea@@@std@@@2@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z
     * @hash   -147289768
     */
    MCAPI std::vector<class std::shared_ptr<class ITickingArea>> findStandaloneAreasNamed(std::string const &) const;
    /**
     * @symbol ?getAreaFor@TickingAreaListBase@@QEBA?AV?$shared_ptr@VITickingArea@@@std@@AEBUActorUniqueID@@@Z
     * @hash   546598828
     */
    MCAPI class std::shared_ptr<class ITickingArea> getAreaFor(struct ActorUniqueID const &) const;
    /**
     * @symbol ?getAreas@TickingAreaListBase@@QEBAAEBV?$vector@V?$shared_ptr@VITickingArea@@@std@@V?$allocator@V?$shared_ptr@VITickingArea@@@std@@@2@@std@@XZ
     * @hash   -2041421977
     */
    MCAPI std::vector<class std::shared_ptr<class ITickingArea>> const & getAreas() const;
    /**
     * @symbol ?getStandaloneTickingAreaDescriptions@TickingAreaListBase@@QEBA?AV?$vector@UTickingAreaDescription@@V?$allocator@UTickingAreaDescription@@@std@@@std@@XZ
     * @hash   1564530066
     */
    MCAPI std::vector<struct TickingAreaDescription> getStandaloneTickingAreaDescriptions() const;
    /**
     * @symbol ?hasTickingAreaNamed@TickingAreaListBase@@QEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
     * @hash   1353760995
     */
    MCAPI bool hasTickingAreaNamed(std::string const &) const;
    /**
     * @symbol ?isPreloadDone@TickingAreaListBase@@QEBA_NXZ
     * @hash   -1763210596
     */
    MCAPI bool isPreloadDone() const;
    /**
     * @symbol ?processRemoves@TickingAreaListBase@@QEAAXXZ
     * @hash   345071459
     */
    MCAPI void processRemoves();
    /**
     * @symbol ?processUpdates@TickingAreaListBase@@QEAAXAEAVLevelStorage@@UTick@@@Z
     * @hash   873492415
     */
    MCAPI void processUpdates(class LevelStorage &, struct Tick);
    /**
     * @symbol ?removeAllStandaloneAreas@TickingAreaListBase@@QEAA?AV?$vector@UTickingAreaDescription@@V?$allocator@UTickingAreaDescription@@@std@@@std@@AEAVLevelStorage@@@Z
     * @hash   -1762730519
     */
    MCAPI std::vector<struct TickingAreaDescription> removeAllStandaloneAreas(class LevelStorage &);
    /**
     * @symbol ?removeAreas@TickingAreaListBase@@QEAA?AV?$vector@UTickingAreaDescription@@V?$allocator@UTickingAreaDescription@@@std@@@std@@AEBV?$vector@V?$shared_ptr@VITickingArea@@@std@@V?$allocator@V?$shared_ptr@VITickingArea@@@std@@@2@@3@AEAVLevelStorage@@@Z
     * @hash   -1459113837
     */
    MCAPI std::vector<struct TickingAreaDescription> removeAreas(std::vector<class std::shared_ptr<class ITickingArea>> const &, class LevelStorage &);
    /**
     * @symbol ?tick@TickingAreaListBase@@QEAAXAEBUTick@@@Z
     * @hash   251574622
     */
    MCAPI void tick(struct Tick const &);
    /**
     * @symbol ?tickSeasons@TickingAreaListBase@@QEAAXAEAVRandom@@@Z
     * @hash   18605672
     */
    MCAPI void tickSeasons(class Random &);
    /**
     * @symbol ?updateBlockSourceCurrentTick@TickingAreaListBase@@QEAAXAEBUTick@@@Z
     * @hash   -2031819842
     */
    MCAPI void updateBlockSourceCurrentTick(struct Tick const &);

//protected:
    /**
     * @symbol ?_shouldRemoveArea@TickingAreaListBase@@IEBA_NIAEBV?$vector@VVec3@@V?$allocator@VVec3@@@std@@@std@@@Z
     * @hash   -1676560837
     */
    MCAPI bool _shouldRemoveArea(unsigned int, std::vector<class Vec3> const &) const;

protected:

};