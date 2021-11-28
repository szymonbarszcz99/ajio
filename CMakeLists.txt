cmake_minimum_required(VERSION 3.19)
project(ajio)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(PkgConfig)
find_package(Threads REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
include_directories(
        ${GLIB_INCLUDE_DIRS}
        ${GTKMM_INCLUDE_DIRS}
)
link_directories(
        ${GLIB_LIBRARY_DIRS}
        ${GTKMM_LIBRARY_DIRS}
)

add_executable(ajio main.cpp App.cpp App.h AppWindow.cpp AppWindow.h Writer.cpp Writer.h ViewStations.cpp ViewStations.h EventHandler.cpp EventHandler.h Validator.cpp Validator.h)

target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES} Threads::Threads)