cmake_minimum_required(VERSION 3.28)
project(TradingSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/mitchellwaghorn/Qt/6.7.0/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(TradingSim main.cpp)
target_link_libraries(TradingSim
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

