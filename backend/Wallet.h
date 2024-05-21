//
// Created by mitch on 19/05/24.
//

#ifndef WALLET_H
#define WALLET_H



class Wallet {
private:
    double money{};

public:
    Wallet();

    void add_money(double amount);

    void remove_money(double amount);

    [[nodiscard]] double get_money() const;
};



#endif //WALLET_H
