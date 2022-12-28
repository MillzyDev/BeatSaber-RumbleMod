#include "custom-types/shared/macros.hpp"
#include "Zenject/Installer.hpp"

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(RumbleMod::Installers, MenuInstaller, ::Zenject::Installer,
    DECLARE_DEFAULT_CTOR();
    DECLARE_OVERRIDE_METHOD(void, InstallBindings, GET_FIND_METHOD(&::Zenject::Installer::InstallBindings));
)