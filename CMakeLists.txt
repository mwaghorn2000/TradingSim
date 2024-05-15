

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
else ()
    set(CMAKE_PREFIX_PATH "/home/mitch/Qt/6.7.0/gcc_64/lib/cmake")
endif ()

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Charts
        PrintSupport
        REQUIRED)

add_executable(TradingSim main.cpp
        frontend/ButtonInterface.cpp
        frontend/ButtonInterface.h
        frontend/BuyButton.cpp
        frontend/BuyButton.h
        frontend/SellButton.cpp
        frontend/SellButton.h
        frontend/MainBoard.cpp
        frontend/MainBoard.h
        frontend/MainBoard.cpp
        backend/User.cpp
        backend/User.h
        lib/qcustomplot/qcustomplot.cpp
        lib/qcustomplot/qcustomplot.h
        frontend/StockChart.cpp
        frontend/StockChart.h
)
target_link_libraries(TradingSim
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Charts
        Qt6::PrintSupport
)

