#pragma once

#include "custom-types/shared/macros.hpp"

#include "HMUI/ViewController.hpp"

#define GET_METHOD(method) il2cpp_utils::il2cpp_type_check::MetadataGetter<&method>::get()

DECLARE_CLASS_CODEGEN(RumbleMod::UI::ViewControllers, SettingsViewController,::HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, GET_METHOD(::HMUI::ViewController::DidActivate),
                            bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

    // Do BSML values here or smth
)