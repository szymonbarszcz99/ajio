#ifndef AJIO_VIEWSTATIONS_H
#define AJIO_VIEWSTATIONS_H
#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <iostream>

class ViewStations : public Gtk::Window{
    Gtk::Grid grid;
    std::vector<std::shared_ptr<Gtk::Widget>> labelsToShow;
    void onHide();
public:
    ViewStations();
    ~ViewStations(){
        std::cout<<"ViewStations destructor"<<std::endl;
    }
    void populate(std::shared_ptr<Gtk::Widget> widget, int left, int top);
};


#endif //AJIO_VIEWSTATIONS_H
