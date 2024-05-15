//
// Created by mitch on 15/05/24.
//

#ifndef STOCKCHART_H
#define STOCKCHART_H
#include "../lib/qcustomplot/qcustomplot.h"


class StockChart : public QCustomPlot {
    Q_OBJECT
public:
    explicit StockChart(QWidget *parent = nullptr);
};



#endif //STOCKCHART_H
