#include <QApplication>
#include <QPushButton>
#include <iostream>  // Include this for std::cout

#include "frontend/MainBoard.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Print to console
    std::cout << "Hello World!" << std::endl;

    MainBoard board;
    board.resize(900, 600);
    board.show();

    return QApplication::exec();
}
