#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_YQSender.h"
#include "YQData.h"

/*
* ������һ���������ݵ���
*/
class YQSender : public QWidget
{
	Q_OBJECT

public:
	YQSender(QWidget *parent = Q_NULLPTR);
	~YQSender();

private:
	Ui::YQSender ui;

public:
	YQData data;

public slots :
	void changeTemperature();
	void changeHumidity();
	void changeBoomgas();
	void changeSmog();
	void changeTheft();
	void changeLightOn();
	void YQupdate();
};
