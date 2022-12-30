#include "UI/ViewControllers/SettingsViewController.hpp"
#include "Configuration/ModConfig.hpp"
#include "assets.hpp"

#include "bsml/shared/BSML.hpp"

DEFINE_TYPE(RumbleMod::UI::ViewControllers, SettingsViewController);

namespace RumbleMod::UI::ViewControllers {
    void SettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
        if (!firstActivation) return;
        BSML::parse_and_construct(::IncludedAssets::SettingsView_bsml, get_transform(), this);
    }
}