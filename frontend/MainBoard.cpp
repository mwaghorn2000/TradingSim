#include "MainBoard.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTimer>
#include <iostream>
#include "BuyButton.h"
#include "StockChart.h"

MainBoard::MainBoard(QWidget *parent) : QWidget(parent), stockChart(nullptr), user(new User(1)) {
    // Central widget and layout
    QWidget *centralWidget = new QWidget(this);
    this->setStyleSheet("background-color: #121212");
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    QWidget *leftWidget = new QWidget(centralWidget);
    QVBoxLayout *leftLayout = new QVBoxLayout(leftWidget);

    // Initialize the stock chart member variable
    stockChart = new StockChart(leftWidget);
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
    BuyButton *buyButton = new BuyButton(user, this);
    SellButton *sellButton = new SellButton(user, this);

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

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainBoard::onTick);
    timer->start(200);

    // Initialize companies map with a sample company
    Stock stock;
    Company company("company_id", stock);
    companies["company_id"] = company;

    std::cout << "MainBoard initialized" << std::endl;

    this->setLayout(mainLayout);
    setWindowTitle("Trading Simulator");
}

void MainBoard::onTick() {
    std::cout << "Tick event" << std::endl;

    auto it = companies.find("company_id");
    if (it == companies.end()) {
        std::cerr << "Company not found!" << std::endl;
        return;
    }

    Company& company = it->second;
    company.getStock().updatePrice();
    double newPrice = company.getStock().getCurrentPrice();

    if (stockChart != nullptr) {
        stockChart->addPoint(newPrice);
    } else {
        std::cerr << "stockChart is null!" << std::endl;
    }

    std::cout << "New stock price: " << newPrice << std::endl;
}

double MainBoard::getCurrentStockPrice() const {
    auto it = companies.find("company_id");
    if (it != companies.end()) {
        return it->second.getStock().getCurrentPrice();
    } else {
        std::cerr << "Company not found!" << std::endl;
        return 0.0; // Or some default error value
    }
}
