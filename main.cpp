#include <iostream>
#include "YQSender.h"
#include "YQData.h"
#include "YQChart.h"
#include "widget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    //YQSender sender;
    //sender.show();
    Widget window;
    window.show();
    return application.exec();
}