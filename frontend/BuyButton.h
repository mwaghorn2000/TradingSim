//
// Created by geazy on 14/05/2024.
//

#ifndef BUYBUTTON_H
#define BUYBUTTON_H
#include <QPushButton>

#include "ButtonInterface.h"


class BuyButton : public QPushButton, public ButtonInterface{
public:
    BuyButton(QWidget *parent = nullptr);
    void onClick() override;
};



#endif //BUYBUTTON_H
