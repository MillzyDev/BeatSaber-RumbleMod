#include "UI/ViewControllers/SettingsViewController.hpp"
#include "Configuration/ModConfig.hpp"
#include "assets.hpp"

#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSML/Components/Settings/SliderSetting.hpp"

#include "UnityEngine/Color.hpp"
#include "UnityEngine/UI/Button.hpp"

#define DEFINE_BSML_PROPERTY(type, name, get, set)          \
type SettingsViewController::get_##name() get               \
void SettingsViewController::set_##name(type value) set

DEFINE_TYPE(RumbleMod::UI::ViewControllers, SettingsViewController);

using namespace BSML;
using namespace UnityEngine;
using namespace UnityEngine::UI;

namespace RumbleMod::UI::ViewControllers {
    void SettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
        if (!firstActivation) return;
        BSML::parse_and_construct(::IncludedAssets::SettingsView_bsml, get_transform(), this);
    }

    DEFINE_BSML_PROPERTY(bool, noteEnabled,
        { // get
            return getModConfig().noteEnabled.GetValue();
        },
        { // set
            getModConfig().noteEnabled.SetValue(value);
            noteEnabledText->set_color(value ? Color::get_green() : Color::get_red());

            noteInteractables->GetComponentInChildren<SliderSetting *>()->set_interactable(value);
            noteInteractables->GetComponentInChildren<Button *>()->set_interactable(value);
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
            chainEnabledText->set_color(value ? Color::get_green() : Color::get_red());

            chainInteractables->GetComponentInChildren<SliderSetting *>()->set_interactable(value);
            chainInteractables->GetComponentInChildren<Button *>()->set_interactable(value);
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
            arcEnabledText->set_color(value ? Color::get_green() : Color::get_red());

            arcInteractables->GetComponentInChildren<SliderSetting *>()->set_interactable(value);
            arcInteractables->GetComponentInChildren<Button *>()->set_interactable(value);
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
            saberEnabledText->set_color(value ? Color::get_green() : Color::get_red());

            saberInteractables->GetComponentInChildren<SliderSetting *>()->set_interactable(value);
            saberInteractables->GetComponentInChildren<Button *>()->set_interactable(value);
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
            wallEnabledText->set_color(value ? Color::get_green() : Color::get_red());

            wallInteractables->GetComponentInChildren<SliderSetting *>()->set_interactable(value);
            wallInteractables->GetComponentInChildren<Button *>()->set_interactable(value);
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
            uiEnabledText->set_color(value ? Color::get_green() : Color::get_red());

            uiInteractables->GetComponentInChildren<SliderSetting *>()->set_interactable(value);
            uiInteractables->GetComponentInChildren<Button *>()->set_interactable(value);
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