//
// Created by geazy on 19/05/2024.
//

#ifndef STOCK_H
#define STOCK_H

#include <list>

#include "StockObserver.h"
#include "StockSubscriber.h"

class Stock : public StockSubscriber {
public:
    Stock();
    void updatePrice();
    [[nodiscard]] double getCurrentPrice() const;
    void registerObserver(StockObserver* observer) override;
    void removeObserver(StockObserver* observer) override;
    void notifyObservers(double priceChange) override;

private:
    double currentPrice;
    int remainingTicks;
    double tickPriceChange;
    bool goingDown;
    void initializeNewPhase();
    std::list<StockObserver*> observers;
};



#endif //STOCK_H
