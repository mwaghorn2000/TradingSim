//
// Created by mitch on 19/05/24.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "User.h"
#include "Company.h"
#include <iostream>
#include <utility>


class GameController {
private:
    User* user;
    Company* company;
    static const int MAX_STOCKS = 5;

public:
     explicit GameController(User* user) : user(user) {}

    Company& getCompany(const std::string& id) {
        return *this->company;
    }

    void addCompany(Company* company) {
         this->company = company;
     }

    std::list<Transaction> get_active_transactions();

    // returns 0 for successful purchase, 1 for failure
    int purchase_stock();
    int sell_stock(int id, double sold_price);
};

#endif //GAMECONTROLLER_H
