#pragma once

#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"
#include "HMUI/ViewController.hpp"

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(RumbleMod::UI::ViewControllers, SettingsViewController, ::HMUI::ViewController,
    DECLARE_DEFAULT_CTOR();
    DECLARE_OVERRIDE_METHOD(void, DidActivate, GET_FIND_METHOD(&::HMUI::ViewController::DidActivate),
                            bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

// *** *** UI VALUES *** ***
    DECLARE_BSML_PROPERTY(bool, ModEnabled);
    DECLARE_BSML_PROPERTY(float, NoteStrength);
    DECLARE_BSML_PROPERTY(float, ChainStrength);
    DECLARE_BSML_PROPERTY(float, ArcStrength);
    DECLARE_BSML_PROPERTY(float, SaberStrength);
    DECLARE_BSML_PROPERTY(float, WallStrength);
    DECLARE_BSML_PROPERTY(float, UIStrength);
)