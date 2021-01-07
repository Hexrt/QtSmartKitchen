#include "YQChart.h"
#include "YQUtil.h"
#include "QTimer"
#include <QNetworkReply>
#include <QJsonParseError>

YQChart::YQChart(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QTimer* timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(YQDraw()));
	timer->start(2000);
}

YQChart::~YQChart()
{}

void YQChart:: YQDraw() {
    QString url = "https://tools.ctrl-s.cn/practice/001/getCurrentData";
    QByteArray rawData = YQUtil::GET(url);
    QString str = rawData;
	str = str.toUtf8();
	YQData data = YQUtil::StringToYQData(str);
	qDebug() << data.getTemperature();
	qDebug() << data.getHumidity();
	ui.label_7->setText(QString::number(data.getTemperature()));
	ui.label_8->setText(QString::number(data.getHumidity()));
	ui.label_9->setText(QString::number(data.getBoomgas()));
	ui.label_10->setText(QString::number(data.getSmog()));
	ui.label_11->setText((data.getTheft())?"YES":"NO");
	ui.label_12->setText((data.getLightOn()) ? "YES" : "NO");
}