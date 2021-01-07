#include "YQUtil.h"
#include <QNetworkAccessManager>
#include <QJsonParseError>
#include <QNetworkReply>
#include <QEventLoop>

QByteArray YQUtil::GET(QString url) {
    QNetworkAccessManager* manager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkReply* pReply = manager->get(request);
    // 开启一个局部的事件循环，等待页面响应结束
    QEventLoop eventLoop;
    QObject::connect(manager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();
    // 获取网页Body中的内容
    QByteArray bytes = pReply->readAll();
    return bytes;
}

QJsonObject YQUtil::StringToJson(QString data) {
    QJsonObject l_ret;
    QJsonParseError l_err;
    QJsonDocument l_doc = QJsonDocument::fromJson(data.toUtf8(), &l_err);
    if (l_err.error == QJsonParseError::NoError)
    {
        if (l_doc.isObject())
        {
            l_ret = l_doc.object();
        }
    }
    return l_ret;
}

YQData YQUtil::StringToYQData(QString str) {
    /*
    "{\"status\":1001,\"message\":\"success\",\"data\":{\"temperature\":37.0,\"humidity\":26.0,\"boomGas\":10.0,\"smog\":0.0375,\"theft\":true,\"lightOn\":true,\"gmt\":1609860913566}}"
    */
    str = str.remove("}}");
    str = str.remove("{\"status\":1001,\"message\":\"success\",\"data\":{");
    str.remove("\"");
    str = str.replace("true", "1");
    str = str.replace("false", 0);
    qDebug() << str;
    QStringList list = str.split(",");
    YQData data;
    data.setTemperature(list[0].split(":")[1].toDouble());
    data.setHumidity(list[1].split(":")[1].toDouble());
    data.setBoomgas(list[2].split(":")[1].toDouble());
    data.setSmog(list[3].split(":")[1].toDouble());
    data.setTheft(list[4].split(":")[1].toInt());
    data.setLightOn(list[5].split(":")[1].toInt());
    return data;
}