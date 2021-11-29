#include <gtkmm/messagedialog.h>
#include "AppWindow.h"

AppWindow::AppWindow(std::shared_ptr<EventHandler> eventHandler){
    this->eventHandler = eventHandler;
    this->set_title("Radio");

    this->add(this->box);
    this->box.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->box.set_spacing(10);
    this->box.property_margin() = 10;

    this->nameLabel = Gtk::Label("Name");
    this->nameEntry = Gtk::Entry();
    this->box.add(this->nameLabel);
    this->box.add(this->nameEntry);

    this->linkLabel = Gtk::Label("Link");
    this->linkEntry = Gtk::Entry();
    this->box.add(this->linkLabel);
    this->box.add(this->linkEntry);

    this->pathLabel = Gtk::Label("Path to logo");
    this->pathEntry = Gtk::Entry();
    this->box.add(this->pathLabel);
    this->box.add(this->pathEntry);

    this->addButton = Gtk::Button("Dodaj");
    this->addButton.signal_clicked().connect(sigc::mem_fun(*this,&AppWindow::addClicked));
    this->deleteButton = Gtk::Button("Usuń ostatni wpis");
    this->deleteButton.signal_clicked().connect(sigc::mem_fun(*this,&AppWindow::deleteClicked));
    this->viewButton = Gtk::Button("Zobacz wszystkie");
    this->viewButton.signal_clicked().connect(sigc::mem_fun(*this,&AppWindow::viewClicked));
    this->box.add(this->addButton);
    this->box.add(this->deleteButton);
    this->box.add(this->viewButton);

    this->box.show_all();
}

void AppWindow::addClicked() {
    std::cout<<"Add clicked"<<std::endl;
    errorCode returnCode = this->eventHandler->addEvent(this->nameEntry.get_text(),
                                 this->linkEntry.get_text(),
                                 this->pathEntry.get_text());
    switch(returnCode){
        case NAME:
            this->throwModal("name");
            break;
        case LINK:
            this->throwModal("link");
            break;
        case PATH:
            this->throwModal("path");
            break;
    }
    this->nameEntry.set_text("");
    this->linkEntry.set_text("");
    this->pathEntry.set_text("");
}

void AppWindow::deleteClicked() {
    std::cout<<"Delete clicked"<<std::endl;
    this->eventHandler->deleteEvent();
}

void AppWindow::viewClicked() {
    std::cout<<"View clicked"<<std::endl;
    this->eventHandler->viewEvent();
}

void AppWindow::throwModal(std::string errorString) {
    Gtk::MessageDialog error("Wrong " + errorString);
    error.run();
}
