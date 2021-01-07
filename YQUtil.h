#pragma once
#include <QString>
#include "YQData.h"
#include <QJsonObject>
class YQUtil
{
	public:
		static QByteArray GET(QString);
		static QJsonObject StringToJson(QString);
		static YQData StringToYQData(QString);
};

