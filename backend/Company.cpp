//
// Created by mitch on 19/05/24.
//

#include "Company.h"

#include "Company.h"


Company::Company(const std::string& id, const Stock& stock) : id(id), stock(stock) {}

Stock& Company::getStock() {
    return stock;
}

const Stock& Company::getStock() const {
    return stock;
}
