#ifndef AJIO_APP_H
#define AJIO_APP_H
#include <gtkmm/application.h>
#include "AppWindow.h"

class App : public Gtk::Application{
    std::unique_ptr<AppWindow> appWindow;
    void onHideWindow();
    void on_activate() override;
    std::shared_ptr<EventHandler> eventHandler;
public:
    App(std::shared_ptr<EventHandler> eventHandler):
    Gtk::Application("org.ajio"),eventHandler(eventHandler){};
    static Glib::RefPtr<App> create(std::shared_ptr<EventHandler> eventHandler);
    ~App(){
        std::cout<<"App destructor"<<std::endl;
    }
};


#endif //AJIO_APP_H
