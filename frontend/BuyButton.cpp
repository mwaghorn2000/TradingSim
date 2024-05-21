//
// Created by geazy on 14/05/2024.
//

#include "BuyButton.h"
#include <iostream>
#include "MainBoard.h"

BuyButton::BuyButton(User* user, MainBoard* mainBoard, QWidget *parent)
    : QPushButton("Buy", parent), user(user), mainBoard(mainBoard) {
    connect(this, &QPushButton::clicked, this, &BuyButton::onClick);
}

void BuyButton::onClick() {
    std::cout << "Buy button clicked" << std::endl;

    if (user->get_transactions().size() >= 5) {
        std::cout << "User cannot hold more than 5 stocks" << std::endl;
        return;
    }

    double currentPrice = mainBoard->getCurrentStockPrice();
    std::cout << "Current stock price: " << currentPrice << std::endl;
    user->addTransation(currentPrice);
    std::cout << "Stock bought at price: " << currentPrice << std::endl;
}
