#include "YQSender.h"
#include <QNetworkAccessManager>
#include <QApplication>
#include <QNetworkReply>
#include <QTimer>
#include <QDateTime>
#include "YQUtil.h"

YQSender::YQSender(QWidget *parent)
	: QWidget(parent)
{
    //初始化数据
    data = YQData(37, 26, 10, 0.0375, 1, 1);
	ui.setupUi(this);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(YQupdate()));
    timer->start(1500);
}

YQSender::~YQSender()
{}

void YQSender::changeTemperature() {
    data.setTemperature(ui.temperature->value());
}

void YQSender::changeHumidity() {
    data.setHumidity(ui.humidity->value());
}

void YQSender::changeBoomgas() {
    data.setBoomgas(ui.boomgas->value());
}

void YQSender::changeSmog() {
    data.setSmog(ui.smog->value());
}

void YQSender::changeTheft() {
    data.setTheft(ui.lock->isChecked());
}

void YQSender::changeLightOn() {
    data.setLightOn(ui.active->isChecked());
}

void YQSender::YQupdate()
{
    QString url = "https://tools.ctrl-s.cn/practice/001/update/";
    //*
    url += "?temperature=";
    url += QString::number(data.getTemperature());
    url += "&humidity=";
    url += QString::number(data.getHumidity());
    url += "&boomGas=";
    url += QString::number(data.getBoomgas());
    url += "&smog=";
    url += QString::number(data.getSmog());
    url += "&theft=";
    url += QString::number(data.getTheft());
    url += "&lightOn=";
    url += QString::number(data.getLightOn());
    //*/
    YQUtil::GET(url);
}
