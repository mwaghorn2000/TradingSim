//
// Created by mitch on 19/05/24.
//

#ifndef COMPANY_H
#define COMPANY_H
#include <string>
#include "Stock.h"


class Company {
private:
    std::string id;
    Stock stock;
public:
    Company() = default;
    Company(const std::string& id, const Stock& stock);
    Stock& getStock(); // Return non-const reference
    [[nodiscard]] const Stock& getStock() const; // Overload for const method
    std::string get_id();
};



#endif //COMPANY_H
