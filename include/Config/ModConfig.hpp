#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
        CONFIG_VALUE(enabled, bool, "Enable RumbleMod", false);
        CONFIG_VALUE(strength, float, "Note Strength", 1.0f);
        CONFIG_VALUE(duration, float, "Note Duration", 0.15f);
        CONFIG_VALUE(strength_saber, float, "Saber Strength", 1.0f);
        CONFIG_VALUE(strength_wall, float, "Wall Strength", 1.0f);
        CONFIG_VALUE(strength_ui, float, "UI Strength", 1.0f);

        CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(enabled);
        CONFIG_INIT_VALUE(strength);
        CONFIG_INIT_VALUE(duration);
        CONFIG_INIT_VALUE(strength_saber);
        CONFIG_INIT_VALUE(strength_wall);
        CONFIG_INIT_VALUE(strength_ui);
                )
               )