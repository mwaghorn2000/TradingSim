//
// Created by mitch on 15/05/24.
//

#include "StockChart.h"

StockChart::StockChart(QWidget *parent) : QCustomPlot(parent) {
    // Placeholder for the chart
    QVector<double> x(101), y(101);
    for (int i = 0; i < 101; i++) {
        x[i] = i/50.0 - 1;
        y[i] = x[i]*x[i];
    }

    this->addGraph();
    this->graph(0)->setData(x, y);
    this->xAxis->setLabel("x");
    this->yAxis->setLabel("y");
    this->xAxis->setRange(-1,1);
    this->yAxis->setRange(0, 1);
    this->setMinimumWidth(400);
    this->setMinimumHeight(400);
    this->replot();
}
