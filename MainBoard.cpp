#include "MainBoard.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QtCharts/QChartView>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

// Assume BuyButton and SellButton are properly defined somewhere

MainBoard::MainBoard(QWidget *parent) : QWidget(parent) {
    // Central widget and layout
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // Placeholder for the chart
    QChartView *chartView = new QChartView();
    chartView->setStyleSheet("background-color: lightgray;");
    chartView->setMinimumWidth(600);

    // Right widget and layout
    QWidget *rightWidget = new QWidget(centralWidget);
    QVBoxLayout *rightLayout = new QVBoxLayout(rightWidget);

    // Create Wallet label
    QLabel *walletLabel = new QLabel("Wallet");
    walletLabel->setAlignment(Qt::AlignCenter);
    walletLabel->setStyleSheet("background-color: green; color: white; font-size: 16px;");
    walletLabel->setFixedSize(100, 50);


    // Create transaction box
    QWidget *transactionBox = new QWidget(rightWidget);
    transactionBox->setStyleSheet("background-color: white;");
    QVBoxLayout *transactionLayout = new QVBoxLayout(transactionBox);

    // Add transaction histories
    QLabel *transactionHistory1 = new QLabel("Transaction History 1");
    transactionHistory1->setStyleSheet("background-color: gray;");
    QLabel *transactionHistory2 = new QLabel("Transaction History 2");
    transactionHistory2->setStyleSheet("background-color: gray;");
    QLabel *transactionHistory3 = new QLabel("Transaction History 3");
    transactionHistory3->setStyleSheet("background-color: gray;");

    transactionLayout->addWidget(transactionHistory1);
    transactionLayout->addWidget(transactionHistory2);
    transactionLayout->addWidget(transactionHistory3);
    transactionLayout->addStretch(1);

    // Create Buy and Sell buttons
    QPushButton *buyButton = new QPushButton("BUY");
    QPushButton *sellButton = new QPushButton("SELL");

    buyButton->setMinimumSize(100, 50);
    buyButton->setStyleSheet("background-color: red; color: white; font-size: 16px;");
    sellButton->setMinimumSize(100, 50);
    sellButton->setStyleSheet("background-color: red; color: white; font-size: 16px;");


    rightLayout->addWidget(walletLabel);
    rightLayout->addWidget(transactionBox, 1);
    rightLayout->addWidget(buyButton);
    rightLayout->addWidget(sellButton);
    rightLayout->addStretch(1);

    mainLayout->addWidget(chartView, 2);
    mainLayout->addWidget(rightWidget, 1);

    this->setLayout(mainLayout);
    setWindowTitle("Trading Simulator");
}