/**
 * @file  AppConfigs.hpp
 * @note  This Header is auto generated by LiteLoaderBDS Toolchain.
 *
 */
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Bedrock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class AppConfigs.
 *
 */
class AppConfigs {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_APPCONFIGS
public:
    class AppConfigs& operator=(class AppConfigs const &) = delete;
    AppConfigs(class AppConfigs const &) = delete;
#endif

public:
    /**
     * @vftbl  0
     * @hash   1242141146
     */
    virtual ~AppConfigs();
    /**
     * @vftbl  1
     * @hash   -1359459903
     */
    virtual void __unk_vfn_1();
    /**
     * @vftbl  2
     * @hash   -1358536382
     */
    virtual void __unk_vfn_2();
    /**
     * @vftbl  3
     * @hash   -1357612861
     */
    virtual void __unk_vfn_3();
    /**
     * @vftbl  4
     * @hash   -1356689340
     */
    virtual void __unk_vfn_4();
    /**
     * @vftbl  5
     * @hash   -1362500507
     */
    virtual void __unk_vfn_5();
    /**
     * @vftbl  6
     * @hash   -1354842298
     */
    virtual void __unk_vfn_6();
    /**
     * @vftbl  7
     * @hash   -1353918777
     */
    virtual void __unk_vfn_7();
    /**
     * @vftbl  8
     * @hash   -1352995256
     */
    virtual void __unk_vfn_8();
    /**
     * @vftbl  9
     * @hash   -1352071735
     */
    virtual void __unk_vfn_9();
    /**
     * @vftbl  10
     * @hash   -335971357
     */
    virtual void __unk_vfn_10();
    /**
     * @vftbl  11
     * @hash   -341782524
     */
    virtual void __unk_vfn_11();
    /**
     * @vftbl  12
     * @hash   -340859003
     */
    virtual void __unk_vfn_12();
    /**
     * @vftbl  13
     * @hash   -339935482
     */
    virtual void __unk_vfn_13();
    /**
     * @vftbl  14
     * @hash   -339011961
     */
    virtual void __unk_vfn_14();
    /**
     * @vftbl  15
     * @hash   -338088440
     */
    virtual void __unk_vfn_15();
    /**
     * @vftbl  16
     * @hash   -337164919
     */
    virtual void __unk_vfn_16();
    /**
     * @vftbl  17
     * @hash   -378525398
     */
    virtual void __unk_vfn_17();
    /**
     * @vftbl  18
     * @symbol ?getEducationEditionOffering@AppConfigs@@UEBA?AW4EducationEditionOffer@@XZ
     * @hash   4140626
     */
    virtual enum EducationEditionOffer getEducationEditionOffering() const;
    /**
     * @vftbl  19
     * @hash   -334394356
     */
    virtual void __unk_vfn_19();
    /**
     * @vftbl  20
     * @hash   -307342206
     */
    virtual void __unk_vfn_20();
    /**
     * @vftbl  21
     * @symbol ?supports3DExport@AppConfigs@@UEBA_NXZ
     * @hash   -1715866479
     */
    virtual bool supports3DExport() const;
    /**
     * @vftbl  22
     * @hash   -305495164
     */
    virtual void __unk_vfn_22();
    /**
     * @vftbl  23
     * @symbol ?getConnectionDefinition@AppConfigs@@UEBA?AUConnectionDefinition@@XZ
     * @hash   146154834
     */
    virtual struct ConnectionDefinition getConnectionDefinition() const;
    /**
     * @vftbl  24
     * @hash   -352666810
     */
    virtual void __unk_vfn_24();
    /**
     * @vftbl  25
     * @hash   -302724601
     */
    virtual void __unk_vfn_25();
    /**
     * @vftbl  26
     * @hash   -301801080
     */
    virtual void __unk_vfn_26();
    /**
     * @vftbl  27
     * @hash   -307612247
     */
    virtual void __unk_vfn_27();
    /**
     * @vftbl  28
     * @hash   -299954038
     */
    virtual void __unk_vfn_28();
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
     * @vftbl  31
     * @hash   -277789534
     */
    virtual void __unk_vfn_31();
    /**
     * @vftbl  32
     * @symbol ?getAdditionalClientPacks@AppConfigs@@UEBA?AV?$vector@UPackIdVersion@@V?$allocator@UPackIdVersion@@@std@@@std@@_N@Z
     * @hash   789308987
     */
    virtual std::vector<struct PackIdVersion> getAdditionalClientPacks(bool) const;
    /**
     * @vftbl  33
     * @symbol ?getScreenCapabilities@AppConfigs@@UEBA?AV?$unique_ptr@VIScreenCapabilities@@U?$default_delete@VIScreenCapabilities@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z
     * @hash   -1322399175
     */
    virtual std::unique_ptr<class IScreenCapabilities> getScreenCapabilities(std::string const &) const;
    /**
     * @vftbl  34
     * @symbol ?createContentAccessibility@AppConfigs@@UEBA?AV?$unique_ptr@VIContentAccessibilityProvider@@U?$default_delete@VIContentAccessibilityProvider@@@std@@@std@@V?$not_null@V?$NonOwnerPointer@VIEntitlementManager@@@Bedrock@@@gsl@@@Z
     * @hash   -794552768
     */
    virtual std::unique_ptr<class IContentAccessibilityProvider> createContentAccessibility(class gsl::not_null<class Bedrock::NonOwnerPointer<class IEntitlementManager>>) const;
    /**
     * @vftbl  35
     * @symbol ?getFeedbackURL@AppConfigs@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
     * @hash   -446183970
     */
    virtual std::string getFeedbackURL() const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_APPCONFIGS
    /**
     * @symbol ?allowGameArguments@AppConfigs@@UEBA_NXZ
     * @hash   1778074307
     */
    MCVAPI bool allowGameArguments() const;
    /**
     * @symbol ?applyLevelDataOverride@AppConfigs@@UEBAXAEAVLevelData@@@Z
     * @hash   506858970
     */
    MCVAPI void applyLevelDataOverride(class LevelData &) const;
    /**
     * @symbol ?areEmotesSupported@AppConfigs@@UEBA_NXZ
     * @hash   -1664812153
     */
    MCVAPI bool areEmotesSupported() const;
    /**
     * @symbol ?arePremiumSkinPacksAllowed@AppConfigs@@UEBA_NXZ
     * @hash   -404409706
     */
    MCVAPI bool arePremiumSkinPacksAllowed() const;
    /**
     * @symbol ?areQuizzesSupported@AppConfigs@@UEBA_NXZ
     * @hash   739183831
     */
    MCVAPI bool areQuizzesSupported() const;
    /**
     * @symbol ?areResourcePacksAllowed@AppConfigs@@UEBA_NXZ
     * @hash   -549025000
     */
    MCVAPI bool areResourcePacksAllowed() const;
    /**
     * @symbol ?canUseAzureNotebooks@AppConfigs@@UEBA_NXZ
     * @hash   -1029702168
     */
    MCVAPI bool canUseAzureNotebooks() const;
    /**
     * @symbol ?canUseMaelstrom@AppConfigs@@UEBA?AW4MaelstromEduUsabilityStatus@1@XZ
     * @hash   796509071
     */
    MCVAPI enum AppConfigs::MaelstromEduUsabilityStatus canUseMaelstrom() const;
    /**
     * @symbol ?gameArgumentsNeedAuthentication@AppConfigs@@UEBA_NXZ
     * @hash   -644102118
     */
    MCVAPI bool gameArgumentsNeedAuthentication() const;
    /**
     * @symbol ?isChatScreenAllowed@AppConfigs@@UEBA_NXZ
     * @hash   1187847554
     */
    MCVAPI bool isChatScreenAllowed() const;
    /**
     * @symbol ?isCoursesCacheEnabled@AppConfigs@@UEBA_NXZ
     * @hash   -202598859
     */
    MCVAPI bool isCoursesCacheEnabled() const;
    /**
     * @symbol ?isExternalPlayerCommunicationAllowed@AppConfigs@@UEBA_NXZ
     * @hash   1514302032
     */
    MCVAPI bool isExternalPlayerCommunicationAllowed() const;
    /**
     * @symbol ?isGameTabShownInSettings@AppConfigs@@UEBA_NXZ
     * @hash   1214945352
     */
    MCVAPI bool isGameTabShownInSettings() const;
    /**
     * @symbol ?isLessonProgressionSupported@AppConfigs@@UEBA_NXZ
     * @hash   1322309501
     */
    MCVAPI bool isLessonProgressionSupported() const;
    /**
     * @symbol ?isPlayScreenAllowed@AppConfigs@@UEBA_NXZ
     * @hash   -1584237402
     */
    MCVAPI bool isPlayScreenAllowed() const;
    /**
     * @symbol ?loadFromData@AppConfigs@@UEAAXAEBVIAppConfigData@@@Z
     * @hash   -1031489956
     */
    MCVAPI void loadFromData(class IAppConfigData const &);
    /**
     * @symbol ?muteByDefault@AppConfigs@@UEBA_NXZ
     * @hash   1816807225
     */
    MCVAPI bool muteByDefault() const;
    /**
     * @symbol ?requireEduLevelSettings@AppConfigs@@UEBA_NXZ
     * @hash   -627448962
     */
    MCVAPI bool requireEduLevelSettings() const;
    /**
     * @symbol ?requireTrustedContent@AppConfigs@@UEBA_NXZ
     * @hash   -1995299345
     */
    MCVAPI bool requireTrustedContent() const;
    /**
     * @symbol ?sendPermissionsTelemetry@AppConfigs@@UEBA_NXZ
     * @hash   -214614171
     */
    MCVAPI bool sendPermissionsTelemetry() const;
    /**
     * @symbol ?setCanAccessWorldCallback@AppConfigs@@UEAAXAEAVIMinecraftGame@@@Z
     * @hash   -1108169246
     */
    MCVAPI void setCanAccessWorldCallback(class IMinecraftGame &);
    /**
     * @symbol ?shouldPromptBeforeExit@AppConfigs@@UEBA_NXZ
     * @hash   304898908
     */
    MCVAPI bool shouldPromptBeforeExit() const;
    /**
     * @symbol ?supportsChangingMultiplayerDuringPlay@AppConfigs@@UEBA_NXZ
     * @hash   606675654
     */
    MCVAPI bool supportsChangingMultiplayerDuringPlay() const;
    /**
     * @symbol ?useEduDemoUpsellDialog@AppConfigs@@UEBA_NXZ
     * @hash   966955599
     */
    MCVAPI bool useEduDemoUpsellDialog() const;
    /**
     * @symbol ?useFullScreenByDefault@AppConfigs@@UEBA_NXZ
     * @hash   167461008
     */
    MCVAPI bool useFullScreenByDefault() const;
    /**
     * @symbol ?useNormalizedFontSize@AppConfigs@@UEBA_NXZ
     * @hash   -1460870090
     */
    MCVAPI bool useNormalizedFontSize() const;
    /**
     * @symbol ?webSocketsDisabled@AppConfigs@@UEBA_NXZ
     * @hash   916246864
     */
    MCVAPI bool webSocketsDisabled() const;
    /**
     * @symbol ?worldBuilderDisabled@AppConfigs@@UEBA_NXZ
     * @hash   -776970131
     */
    MCVAPI bool worldBuilderDisabled() const;
    /**
     * @symbol ?worldsAreSingleUse@AppConfigs@@UEBA_NXZ
     * @hash   -2059963212
     */
    MCVAPI bool worldsAreSingleUse() const;
#endif
    /**
     * @symbol ??0AppConfigs@@QEAA@XZ
     * @hash   -1411731444
     */
    MCAPI AppConfigs();

};