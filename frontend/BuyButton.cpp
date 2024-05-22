//
// Created by geazy on 14/05/2024.
//

#include "BuyButton.h"
#include <iostream>
#include "MainBoard.h"

BuyButton::BuyButton(User* user, MainBoard* mainBoard, GameController* gameController, QWidget *parent)
    : QPushButton("Buy", parent), user(user), gameController(gameController), mainBoard(mainBoard) {
    connect(this, &QPushButton::clicked, this, &BuyButton::onClick);
}

void BuyButton::onClick() {
    std::cout << "Buy button clicked" << std::endl;

    if (!this->gameController->purchase_stock()) {
        double currentPrice = mainBoard->getCurrentStockPrice();
        std::cout << "Current stock price: " << currentPrice << std::endl;
        user->addTransaction(currentPrice);
        std::cout << "Stock bought at price: " << currentPrice << std::endl;
    } else {
        std::cout << "Failed purchase\n";
    }
}