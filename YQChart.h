#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_YQChart.h"
#include "YQData.h"

class YQChart : public QWidget
{
	Q_OBJECT

public:
	YQChart(QWidget *parent = Q_NULLPTR);
	~YQChart();
	YQData data;
public slots:
	void YQDraw();
private:
	Ui::YQChart ui;
};
