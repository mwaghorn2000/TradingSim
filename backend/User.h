//
// Created by mitch on 15/05/24.
//

#ifndef USER_H
#define USER_H
#include <list>
#include <map>

#include "Transaction.h"
#include "Wallet.h"


class User {
private:
    int id;
    Wallet wallet;
    std::map<int, Transaction> transactions;

public:
    explicit User(int id);
    [[nodiscard]] int get_id() const;
    void add_money(double amount) const;
    [[nodiscard]] int remove_money(double amount) const;
    std::list<Transaction> get_transactions();
    void addTransation(double bought_price);
    std::optional<Transaction>  get_transation(int id);
    [[nodiscard]] Wallet get_wallet() const;
};



#endif //USER_H
