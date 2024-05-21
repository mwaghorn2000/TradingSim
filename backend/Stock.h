//
// Created by geazy on 19/05/2024.
//

#ifndef STOCK_H
#define STOCK_H



class Stock {
public:
    Stock();
    void updatePrice();
    double getCurrentPrice() const;

private:
    double currentPrice;
    int remainingTicks;
    double tickPriceChange;
    bool goingDown;

    void initializeNewPhase();
};



#endif //STOCK_H
