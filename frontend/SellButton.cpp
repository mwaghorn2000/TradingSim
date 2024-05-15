//
// Created by geazy on 14/05/2024.
//

#include "SellButton.h"
#include <iostream>

SellButton::SellButton(QWidget *parent) : QPushButton("Sell", parent) {
    connect(this, &QPushButton::clicked, this, &SellButton::onClick);
}

void SellButton::onClick() {
    std::cout << "Sell button clicked" << std::endl;
}


