//
// Created by geazy on 14/05/2024.
//

#include "BuyButton.h"
#include <iostream>

BuyButton::BuyButton(QWidget *parent) : QPushButton("Buy", parent) {
    connect(this, &QPushButton::clicked, this, &BuyButton::onClick);
}

void BuyButton::onClick() {
    std::cout << "Buy button clicked" << std::endl;
}


