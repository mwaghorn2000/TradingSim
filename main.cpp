#include <QApplication>
#include <QPushButton>
#include <iostream>  // Include this for std::cout

#include "MainBoard.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Print to console
    std::cout << "Hello World!" << std::endl;

    MainBoard board;
    board.resize(800, 600);
    board.show();

    return QApplication::exec();
}
