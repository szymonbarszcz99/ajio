#ifndef AJIO_APPWINDOW_H
#define AJIO_APPWINDOW_H
#include <gtkmm/applicationwindow.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <iostream>
#include "Writer.h"
#include "ViewStations.h"
#include "EventHandler.h"

class AppWindow : public Gtk::ApplicationWindow{
    Gtk::Entry nameEntry, linkEntry, pathEntry;
    Gtk::Label nameLabel, linkLabel, pathLabel;
    Gtk::Button addButton, deleteButton, viewButton;
    Gtk::Box box;
    void onAddClicked();
    void onDeleteClicked();
    void onViewClicked();
    std::shared_ptr<EventHandler> eventHandler;
    void throwModal(std::string errorString);

public:
    AppWindow(std::shared_ptr<EventHandler> eventHandler);
    ~AppWindow(){
        std::cout<<"AppWindow destructor"<<std::endl;
    }
};


#endif //AJIO_APPWINDOW_H
