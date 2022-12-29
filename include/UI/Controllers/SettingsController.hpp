#pragma once

#include "main.hpp"
#include "custom-types/shared/macros.hpp"
#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSMLDataCache.hpp"
#include "GlobalNamespace/PersistentSingleton_1.hpp"
#include "assets.hpp"

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(RumbleMod::UI::Controllers, SettingsController, Il2CppObject,
public:
    static SettingsController *get_instance();
    static SafePtr<SettingsController> instance;

    DECLARE_DEFAULT_CTOR();

    // *** *** UI VALUES *** ***
    DECLARE_BSML_PROPERTY(bool, ModEnabled);
    DECLARE_BSML_PROPERTY(float, NoteStrength);
    DECLARE_BSML_PROPERTY(float, ChainStrength);
    DECLARE_BSML_PROPERTY(float, ArcStrength);
    DECLARE_BSML_PROPERTY(float, SaberStrength);
    DECLARE_BSML_PROPERTY(float, WallStrength);
    DECLARE_BSML_PROPERTY(float, UIStrength);

)