#include "App.h"

int main() {
    auto writer = std::make_shared<Writer>();
    std::shared_ptr<ViewStations> viewStations;
    auto eventHandler = std::make_shared<EventHandler>(writer,viewStations);

    auto app = App::create(eventHandler);
    return app->run();
}
