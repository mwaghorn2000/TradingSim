//
// Created by geazy on 14/05/2024.
//

#ifndef MAINBOARD_H
#define MAINBOARD_H
#include "StockChart.h"
#include "../backend/GameController.h"
#include <QWidget>
#include <QVBoxLayout>
#include "BuyButton.h"
#include "SellButton.h"
#include "../backend/Company.h"
#include <map>
#include "../backend/User.h"


class MainBoard : public QWidget {
    Q_OBJECT
public:
    MainBoard(QWidget *parent = nullptr);

    private slots:
        void onTick();
public:
    double getCurrentStockPrice() const;
    GameController getGameController();
private:
    QLabel* walletLabel;
    StockChart *stockChart;
    std::map<std::string, Company> companies;
    User *user;
    GameController gc;
};


#endif //MAINBOARD_H
