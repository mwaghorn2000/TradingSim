//
// Created by mitch on 19/05/24.
//

#include "GameController.h"
using namespace std;

// returns active transactions
list<Transaction> GameController::get_active_transactions() {
    list<Transaction> all_transactions = this->user->get_transactions();

    list<Transaction> active_transactions;
    for (auto t : all_transactions) {
        if (t.is_active()) {
            active_transactions.push_back(t);
        }
    }

    return active_transactions;
}

int GameController::purchase_stock() {
    if (this->get_active_transactions().size() >= MAX_STOCKS) {
        cout << "Transaction failed\n";
        return 1;
    }

    double price = this->company->getStock().getCurrentPrice();
    this->user->remove_money(price);
    this->user->addTransaction(price);
    cout << "Transaction added successfully\n";
    return 0;
}

int GameController::sell_stock(int id, double sold_price) {
    list<Transaction> transactions = this->user->get_transactions();
    Transaction *t_to_sell = nullptr;
    for (auto t : transactions) {
        if (t.get_id() == id) {
            t_to_sell = &t;
        }
    }

    // not found
    if (t_to_sell == nullptr) {
        cout << "failed to close transaction\n";
        return 1;
    }

    t_to_sell->set_sold_price(sold_price);

    cout << "Successfully closed transaction for id: " << id << endl;
    return 0;
}