#include "StockChart.h"
#include <iostream>

#include "StockChart.h"
#include <iostream>

StockChart::StockChart(QWidget *parent) : QCustomPlot(parent), minY(100), maxY(100) {
    this->addGraph();
    this->graph(0)->setName("Stock Price");
    this->xAxis->setLabel("Time");
    this->yAxis->setLabel("Price");
    this->xAxis->setRange(0, 100);
    this->yAxis->setRange(minY - 10, maxY + 10); // Initial range
    this->setMinimumWidth(400);
    this->setMinimumHeight(400);
    this->replot();
}

void StockChart::addPoint(double price) {
    static int time = 0;
    std::cout << "Adding point to graph: time=" << time << ", price=" << price << std::endl;
    this->graph(0)->addData(time, price);
    time++;

    // Update x-axis range to show the last 100 points
    this->xAxis->setRange(time - 100, time);

    // Update y-axis range dynamically
    if (price < minY) minY = price;
    if (price > maxY) maxY = price;
    this->yAxis->setRange(minY - 10, maxY + 10); // Adding some padding

    this->replot();
}
