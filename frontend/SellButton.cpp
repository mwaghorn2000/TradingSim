//
// Created by geazy on 14/05/2024.
//

#include "SellButton.h"
#include <iostream>

SellButton::SellButton(User* user, MainBoard* mainBoard, QWidget *parent)
    : QPushButton("Sell", parent), user(user), mainBoard(mainBoard) {
    connect(this, &QPushButton::clicked, this, &SellButton::onClick);
}

void SellButton::onClick() {
    std::cout << "Sell button clicked" << std::endl;

    if (user->get_transactions().empty()) {
        std::cout << "No stocks to sell" << std::endl;
        return;
    }

    double currentPrice = mainBoard->getCurrentStockPrice();
    user->removeTransaction();

    std::cout << "Stock sold at price: " << currentPrice << std::endl;
    std::cout << "Stocks remaining: " << user->get_transactions().size() << std::endl;
}
