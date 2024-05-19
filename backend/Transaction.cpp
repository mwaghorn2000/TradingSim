//
// Created by mitch on 19/05/24.
//

#include "Transaction.h"

#include <ctime>

Transaction::Transaction(int const id, double const bought_price) {
    this->id = id;
    this->active = true;
    this->bought_price = bought_price;
    this->open_time = time(nullptr);
}

double Transaction::get_bought_price() const {
    return this->bought_price;
}

double Transaction::get_sold_price() const {
    return this->sold_price;
}

void Transaction::set_sold_price(double const sold_price) {
    this->sold_price = sold_price;
    this->close_time = time(nullptr);
}



