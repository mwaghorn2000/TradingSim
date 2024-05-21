//
// Created by mitch on 15/05/24.
//

#include "User.h"

#include <iostream>

User::User(int const id) {
    this->id = id;
    this->wallet = Wallet();
}

int User::get_id() const {
    return this->id;
}

void User::add_money(double const amount) const {
    this->get_wallet().add_money(amount);
}

void User::remove_money(double const amount) const {
    this->get_wallet().remove_money(amount);
}

std::list<Transaction> User::get_transactions() {
    std::list<Transaction> new_transactions;
    for (auto const& [key, val] : this->transactions) {
        new_transactions.push_back(val);
    }

    return new_transactions;
}

void User::addTransation(double const bought_price) {
    std::cout << "Adding transaction with price: " << bought_price << std::endl;
    int const id = transactions.size() + 1;
    auto t = Transaction(id, bought_price);
    this->transactions.insert({id, t});
    std::cout << "Transaction added. Total transactions: " << transactions.size() << std::endl;
}

void User::removeTransaction() {
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        transactions.erase(it);
        std::cout << "Transaction removed. Total transactions: " << transactions.size() << std::endl;
        return;
    }
    std::cout << "Transaction not performed because you have no stocks" << std::endl;
}

std::optional<Transaction> User::get_transation(int id) {
    auto it = this->transactions.find(id);
    if (it != this->transactions.end()) {
        return it->second;
    } else {
        return std::nullopt;
    }
}

Wallet User::get_wallet() const {
    return this->wallet;
}





