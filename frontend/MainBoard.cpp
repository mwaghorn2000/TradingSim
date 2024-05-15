#include "MainBoard.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QtCharts/QChartView>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

#include "StockChart.h"
#include "../lib/qcustomplot/qcustomplot.h"


MainBoard::MainBoard(QWidget *parent) : QWidget(parent) {


    // Central widget and layout
    QWidget *centralWidget = new QWidget(this);
    this->setStyleSheet("background-color: #121212");
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    QWidget *leftWidget = new QWidget(centralWidget);
    QVBoxLayout *leftLayout = new QVBoxLayout(leftWidget);

    StockChart *stockChart = new StockChart(leftWidget);
    leftLayout->addWidget(stockChart);
    leftLayout->setContentsMargins(0,0,0,0);
    leftLayout->setSpacing(0);
    leftWidget->setLayout(leftLayout);


    // Right widget and layout
    QWidget *rightWidget = new QWidget(centralWidget);
    QVBoxLayout *rightLayout = new QVBoxLayout(rightWidget);

    // Create Wallet label
    QLabel *walletLabel = new QLabel("Wallet", rightWidget);
    walletLabel->setAlignment(Qt::AlignCenter);
    walletLabel->setStyleSheet("background-color: green; color: white; font-size: 16px");

    QListWidget *listPlaceholder = new QListWidget(rightWidget);
    listPlaceholder->setStyleSheet("background-color: #757575");
    listPlaceholder->insertItem(0, "Item 1");
    listPlaceholder->insertItem(0, "Item 2");

    // Create Buy and Sell buttons
    QPushButton *buyButton = new QPushButton("BUY");
    QPushButton *sellButton = new QPushButton("SELL");

    buyButton->setMinimumSize(100, 50);
    buyButton->setStyleSheet("background-color: red; color: white; font-size: 16px;");
    sellButton->setMinimumSize(100, 50);
    sellButton->setStyleSheet("background-color: red; color: white; font-size: 16px;");


    rightLayout->addWidget(walletLabel);
    rightLayout->addWidget(listPlaceholder, 1);
    rightLayout->addWidget(buyButton);
    rightLayout->addWidget(sellButton);
    rightLayout->addStretch(1);

    mainLayout->addWidget(leftWidget, 2);
    mainLayout->addWidget(rightWidget, 1);

    this->setLayout(mainLayout);
    setWindowTitle("Trading Simulator");
}