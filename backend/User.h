//
// Created by mitch on 15/05/24.
//

#ifndef USER_H
#define USER_H
#include <list>
#include <map>

#include "Transaction.h"
#include "Wallet.h"
#include "Company.h"
#include "StockObserver.h"

class User : public StockObserver {
private:
    int id;
    Wallet wallet;
    std::map<int, Transaction> transactions;

public:
    explicit User(int id);
    [[nodiscard]] int get_id() const;
    void add_money(double amount) const;
    void remove_money(double amount) const;
    std::list<Transaction> get_transactions();
    void addTransaction(double bought_price);
    void removeTransaction();
    std::optional<Transaction> get_transaction(int id);
    [[nodiscard]] Wallet get_wallet() const;
    void updatePrice(double price) override;
};



#endif //USER_H
