#include "Installers/MenuInstaller.hpp"

#include "Zenject/DiContainer.hpp"

DEFINE_TYPE(::RumbleMod::Installers, MenuInstaller)

namespace RumbleMod::Installers {
    void MenuInstaller::InstallBindings() {
        Zenject::DiContainer *container = get_Container();

        // Bind the things
    }
}