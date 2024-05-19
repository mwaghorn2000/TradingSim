//
// Created by mitch on 19/05/24.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <qnamespace.h>


class Transaction {
private:
    int id{};
    bool active;
    double bought_price;
    double sold_price{};
    time_t open_time;
    time_t close_time{};

public:
    explicit Transaction(int id, double bought_price);
    [[nodiscard]] double get_bought_price() const;
    void set_sold_price(double sold_price);
    [[nodiscard]] double get_sold_price() const;
};

#endif //TRANSACTION_H
