//
// Created by mitch on 19/05/24.
//

#include "Wallet.h"

Wallet::Wallet() {
    this->money = 1000.00;
}

double Wallet::get_money() const {
    return this->money;
}

void Wallet::add_money(const double amount) {
    if (amount <= 0) {
        return;
    }
    this->money += amount;
}

int Wallet::remove_money(const double amount) {
    if (amount <= 0) {
        return 1;
    }
    if (this->money - amount < 0) {
        return 1;
    }

    this->money -= amount;
    return 0;
}
