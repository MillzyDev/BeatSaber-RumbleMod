#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(enabled, bool, "enabled", false);

    CONFIG_VALUE(noteStrength, float, "noteStrength", 1.0f);
    CONFIG_VALUE(chainStrength, float, "chainStrength", 1.0f);
    CONFIG_VALUE(arcStrength, float, "arcStrength", 1.0f);
    CONFIG_VALUE(saberStrength, float, "saberStrength", 1.0f);
    CONFIG_VALUE(wallStrength, float, "wallStrength", 1.0f);
    CONFIG_VALUE(uiStrength, float, "uiStrength", 1.0f);
)