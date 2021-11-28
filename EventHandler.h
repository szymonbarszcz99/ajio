#ifndef AJIO_EVENTHANDLER_H
#define AJIO_EVENTHANDLER_H
#include "Writer.h"
#include "ViewStations.h"
#include "Validator.h"
#include <gtkmm/label.h>

enum errorCode{
    NAME,
    LINK,
    PATH
};

class EventHandler {
    std::shared_ptr<ViewStations> viewStations;
    std::shared_ptr<Writer> writer;
    std::shared_ptr<Validator> validator;
public:
    EventHandler(std::shared_ptr<Writer> writer, std::shared_ptr<ViewStations> viewStations):
    viewStations(viewStations), writer(writer){}
    errorCode addEvent(std::string name, std::string link, std::string path);
    void deleteEvent();
    void viewEvent();
    std::shared_ptr<ViewStations>& getViewStations();
    ~EventHandler(){
        std::cout<<"EventHandler destructor"<<std::endl;
    }
};


#endif //AJIO_EVENTHANDLER_H
