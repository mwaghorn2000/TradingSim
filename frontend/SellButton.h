//
// Created by geazy on 14/05/2024.
//

#ifndef SELLBUTTON_H
#define SELLBUTTON_H

#include <QPushButton>
#include "ButtonInterface.h"
#include "../backend/User.h"
#include "MainBoard.h"

class MainBoard;

class SellButton : public QPushButton, public ButtonInterface {
    Q_OBJECT

public:
    explicit SellButton(User* user, MainBoard* mainBoard, QWidget *parent = nullptr);
    void onClick() override;

private:
    User* user;
    MainBoard* mainBoard;
};

#endif //SELLBUTTON_H
