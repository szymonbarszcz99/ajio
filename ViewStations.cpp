#include "ViewStations.h"

ViewStations::ViewStations() {
    std::cout<<"ViewStations constructor"<<std::endl;
    this->grid = Gtk::Grid();
    this->grid.set_row_spacing(10);
    this->grid.set_column_spacing(10);
    this->grid.property_margin() = 10;
    this->add(grid);
    this->set_title("Dodane stacje");
    this->signal_hide().connect(sigc::mem_fun(*this,&ViewStations::onHide));
}

void ViewStations::populate(std::shared_ptr<Gtk::Widget> widget, int left, int top) {
    labelsToShow.push_back(widget);
    this->grid.attach(*widget,left,top);
    this->grid.show_all();
}

void ViewStations::onHide() {
    this->labelsToShow.clear();
}
