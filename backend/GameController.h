//
// Created by mitch on 19/05/24.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "User.h"
#include "Company.h"


class GameController {
private:
    User user;
    std::map<std::string, Company> companies;

public:
    GameController(const User& user) : user(user) {}
    void addCompany(const std::string& id, const Company& company) {
        companies[id] = company;
    }
    Company& getCompany(const std::string& id) {
        return companies[id];
    }
};



#endif //GAMECONTROLLER_H
