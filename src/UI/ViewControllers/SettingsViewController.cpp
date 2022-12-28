#include "UI/ViewControllers/SettingsViewController.hpp"

#include "Configuration/ModConfig.hpp"

#include "assets.hpp"

#include "bsml/shared/BSML.hpp"

#define __PROPERTY_DEFINITION(klass, valueType, valueName, config, configName, setFunc) \
valueType klass::get_##valueName() {                                                    \
    return config.configName.GetValue();                                                \
}                                                                                       \
                                                                                        \
void klass::set_##valueName(valueType value) {                                          \
    config.configName.SetValue(value);                                                  \
    setFunc                                                                             \
}

#define PROPERTY_DEFINITION(valueType, valueName, configName, setFunc) \
__PROPERTY_DEFINITION(SettingsViewController, valueType, valueName, getModConfig(), configName, setFunc)

DEFINE_TYPE(RumbleMod::UI::ViewControllers, SettingsViewController)

namespace RumbleMod::UI::ViewControllers {
    void SettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
        if (firstActivation)
            BSML::parse_and_construct(IncludedAssets::SettingsView_bsml, get_transform(), this);
    }

#pragma region UI Values
    PROPERTY_DEFINITION(bool, ModEnabled, enabled,)
    PROPERTY_DEFINITION(float, NoteStrength, noteStrength,)
    PROPERTY_DEFINITION(float, ChainStrength, chainStrength,)
    PROPERTY_DEFINITION(float, ArcStrength, arcStrength,)
    PROPERTY_DEFINITION(float, SaberStrength, saberStrength,)
    PROPERTY_DEFINITION(float, WallStrength, wallStrength,)
    PROPERTY_DEFINITION(float, UIStrength, uiStrength,)
#pragma endregion
}