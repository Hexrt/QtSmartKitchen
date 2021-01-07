#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QtCharts>
#include<QChartView>
#include<QSplineSeries>
#include<QMouseEvent>
#include<QPixmap>
#include<QPalette>
#include<QBitmap>
#include<QLabel>
#include<QPieSlice>
#include<QPieSeries>
#include<QtCore/QDebug>
#include<QtMultimedia/QMediaPlayer>
#include "UTF.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget* parent = 0);
    ~Widget();


private:
    //折线图
    QSplineSeries* main_series = new QSplineSeries(this);
    QChartView* main_chartView = new QChartView(this);
    QChart* main_chart = new QChart();
    //图表
    QPieSeries* series_1 = new QPieSeries(this);
    QPieSeries* series_2 = new QPieSeries(this);
    QPieSeries* series_3 = new QPieSeries(this);
    QPieSeries* series_4 = new QPieSeries(this);
    QChartView* chartView_1 = new QChartView(this);
    QChartView* chartView_2 = new QChartView(this);
    QChartView* chartView_3 = new QChartView(this);
    QChartView* chartView_4 = new QChartView(this);

private slots:
    void on_radioButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_listWidget_clicked(const QModelIndex& index);

    void on_pushButton_5_clicked();
private:
    //展现折线图
    void showTemperatureGraph();
    void showHumidityGraph();
    void showBoomGasGraph();
    void showSmogGraph();
    void showChooseBox();
    //展现那几个环
    void showTemperatureCircle();
    void showHumidityCircle();
    void showBoomGasCircle();
    void showSmogCircle();
    // init
    void initButton();
    void initGraph();
private:
    Ui::Widget* ui;
};

#endif // WIDGET_H
