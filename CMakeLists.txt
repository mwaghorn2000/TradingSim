

cmake_minimum_required(VERSION 3.28)
project(TradingSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

cmake_minimum_required(VERSION 3.28)
project(TradingSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(DEFINED ENV{QT_DIR})
    set(CMAKE_PREFIX_PATH $ENV{QT_DIR})
endif()

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Charts
        REQUIRED)

add_executable(TradingSim main.cpp
        ButtonInterface.cpp
        ButtonInterface.h
        BuyButton.cpp
        BuyButton.h
        SellButton.cpp
        SellButton.h
        MainBoard.cpp
        MainBoard.h
        MainBoard.cpp)
target_link_libraries(TradingSim
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Charts
)

