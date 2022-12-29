#include "main.hpp"
#include "hooks.hpp"

#include "ModloaderUtils.hpp"

#include "Configuration/ModConfig.hpp"

#include "UI/Controllers/SettingsController.hpp"

#include "custom-types/shared/register.hpp"

#include "bsml/shared/BSML.hpp"

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static auto* logger = new Logger(modInfo);
    return *logger;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;

    ModConfig_t::Init(modInfo);
    getLogger().info("Completed setup!");
}

bool tooManyTweaks;

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();
    ::BSML::Init();

    ::custom_types::Register::AutoRegister();

    tooManyTweaks = RumbleMod::ModloaderUtils::modIsInstalled("toomanytweaks");

    getLogger().info("Installing hooks...");
    Hooks::InstallHooks(getLogger());
    getLogger().info("Installed all hooks!");

    ::BSML::Register::RegisterSettingsMenu("RumbleMod", MOD_ID "_settings",
                                           ::RumbleMod::UI::Controllers::SettingsController::get_instance(),
                                           false);
}