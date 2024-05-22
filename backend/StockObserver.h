//
// Created by Mitchell Waghorn on 22/5/2024.
//

#ifndef STOCKOBSERVER_H
#define STOCKOBSERVER_H

class StockObserver {
public:
    virtual void updatePrice(double price) = 0;
    virtual ~StockObserver() = default;
};


#endif //STOCKOBSERVER_H
