//
// Created by Mitchell Waghorn on 22/5/2024.
//

#ifndef STOCKSUBSCRIBER_H
#define STOCKSUBSCRIBER_H

class StockObserver;

class StockSubscriber {
public:
    virtual void registerObserver(StockObserver* observer) = 0;
    virtual void removeObserver(StockObserver* observer) = 0;
    virtual void notifyObservers(double priceChange) = 0;
    virtual ~StockSubscriber() = default;
};


#endif //STOCKSUBSCRIBER_H
