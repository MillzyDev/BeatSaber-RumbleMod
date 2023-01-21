#include "UI/ViewControllers/SettingsViewController.hpp"
#include "Configuration/ModConfig.hpp"
#include "assets.hpp"
#include "logging.hpp"

#include "bsml/shared/BSML.hpp"

#include "UnityEngine/Color.hpp"
#include "UnityEngine/Resources.hpp"
#include "UnityEngine/ScriptableObject.hpp"
#include "UnityEngine/XR/XRNode.hpp"
#include "VRUIControls/VRInputModule.hpp"

#define DEFINE_BSML_PROPERTY(type, name, get, set)          \
type SettingsViewController::get_##name() get               \
void SettingsViewController::set_##name(type value) set

#define CHANGED_RUMBLE_VALUE_ENABLED(value, text, slider, button) \
text->set_color((value) ? Color::get_green() : Color::get_red()); \
slider->set_interactable(value);                                  \
button->set_interactable(value);

DEFINE_TYPE(RumbleMod::UI::ViewControllers, SettingsViewController);

using namespace BSML;
using namespace Libraries::HM::HMLib::VR;
using namespace UnityEngine;
using namespace UnityEngine::UI;
using namespace UnityEngine::XR;
using namespace VRUIControls;

namespace RumbleMod::UI::ViewControllers {
    void SettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
        if (!firstActivation) return;
        BSML::parse_and_construct(::IncludedAssets::SettingsView_bsml, get_transform(), this);
        hapticPresetSO = ScriptableObject::CreateInstance<HapticPresetSO *>();
    }

    void SettingsViewController::TestRumble(float strength, float duration) {
        if (!hapticFeedbackController) {
            ArrayW<VRInputModule *> vrInputModules = Resources::FindObjectsOfTypeAll<VRInputModule *>();
            VRInputModule *vrInputModule = vrInputModules.FirstOrDefault();
            if (vrInputModule)
                hapticFeedbackController = vrInputModule->hapticFeedbackController;
        }

        if (hapticFeedbackController) {
            hapticPresetSO->strength = strength;
            hapticPresetSO->duration = duration;
            hapticFeedbackController->PlayHapticFeedback(XRNode::LeftHand, hapticPresetSO);
            hapticFeedbackController->PlayHapticFeedback(XRNode::RightHand, hapticPresetSO);
        }
        else {
            ERROR("Error getting HapticFeedbackController");
        }
    }

    void SettingsViewController::TestNoteRumble() {
        TestRumble(getModConfig().noteStrength.GetValue(), 1.0f);
    }

    void SettingsViewController::TestChainRumble() {
        TestRumble(getModConfig().chainStrength.GetValue(), 0.2f);
    }

    void SettingsViewController::TestArcRumble() {
        TestRumble(getModConfig().arcStrength.GetValue(), 1.0f);
    }

    void SettingsViewController::TestSaberRumble() {
        TestRumble(getModConfig().saberStrength.GetValue(), 1.0f);
    }

    void SettingsViewController::TestWallRumble() {
        TestRumble(getModConfig().wallStrength.GetValue(), 1.0f);
    }

    void SettingsViewController::TestUIRumble() {
        TestRumble(getModConfig().uiStrength.GetValue(), 0.02f);
    }

    DEFINE_BSML_PROPERTY(bool, noteEnabled,
        { // get
            return getModConfig().noteEnabled.GetValue();
        },
        { // set
            getModConfig().noteEnabled.SetValue(value);
            CHANGED_RUMBLE_VALUE_ENABLED(value, noteEnabledText, noteSlider, noteButton)
        }
    )

    DEFINE_BSML_PROPERTY(float, noteStrength,
        { // get
            return getModConfig().noteStrength.GetValue();
        },
        { // set
            getModConfig().noteStrength.SetValue(value);
        }
    )

    DEFINE_BSML_PROPERTY(bool, chainEnabled,
        { // get
            return getModConfig().chainEnabled.GetValue();
        },
        { // set
            getModConfig().chainEnabled.SetValue(value);
            CHANGED_RUMBLE_VALUE_ENABLED(value, chainEnabledText, chainSlider, chainButton)
        }
    )

    DEFINE_BSML_PROPERTY(float, chainStrength,
        { // get
            return getModConfig().chainStrength.GetValue();
        },
        { // set
            getModConfig().chainStrength.SetValue(value);
        }
    )

    DEFINE_BSML_PROPERTY(bool, arcEnabled,
        { // get
            return getModConfig().arcEnabled.GetValue();
        },
        { // set
            getModConfig().arcEnabled.SetValue(value);
            CHANGED_RUMBLE_VALUE_ENABLED(value, arcEnabledText, arcSlider, arcButton)
        }
    )

    DEFINE_BSML_PROPERTY(float, arcStrength,
        { // get
            return getModConfig().arcStrength.GetValue();
        },
        { // set
            getModConfig().arcStrength.SetValue(value);
        }
    )

    DEFINE_BSML_PROPERTY(bool, saberEnabled,
        { // get
            return getModConfig().saberEnabled.GetValue();
        },
        { // set
            getModConfig().saberEnabled.SetValue(value);
            CHANGED_RUMBLE_VALUE_ENABLED(value, saberEnabledText, saberSlider, saberButton)
        }
    )

    DEFINE_BSML_PROPERTY(float, saberStrength,
        { // get
            return getModConfig().saberStrength.GetValue();
        },
        { // set
            getModConfig().saberStrength.SetValue(value);
        }
    )

    DEFINE_BSML_PROPERTY(bool, wallEnabled,
        { // get
            return getModConfig().wallEnabled.GetValue();
        },
        { // set
            getModConfig().wallEnabled.SetValue(value);
            CHANGED_RUMBLE_VALUE_ENABLED(value, wallEnabledText, wallSlider, wallButton)
        }
    )

    DEFINE_BSML_PROPERTY(float, wallStrength,
        { // get
            return getModConfig().wallStrength.GetValue();
        },
        { // set
            getModConfig().wallStrength.SetValue(value);
        }
    )

    DEFINE_BSML_PROPERTY(bool, uiEnabled,
        { // get
            return getModConfig().uiEnabled.GetValue();
        },
        { // set
            getModConfig().uiEnabled.SetValue(value);
            CHANGED_RUMBLE_VALUE_ENABLED(value, uiEnabledText, uiSlider, uiButton)
        }
    )

    DEFINE_BSML_PROPERTY(float, uiStrength,
        { // get
            return getModConfig().uiStrength.GetValue();
        },
        { // set
            getModConfig().uiStrength.SetValue(value);
        }
    )
}