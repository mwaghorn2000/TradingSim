#include "./Stock.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>

Stock::Stock() {
    std::srand(std::time(nullptr));
    currentPrice = 100.0;
    remainingTicks = 0;
    tickPriceChange = 0.0;
    goingDown = false;
    std::cout << "Stock initialized with price: " << currentPrice << std::endl;
}

void Stock::initializeNewPhase() {
    remainingTicks = 5 + std::rand() % 21; // n is a random number between 5 and 25
    goingDown = (std::rand() % 100) < 40; // 38% chance to go down

    double percentageChange;
    if (goingDown) {
        percentageChange = (10 + std::rand() % 41) / 100.0; // 10-50% change downwards
    } else {
        percentageChange = (25 + std::rand() % 25) / 100.0; // 25-50% change upwards
    }

    tickPriceChange = percentageChange * currentPrice;
    if (goingDown) {
        tickPriceChange = -tickPriceChange;
    }

    tickPriceChange = tickPriceChange / remainingTicks;

//    std::cout << "New phase initialized: " << (goingDown ? "downward" : "upward")
//              << " for " << remainingTicks << " ticks, "
//              << "total change: " << percentageChange * 100 << "%" << std::endl;
}

void Stock::updatePrice() {
    if (remainingTicks <= 0) {
        initializeNewPhase();
    }

    double fluctuation = ((std::rand() % 201) - 100) / 100.0; // Random fluctuation between -0.50 and +0.50

    double adjustedTickPriceChange = tickPriceChange * (1 + fluctuation);

    currentPrice += adjustedTickPriceChange;
    if (currentPrice < 0) {
        currentPrice = 0;
    }
    notifyObservers(adjustedTickPriceChange);
    remainingTicks--;
    //std::cout << "Stock price updated to: " << currentPrice
    //          << ", remaining ticks: " << remainingTicks << std::endl;
}

double Stock::getCurrentPrice() const {
    return currentPrice;
}

void Stock::registerObserver(StockObserver *observer) {
    this->observers.push_back(observer);
}

void Stock::removeObserver(StockObserver *observer) {
    this->observers.remove(observer);
}

void Stock::notifyObservers(double priceChange) {
    for (auto x : observers) {
        x->updatePrice(priceChange);
    }
}
