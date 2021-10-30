#pragma once

#include "main.hpp"

#include "custom-types/shared/macros.hpp"

#include "HMUI/ViewController.hpp"
using namespace HMUI;

#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

#include "UnityEngine/UI/VerticalLayoutGroup.hpp"
#include "UnityEngine/UI/HorizontalLayoutGroup.hpp"
#include "UnityEngine/UI/Button.hpp"
#include "UnityEngine/UI/Toggle.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"
using namespace UnityEngine::UI;

#include "questui/shared/CustomTypes/Components/Settings/SliderSetting.hpp"
using namespace QuestUI;

#include "TMPro/TextMeshProUGUI.hpp"
using namespace TMPro;

#include "GlobalNamespace/HapticFeedbackController.hpp"
using namespace GlobalNamespace;

#include "Libraries/HM/HMLib/VR/HapticPresetSO.hpp"
using namespace Libraries::HM::HMLib::VR;

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(RumbleMod::UI::ViewControllers, RumbleModSettingsViewController, ViewController,
    DECLARE_INSTANCE_FIELD(VerticalLayoutGroup*, layout);
    DECLARE_INSTANCE_FIELD(HorizontalLayoutGroup*, horizontal);
    DECLARE_INSTANCE_FIELD(Button*, button);
    DECLARE_STATIC_FIELD(Toggle*, toggle);
    DECLARE_INSTANCE_FIELD(HorizontalLayoutGroup*, horizontalChild);
    DECLARE_INSTANCE_FIELD(TextMeshProUGUI*, text);
    DECLARE_INSTANCE_FIELD(LayoutElement*, layoutElement);
    DECLARE_STATIC_FIELD(SliderSetting*, strengthSlider);
    DECLARE_STATIC_FIELD(SliderSetting*, durationSlider);
    DECLARE_STATIC_FIELD(SliderSetting*, saberSlider);
    DECLARE_STATIC_FIELD(SliderSetting*, wallSlider);
    DECLARE_STATIC_FIELD(SliderSetting*, uiSlider);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, GET_FIND_METHOD(&ViewController::DidActivate), bool firstActivation, bool addedToHeirarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD(void, DidDeactivate, GET_FIND_METHOD(&ViewController::DidDeactivate), bool removedFromHeirarchy, bool screenSystemDisabling);
    DECLARE_CTOR(ctor);
    // All the rumble majik :>

    DECLARE_STATIC_FIELD(HapticFeedbackController*, hapticFeedbackController);
    DECLARE_STATIC_FIELD(HapticPresetSO*, rumblePreset);

    DECLARE_STATIC_METHOD(void, OnDefaultClick);
    DECLARE_STATIC_METHOD(void, OnRecommendedClick);

    DECLARE_STATIC_METHOD(void, OnRumbleNoteClick);
    DECLARE_STATIC_METHOD(void, OnRumbleSaberClick);
    DECLARE_STATIC_METHOD(void, OnRumbleWallClick);
    DECLARE_STATIC_METHOD(void, OnRumbleUIClick);

    DECLARE_STATIC_METHOD(void, RumbleTest, float strength, float duration);
)