#include "Installers/MenuInstaller.hpp"

#include "lapiz/shared/utilities/ZenjectExtensions.hpp"

#include "Zenject/DiContainer.hpp"
#include "Zenject/ConcreteIdBinderGeneric_1.hpp"
#include "Zenject/FromBinderNonGeneric.hpp"

#include "UI/SettingsUI.hpp"
#include "UI/FlowCoordinators/SettingsFlowCoordinator.hpp"
#include "UI/ViewControllers/SettingsViewController.hpp"

DEFINE_TYPE(RumbleMod::Installers, MenuInstaller);

using namespace Lapiz::Zenject::ZenjectExtensions;

namespace RumbleMod::Installers {
    void MenuInstaller::InstallBindings() {
        auto container = get_Container();

        FromNewComponentAsViewController(
                container->Bind<::RumbleMod::UI::ViewControllers::SettingsViewController *>())->AsSingle();

        container->BindInterfacesAndSelfTo<::RumbleMod::UI::SettingsUI *>()->AsSingle();

        FromNewComponentOnNewGameObject(
                container->BindInterfacesAndSelfTo<::RumbleMod::UI::FlowCoordinators::SettingsFlowCoordinator *>()
                )->AsSingle();
    }
}