/**
 * @file  PrimedTnt.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "PredictableProjectile.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class PrimedTnt.
 *
 */
class PrimedTnt : public PredictableProjectile {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PRIMEDTNT
public:
    class PrimedTnt& operator=(class PrimedTnt const &) = delete;
    PrimedTnt(class PrimedTnt const &) = delete;
    PrimedTnt() = delete;
#endif

public:
    /**
     * @vftbl  8
     * @symbol ?reloadHardcoded@PrimedTnt@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z
     * @hash   315265256
     */
    virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /**
     * @vftbl  9
     * @symbol ?reloadHardcodedClient@PrimedTnt@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z
     * @hash   -591918221
     */
    virtual void reloadHardcodedClient(enum Actor::InitializationMethod, class VariantParameterList const &);
    /**
     * @vftbl  10
     * @symbol ?initializeComponents@PrimedTnt@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z
     * @hash   336587803
     */
    virtual void initializeComponents(enum Actor::InitializationMethod, class VariantParameterList const &);
    /**
     * @vftbl  14
     * @hash   20535427
     */
    virtual ~PrimedTnt();
    /**
     * @vftbl  17
     * @symbol ?getOwnerEntityType@PrimedTnt@@UEAA?AW4ActorType@@XZ
     * @hash   -1843640195
     */
    virtual enum ActorType getOwnerEntityType();
    /**
     * @vftbl  41
     * @hash   -249160383
     */
    virtual void __unk_vfn_41();
    /**
     * @vftbl  44
     * @symbol ?teleportTo@PrimedTnt@@UEAAXAEBVVec3@@_NHH1@Z
     * @hash   1224530338
     */
    virtual void teleportTo(class Vec3 const &, bool, int, int, bool);
    /**
     * @vftbl  49
     * @symbol ?normalTick@PrimedTnt@@UEAAXXZ
     * @hash   910124806
     */
    virtual void normalTick();
    /**
     * @vftbl  61
     * @hash   -198636769
     */
    virtual void __unk_vfn_61();
    /**
     * @vftbl  68
     * @hash   -185437434
     */
    virtual void __unk_vfn_68();
    /**
     * @vftbl  79
     * @symbol ?getShadowHeightOffs@PrimedTnt@@UEAAMXZ
     * @hash   -1881344869
     */
    virtual float getShadowHeightOffs();
    /**
     * @vftbl  80
     * @symbol ?getShadowRadius@PrimedTnt@@UEBAMXZ
     * @hash   -143847007
     */
    virtual float getShadowRadius() const;
    /**
     * @vftbl  82
     * @hash   -133720258
     */
    virtual void __unk_vfn_82();
    /**
     * @vftbl  85
     * @hash   -137684383
     */
    virtual void __unk_vfn_85();
    /**
     * @vftbl  88
     * @hash   -128179132
     */
    virtual void __unk_vfn_88();
    /**
     * @vftbl  95
     * @symbol ?isPickable@PrimedTnt@@UEAA_NXZ
     * @hash   1752629049
     */
    virtual bool isPickable();
    /**
     * @vftbl  96
     * @hash   -108131711
     */
    virtual void __unk_vfn_96();
    /**
     * @vftbl  99
     * @hash   -98626460
     */
    virtual void __unk_vfn_99();
    /**
     * @vftbl  106
     * @hash   1332943623
     */
    virtual void __unk_vfn_106();
    /**
     * @vftbl  108
     * @hash   1334790665
     */
    virtual void __unk_vfn_108();
    /**
     * @vftbl  109
     * @hash   1328979498
     */
    virtual void __unk_vfn_109();
    /**
     * @vftbl  111
     * @hash   1356955169
     */
    virtual void __unk_vfn_111();
    /**
     * @vftbl  172
     * @symbol ?getSourceUniqueID@PrimedTnt@@UEBA?AUActorUniqueID@@XZ
     * @hash   298566897
     */
    virtual struct ActorUniqueID getSourceUniqueID() const;
    /**
     * @vftbl  182
     * @hash   1509264059
     */
    virtual void __unk_vfn_182();
    /**
     * @vftbl  196
     * @hash   1590605982
     */
    virtual void __unk_vfn_196();
    /**
     * @vftbl  222
     * @hash   -2034256014
     */
    virtual void __unk_vfn_222();
    /**
     * @vftbl  223
     * @hash   -2020032253
     */
    virtual void __unk_vfn_223();
    /**
     * @vftbl  248
     * @hash   -2007175034
     */
    virtual void __unk_vfn_248();
    /**
     * @vftbl  251
     * @hash   -786620466
     */
    virtual void __unk_vfn_251();
    /**
     * @vftbl  269
     * @hash   -1906709211
     */
    virtual void __unk_vfn_269();
    /**
     * @vftbl  270
     * @symbol ?_hurt@PrimedTnt@@MEAA_NAEBVActorDamageSource@@M_N1@Z
     * @hash   -1547796437
     */
    virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /**
     * @vftbl  273
     * @symbol ?readAdditionalSaveData@PrimedTnt@@MEAAXAEBVCompoundTag@@AEAVDataLoadHelper@@@Z
     * @hash   582064635
     */
    virtual void readAdditionalSaveData(class CompoundTag const &, class DataLoadHelper &);
    /**
     * @vftbl  274
     * @symbol ?addAdditionalSaveData@PrimedTnt@@MEBAXAEAVCompoundTag@@@Z
     * @hash   -1377109454
     */
    virtual void addAdditionalSaveData(class CompoundTag &) const;
    /**
     * @vftbl  277
     * @hash   -1873192414
     */
    virtual void __unk_vfn_277();
    /**
     * @symbol ??0PrimedTnt@@QEAA@PEAVActorDefinitionGroup@@AEBUActorDefinitionIdentifier@@AEAVEntityContext@@@Z
     * @hash   -2077364607
     */
    MCAPI PrimedTnt(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    /**
     * @symbol ?postNormalTick@PrimedTnt@@QEAAXXZ
     * @hash   -645295461
     */
    MCAPI void postNormalTick();

};