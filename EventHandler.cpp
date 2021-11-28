#include "EventHandler.h"

void EventHandler::deleteEvent() {
    std::cout<<"Delete Event"<<std::endl;
    //auto sp = this->writer.lock();
    //sp->deleteLast();
    this->writer->deleteLast();
}

void EventHandler::viewEvent() {
    //if(this->viewStations.expired())std::cout<<"Expired"<<std::endl;

    //auto wsp = this->writer.lock();
    //auto vsp = this->viewStations.lock();

    const auto& vector = this->writer->getVector();

    int top = 0;
    for(auto it: vector){
        std::shared_ptr<Gtk::Label> name = std::make_shared<Gtk::Label>(std::get<0>(it));
        std::shared_ptr<Gtk::Label> link = std::make_shared<Gtk::Label>(std::get<1>(it));
        std::shared_ptr<Gtk::Label> path = std::make_shared<Gtk::Label>(std::get<2>(it));

        this->viewStations->populate(name,0,top);
        this->viewStations->populate(link,1,top);
        this->viewStations->populate(path,2,top);

        top++;
    }
    this->viewStations->present();
}

std::shared_ptr<ViewStations>& EventHandler::getViewStations() {
    return this->viewStations;
}

errorCode EventHandler::addEvent(std::string name, std::string link, std::string path) {
    this->validator = std::make_shared<Validator>();
    if(!this->validator->validate(name)) return NAME;

    if(!this->validator->validate(link)) return LINK;

    if(!this->validator->validate(path)) return PATH;

    std::cout<<"Strings are now"<<std::endl<<name<<std::endl<<link<<std::endl<<path<<std::endl;

    this->writer->add(name,link,path);
}
