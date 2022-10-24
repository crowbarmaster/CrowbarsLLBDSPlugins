/**
 * @file  CropBlock.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "BushBlock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class CropBlock.
 *
 */
class CropBlock : public BushBlock {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CROPBLOCK
public:
    class CropBlock& operator=(class CropBlock const &) = delete;
    CropBlock(class CropBlock const &) = delete;
    CropBlock() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -1182998741
     */
    virtual ~CropBlock();
    /**
     * @vftbl  4
     * @symbol ?hasTag@CropBlock@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z
     * @hash   1956329505
     */
    virtual bool hasTag(class BlockSource &, class BlockPos const &, class Block const &, std::string const &) const;
    /**
     * @vftbl  10
     * @symbol ?getAABB@CropBlock@@UEBAAEBVAABB@@AEBVIConstBlockSource@@AEBVBlockPos@@AEBVBlock@@AEAV2@_N@Z
     * @hash   -232203299
     */
    virtual class AABB const & getAABB(class IConstBlockSource const &, class BlockPos const &, class Block const &, class AABB &, bool) const;
    /**
     * @vftbl  19
     * @hash   -327659668
     */
    virtual void __unk_vfn_19();
    /**
     * @vftbl  29
     * @hash   -299030517
     */
    virtual void __unk_vfn_29();
    /**
     * @vftbl  30
     * @hash   -278713055
     */
    virtual void __unk_vfn_30();
    /**
     * @vftbl  32
     * @hash   -276866013
     */
    virtual void __unk_vfn_32();
    /**
     * @vftbl  33
     * @hash   -275942492
     */
    virtual void __unk_vfn_33();
    /**
     * @vftbl  34
     * @hash   -275018971
     */
    virtual void __unk_vfn_34();
    /**
     * @vftbl  36
     * @hash   -273171929
     */
    virtual void __unk_vfn_36();
    /**
     * @vftbl  37
     * @hash   -272248408
     */
    virtual void __unk_vfn_37();
    /**
     * @vftbl  38
     * @hash   -271324887
     */
    virtual void __unk_vfn_38();
    /**
     * @vftbl  39
     * @hash   -270401366
     */
    virtual void __unk_vfn_39();
    /**
     * @vftbl  40
     * @hash   -250083904
     */
    virtual void __unk_vfn_40();
    /**
     * @vftbl  41
     * @hash   -249160383
     */
    virtual void __unk_vfn_41();
    /**
     * @vftbl  42
     * @hash   -248236862
     */
    virtual void __unk_vfn_42();
    /**
     * @vftbl  44
     * @hash   -246389820
     */
    virtual void __unk_vfn_44();
    /**
     * @vftbl  45
     * @hash   -245466299
     */
    virtual void __unk_vfn_45();
    /**
     * @vftbl  46
     * @hash   -244542778
     */
    virtual void __unk_vfn_46();
    /**
     * @vftbl  47
     * @hash   -243619257
     */
    virtual void __unk_vfn_47();
    /**
     * @vftbl  48
     * @hash   -242695736
     */
    virtual void __unk_vfn_48();
    /**
     * @vftbl  49
     * @hash   -241772215
     */
    virtual void __unk_vfn_49();
    /**
     * @vftbl  59
     * @hash   -219877752
     */
    virtual void __unk_vfn_59();
    /**
     * @vftbl  60
     * @hash   -192825602
     */
    virtual void __unk_vfn_60();
    /**
     * @vftbl  61
     * @symbol ?canContainLiquid@CropBlock@@UEBA_NXZ
     * @hash   -695788165
     */
    virtual bool canContainLiquid() const;
    /**
     * @vftbl  73
     * @hash   -161425888
     */
    virtual void __unk_vfn_73();
    /**
     * @vftbl  80
     * @hash   -135567300
     */
    virtual void __unk_vfn_80();
    /**
     * @vftbl  84
     * @symbol ?onFertilized@CropBlock@@MEBA_NAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@W4FertilizerType@@@Z
     * @hash   1331754178
     */
    virtual bool onFertilized(class BlockSource &, class BlockPos const &, class Actor *, enum FertilizerType) const;
    /**
     * @vftbl  86
     * @symbol ?canBeFertilized@CropBlock@@MEBA_NAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z
     * @hash   -2041158231
     */
    virtual bool canBeFertilized(class BlockSource &, class BlockPos const &, class Block const &) const;
    /**
     * @vftbl  91
     * @symbol ?mayPlaceOn@CropBlock@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z
     * @hash   -1060936222
     */
    virtual bool mayPlaceOn(class BlockSource &, class BlockPos const &) const;
    /**
     * @vftbl  98
     * @symbol ?neighborChanged@CropBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@1@Z
     * @hash   704725887
     */
    virtual void neighborChanged(class BlockSource &, class BlockPos const &, class BlockPos const &) const;
    /**
     * @vftbl  102
     * @symbol ?asItemInstance@CropBlock@@UEBA?AVItemInstance@@AEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z
     * @hash   245565264
     */
    virtual class ItemInstance asItemInstance(class BlockSource &, class BlockPos const &, class Block const &) const;
    /**
     * @vftbl  103
     * @symbol ?spawnResources@CropBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@AEAVRandomize@@PEAV?$vector@PEBVItem@@V?$allocator@PEBVItem@@@std@@@std@@MH@Z
     * @hash   1914165201
     */
    virtual void spawnResources(class BlockSource &, class BlockPos const &, class Block const &, class Randomize &, std::vector<class Item const *> *, float, int) const;
    /**
     * @vftbl  105
     * @hash   1332020102
     */
    virtual void __unk_vfn_105();
    /**
     * @vftbl  119
     * @symbol ?executeEvent@CropBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVActor@@@Z
     * @hash   22307297
     */
    virtual void executeEvent(class BlockSource &, class BlockPos const &, class Block const &, std::string const &, class Actor &) const;
    /**
     * @vftbl  124
     * @hash   1388354883
     */
    virtual void __unk_vfn_124();
    /**
     * @vftbl  126
     * @hash   1390201925
     */
    virtual void __unk_vfn_126();
    /**
     * @vftbl  127
     * @hash   1391125446
     */
    virtual void __unk_vfn_127();
    /**
     * @vftbl  132
     * @hash   1415136992
     */
    virtual void __unk_vfn_132();
    /**
     * @vftbl  147
     * @symbol ?getVariant@CropBlock@@UEBAHAEBVBlock@@@Z
     * @hash   -1120778307
     */
    virtual int getVariant(class Block const &) const;
    /**
     * @vftbl  148
     * @hash   1442572581
     */
    virtual void __unk_vfn_148();
    /**
     * @vftbl  157
     * @hash   1477012899
     */
    virtual void __unk_vfn_157();
    /**
     * @vftbl  168
     * @hash   1457546883
     */
    virtual void __unk_vfn_168();
    /**
     * @vftbl  169
     * @hash   1458470404
     */
    virtual void __unk_vfn_169();
    /**
     * @vftbl  170
     * @hash   1478787866
     */
    virtual void __unk_vfn_170();
    /**
     * @vftbl  175
     * @symbol ?randomTick@CropBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z
     * @hash   1139896960
     */
    virtual void randomTick(class BlockSource &, class BlockPos const &, class Random &) const;
    /**
     * @vftbl  177
     * @hash   1534271201
     */
    virtual void __unk_vfn_177();
    /**
     * @vftbl  180
     * @symbol ?canSurvive@CropBlock@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z
     * @hash   -456741981
     */
    virtual bool canSurvive(class BlockSource &, class BlockPos const &) const;
    /**
     * @vftbl  188
     * @hash   1563823873
     */
    virtual void __unk_vfn_188();
    /**
     * @vftbl  193
     * @symbol ?getBaseSeed@CropBlock@@MEBA?BVItemInstance@@XZ
     * @hash   2105972040
     */
    virtual class ItemInstance const getBaseSeed() const;
    /**
     * @vftbl  194
     * @symbol ?getBaseCrop@CropBlock@@MEBA?BVItemInstance@@XZ
     * @hash   -708251289
     */
    virtual class ItemInstance const getBaseCrop() const;
    /**
     * @vftbl  195
     * @symbol ?getSeedNum@CropBlock@@MEBAHAEAVRandomize@@HH@Z
     * @hash   -1015968269
     */
    virtual int getSeedNum(class Randomize &, int, int) const;
    /**
     * @vftbl  196
     * @symbol ?getCropNum@CropBlock@@MEBAHAEAVRandomize@@HH@Z
     * @hash   9274194
     */
    virtual int getCropNum(class Randomize &, int, int) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_CROPBLOCK
    /**
     * @symbol ?canBeSilkTouched@CropBlock@@MEBA_NXZ
     * @hash   1798446282
     */
    MCVAPI bool canBeSilkTouched() const;
#endif
    /**
     * @symbol ??0CropBlock@@QEAA@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z
     * @hash   1743135627
     */
    MCAPI CropBlock(std::string const &, int);

//private:
    /**
     * @symbol ?getGrowthSpeed@CropBlock@@AEBAMAEAVBlockSource@@AEBVBlockPos@@@Z
     * @hash   -232197970
     */
    MCAPI float getGrowthSpeed(class BlockSource &, class BlockPos const &) const;

private:

};