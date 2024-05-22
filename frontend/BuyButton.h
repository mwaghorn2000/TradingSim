//
// Created by geazy on 14/05/2024.
//

#ifndef BUYBUTTON_H
#define BUYBUTTON_H
#include <QPushButton>
#include "../backend/User.h"
#include "ButtonInterface.h"
#include "MainBoard.h"
#include "../backend/GameController.h"

class MainBoard;

class BuyButton : public QPushButton {
    Q_OBJECT
public:
    explicit BuyButton(User* user, MainBoard* mainBoard, GameController* gameController, QWidget *parent = nullptr);

    private slots:
        void onClick();

private:
    User* user;
    MainBoard* mainBoard;
    GameController* gameController;
};

#endif //BUYBUTTON_H
