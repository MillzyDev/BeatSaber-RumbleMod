#include "main.hpp"
#include "hooking.hpp"
#include "logging.hpp"
#include "Configuration/ModConfig.hpp"

#include "custom-types/shared/register.hpp"
#include "lapiz/shared/zenject/Zenjector.hpp"
#include "lapiz/shared/AttributeRegistration.hpp"
#include "bsml/shared/BSML.hpp"

#include "Installers/MenuInstaller.hpp"

static ModInfo modInfo {MOD_ID, VERSION};

extern "C" void setup(ModInfo& info) {
    modInfo = info;
}
bool tooManyTweaks;

extern "C" void load() {
    ModConfig_t::Init(modInfo);

    ::il2cpp_functions::Init();
    ::BSML::Init();
    ::custom_types::Register::AutoRegister();
    ::Lapiz::Attributes::AutoRegister();

    // false if toomanytweaks is not installed/cannot be loaded
    auto mods = ::Modloader::getMods();
    tooManyTweaks = mods.find("toomanytweaks") != mods.end();

    Hooks::InstallHooks(getLogger());

    auto zenjector = ::Lapiz::Zenject::Zenjector::Get();
    zenjector->Install<::RumbleMod::Installers::MenuInstaller *>(::Lapiz::Zenject::Location::Menu);
}