#include "UI/Controllers/SettingsController.hpp"

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
__PROPERTY_DEFINITION(SettingsController, valueType, valueName, getModConfig(), configName, setFunc)

DEFINE_TYPE(RumbleMod::UI::Controllers, SettingsController)

namespace RumbleMod::UI::Controllers {
    SafePtr<SettingsController> SettingsController::instance;

    SettingsController *SettingsController::get_instance() {
        if (!instance)
            instance = SettingsController::New_ctor();

        return instance.ptr();
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

BSML_DATACACHE(settings) {
    return IncludedAssets::SettingsView_bsml;
}