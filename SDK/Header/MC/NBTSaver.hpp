/**
 * @file  NBTSaver.hpp
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
 * @brief MC class NBTSaver.
 *
 */
class NBTSaver {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_NBTSAVER
public:
    class NBTSaver& operator=(class NBTSaver const &) = delete;
    NBTSaver(class NBTSaver const &) = delete;
    NBTSaver() = delete;
#endif

public:
    /**
     * @symbol ?getSavedCompoundTag@NBTSaver@@QEAA?AVCompoundTag@@XZ
     * @hash   792982694
     */
    MCAPI class CompoundTag getSavedCompoundTag();

};