//
// Created by mitch on 15/05/24.
//

#ifndef USER_H
#define USER_H



class User {
private:
    int id;
    int money;

public:
    explicit User(const int id) {
        this->id = id;
        this->money = 1000;
    }
};



#endif //USER_H
