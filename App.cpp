#include "App.h"

void App::onHideWindow() {
    this->appWindow->hide();
}

void App::on_activate() {
    std::cout<<"Activate"<<std::endl;
    this->appWindow = std::make_unique<AppWindow>(this->eventHandler);
    add_window(*this->appWindow);
    this->appWindow->present();

    this->eventHandler->getViewStations() = std::make_shared<ViewStations>();
}

Glib::RefPtr<App> App::create(std::shared_ptr<EventHandler> eventHandler) {
    return Glib::RefPtr<App>(new App(eventHandler));
}
