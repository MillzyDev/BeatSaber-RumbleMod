#pragma once

#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"

#include "bsml/shared/BSML/Components/Settings/SliderSetting.hpp"

#include "HMUI/ViewController.hpp"
#include "Libraries/HM/HMLib/VR/HapticPresetSO.hpp"
#include "TMPro/TextMeshProUGUI.hpp"
#include "UnityEngine/UI/Button.hpp"

#include "GlobalNamespace/HapticFeedbackController.hpp"

#define HapticFeedbackController GlobalNamespace::HapticFeedbackController
#define HapticPresetSO Libraries::HM::HMLib::VR::HapticPresetSO
#define TextMeshProUGUI TMPro::TextMeshProUGUI
#define SliderSetting BSML::SliderSetting
#define Button UnityEngine::UI::Button

#define GET_METHOD(method) il2cpp_utils::il2cpp_type_check::MetadataGetter<&method>::get()

DECLARE_CLASS_CODEGEN(RumbleMod::UI::ViewControllers, SettingsViewController,::HMUI::ViewController,
    DECLARE_INSTANCE_FIELD(HapticPresetSO *, hapticPresetSO);
    DECLARE_INSTANCE_FIELD(HapticFeedbackController *, hapticFeedbackController);

    DECLARE_INSTANCE_FIELD(TextMeshProUGUI *, noteEnabledText);
    DECLARE_INSTANCE_FIELD(SliderSetting *, noteSlider);
    DECLARE_INSTANCE_FIELD(Button *, noteButton);
    DECLARE_INSTANCE_FIELD(TextMeshProUGUI *, chainEnabledText);
    DECLARE_INSTANCE_FIELD(SliderSetting *, chainSlider);
    DECLARE_INSTANCE_FIELD(Button *, chainButton);
    DECLARE_INSTANCE_FIELD(TextMeshProUGUI *, arcEnabledText);
    DECLARE_INSTANCE_FIELD(SliderSetting *, arcSlider);
    DECLARE_INSTANCE_FIELD(Button *, arcButton);
    DECLARE_INSTANCE_FIELD(TextMeshProUGUI *, saberEnabledText);
    DECLARE_INSTANCE_FIELD(SliderSetting *, saberSlider);
    DECLARE_INSTANCE_FIELD(Button *, saberButton);
    DECLARE_INSTANCE_FIELD(TextMeshProUGUI *, wallEnabledText);
    DECLARE_INSTANCE_FIELD(SliderSetting *, wallSlider);
    DECLARE_INSTANCE_FIELD(Button *, wallButton);
    DECLARE_INSTANCE_FIELD(TextMeshProUGUI *, uiEnabledText);
    DECLARE_INSTANCE_FIELD(SliderSetting *, uiSlider);
    DECLARE_INSTANCE_FIELD(Button *, uiButton);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, GET_METHOD(::HMUI::ViewController::DidActivate),
                            bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

    DECLARE_INSTANCE_METHOD(void, TestRumble, float strength, float duration);
    DECLARE_INSTANCE_METHOD(void, TestNoteRumble);
    DECLARE_INSTANCE_METHOD(void, TestChainRumble);
    DECLARE_INSTANCE_METHOD(void, TestArcRumble);
    DECLARE_INSTANCE_METHOD(void, TestSaberRumble);
    DECLARE_INSTANCE_METHOD(void, TestWallRumble);
    DECLARE_INSTANCE_METHOD(void, TestUIRumble);

    DECLARE_INSTANCE_METHOD(void, RumbleEnableChange, bool value, TextMeshProUGUI *text, SliderSetting *slider,
                            Button *button);
    DECLARE_INSTANCE_METHOD(void, PostParse);

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

#undef HapticFeedbackController
#undef HapticPresetSO
#undef TextMeshProUGUI
#undef SliderSetting
#undef Button