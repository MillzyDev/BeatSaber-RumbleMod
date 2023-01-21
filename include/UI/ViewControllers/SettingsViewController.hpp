#pragma once

#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"

#include "HMUI/ViewController.hpp"
#include "TMPro/TextMeshProUGUI.hpp"
#include "UnityEngine/UI/HorizontalLayoutGroup.hpp"

#define TextMeshProUGUI TMPro::TextMeshProUGUI
#define HorizontalLayoutGroup UnityEngine::UI::HorizontalLayoutGroup

#define GET_METHOD(method) il2cpp_utils::il2cpp_type_check::MetadataGetter<&method>::get()

DECLARE_CLASS_CODEGEN(RumbleMod::UI::ViewControllers, SettingsViewController,::HMUI::ViewController,
    DECLARE_INSTANCE_FIELD(TextMeshProUGUI *, noteEnabledText);
    DECLARE_INSTANCE_FIELD(HorizontalLayoutGroup *, noteInteractables);
    DECLARE_INSTANCE_FIELD(TextMeshProUGUI *, chainEnabledText);
    DECLARE_INSTANCE_FIELD(HorizontalLayoutGroup *, chainInteractables);
    DECLARE_INSTANCE_FIELD(TextMeshProUGUI *, arcEnabledText);
    DECLARE_INSTANCE_FIELD(HorizontalLayoutGroup *, arcInteractables);
    DECLARE_INSTANCE_FIELD(TextMeshProUGUI *, saberEnabledText);
    DECLARE_INSTANCE_FIELD(HorizontalLayoutGroup *, saberInteractables);
    DECLARE_INSTANCE_FIELD(TextMeshProUGUI *, wallEnabledText);
    DECLARE_INSTANCE_FIELD(HorizontalLayoutGroup *, wallInteractables);
    DECLARE_INSTANCE_FIELD(TextMeshProUGUI *, uiEnabledText);
    DECLARE_INSTANCE_FIELD(HorizontalLayoutGroup *, uiInteractables);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, GET_METHOD(::HMUI::ViewController::DidActivate),
                            bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

    DECLARE_BSML_PROPERTY(bool, noteEnabled);
    DECLARE_BSML_PROPERTY(float, noteStrength);
    DECLARE_BSML_PROPERTY(bool, chainEnabled);
    DECLARE_BSML_PROPERTY(float, chainStrength);
    DECLARE_BSML_PROPERTY(bool, arcEnabled);
    DECLARE_BSML_PROPERTY(float, arcStrength);
    DECLARE_BSML_PROPERTY(bool, saberEnabled);
    DECLARE_BSML_PROPERTY(float, saberStrength);
    DECLARE_BSML_PROPERTY(bool, wallEnabled);
    DECLARE_BSML_PROPERTY(float, wallStrength);
    DECLARE_BSML_PROPERTY(bool, uiEnabled);
    DECLARE_BSML_PROPERTY(float, uiStrength);
)

#undef TextMeshProUGUI
#undef HorizontalLayoutGroup