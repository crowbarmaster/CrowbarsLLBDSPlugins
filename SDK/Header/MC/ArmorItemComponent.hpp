/**
 * @file  ArmorItemComponent.hpp
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
 * @brief MC class ArmorItemComponent.
 *
 */
class ArmorItemComponent {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ARMORITEMCOMPONENT
public:
    class ArmorItemComponent& operator=(class ArmorItemComponent const &) = delete;
    ArmorItemComponent(class ArmorItemComponent const &) = delete;
    ArmorItemComponent() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   -1555556747
     */
    virtual ~ArmorItemComponent();
    /**
     * @vftbl  1
     * @symbol ?isNetworkComponent@?$NetworkedItemComponent@VArmorItemComponent@@@@UEBA_NXZ
     * @hash   1427385894
     */
    virtual bool isNetworkComponent() const;
    /**
     * @vftbl  2
     * @hash   -1365271070
     */
    virtual void __unk_vfn_2();
    /**
     * @vftbl  3
     * @hash   -1357612861
     */
    virtual void __unk_vfn_3();
    /**
     * @vftbl  4
     * @hash   -1405708028
     */
    virtual void __unk_vfn_4();
    /**
     * @vftbl  5
     * @symbol ?buildNetworkTag@?$NetworkedItemComponent@VArmorItemComponent@@@@UEBA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@XZ
     * @hash   945585240
     */
    virtual std::unique_ptr<class CompoundTag> buildNetworkTag() const;
    /**
     * @vftbl  6
     * @symbol ?initializeFromNetwork@?$NetworkedItemComponent@VArmorItemComponent@@@@UEAA_NAEBVCompoundTag@@@Z
     * @hash   199031752
     */
    virtual bool initializeFromNetwork(class CompoundTag const &);
    /**
     * @symbol ?getArmorTextureType@ArmorItemComponent@@QEBA?AW4ArmorTextureType@@XZ
     * @hash   1841260622
     */
    MCAPI enum ArmorTextureType getArmorTextureType() const;
    /**
     * @symbol ?getArmorValue@ArmorItemComponent@@QEBAHXZ
     * @hash   651217926
     */
    MCAPI int getArmorValue() const;
    /**
     * @symbol ?bindType@ArmorItemComponent@@SAXXZ
     * @hash   -235388157
     */
    MCAPI static void bindType();
    /**
     * @symbol ?getIdentifier@ArmorItemComponent@@SAAEBVHashedString@@XZ
     * @hash   -582594494
     */
    MCAPI static class HashedString const & getIdentifier();

};