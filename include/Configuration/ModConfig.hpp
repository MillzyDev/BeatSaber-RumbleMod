#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(noteEnabled, bool, "noteEnabled", false);
    CONFIG_VALUE(noteStrength, float, "noteStrength", 1.0f);
    CONFIG_VALUE(chainEnabled, bool, "chainEnabled", false);
    CONFIG_VALUE(chainStrength, float, "chainStrength", 1.0f);
    CONFIG_VALUE(arcEnabled, bool, "arcEnabled", false);
    CONFIG_VALUE(arcStrength, float, "arcStrength", 1.0f);
    CONFIG_VALUE(saberEnabled, bool, "saberEnabled", false);
    CONFIG_VALUE(saberStrength, float, "saberStrength", 1.0f);
    CONFIG_VALUE(wallEnabled, bool, "wallEnabled", false);
    CONFIG_VALUE(wallStrength, float, "wallStrength", 1.0f);
    CONFIG_VALUE(uiEnabled, bool, "uiEnabled", false);
    CONFIG_VALUE(uiStrength, float, "uiStrength", 1.0f);
)