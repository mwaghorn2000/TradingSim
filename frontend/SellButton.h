//
// Created by geazy on 14/05/2024.
//

#ifndef SELLBUTTON_H
#define SELLBUTTON_H

#include <QPushButton>

#include "ButtonInterface.h"


class SellButton : public QPushButton, public ButtonInterface {
public:
    SellButton(QWidget *parent = nullptr);
    void onClick() override;
};



#endif //SELLBUTTON_H
