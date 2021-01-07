#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    showChooseBox();
    showTemperatureCircle();
    showHumidityCircle();
    showBoomGasCircle();
    showSmogCircle();
    initButton();
    initGraph();
}

////////show

void Widget::initButton()
{
    //报错处理模块
         //三个PushButton用于处理异常，响应pushButton，
   //1是处理，2是忽略提示，3是删除文本框最后一行的报错
    //报错文本框:
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->item(0)->setTextColor(Qt::red);
    ui->listWidget->item(1)->setTextColor(Qt::red);
    ui->listWidget->item(2)->setTextColor(Qt::red);
    ui->listWidget->item(3)->setTextColor(Qt::red);
    ui->listWidget->item(4)->setTextColor(Qt::red);
    ui->listWidget->item(5)->setTextColor(Qt::red);
    //报错处理end

    //上部比例圆图：

  //传感器插入好信息用CheckBox显示,默认check为false
  // ui->checkBox->setChecked(true);

    //设置默认情况下五个按钮的可用与否
    QPalette pal_2 = ui->pushButton_5->palette();
    pal_2.setColor(QPalette::Button, Qt::red);
    ui->pushButton_5->setPalette(pal_2);
    ui->pushButton_5->setAutoFillBackground(true);
    ui->pushButton_5->setFlat(true);
    ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(51, 180, 148)}");
    ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(180, 56, 47)}");
    //圆图end

}

/*
初始化图表
*/
void Widget::initGraph()
{
    main_chart->addSeries(main_series);     //添加折线系列
    main_chart->legend()->hide();          //隐藏图标
    main_chartView->setChart(main_chart);           //添加图标对象
    main_chartView->setRenderHints(QPainter::Antialiasing);
    main_chart->createDefaultAxes();
    main_series->setPointLabelsClipping(false);
    main_chartView->resize(QSize(500, 300));      //大小
    ui->gridLayout->addWidget(main_chartView, 0, 0, 10, 10);
    showTemperatureGraph();
    showChooseBox();
}

//修改主题来改变折线的颜色，温度用Brow Sand，湿度BlueNcs,烟雾BlueCerulean，可燃气体dark
void Widget::showTemperatureGraph()
{
    main_series->clear();
    for (int i = 0; i < 9; ++i) {
        main_series->append(i, rand()%100);
    }
    //main_series->setPointLabelsVisible();
    main_chart->createDefaultAxes();
    main_chart->axisX()->setRange(0,50);
    main_chart->axisY()->setRange(0,100);       //修改参数，要改变对应的坐标范围，设置坐标范围
    main_series->setName("温度");        //系列的名字
    main_chart->setTheme(QChart::ChartThemeBlueIcy);       //主题颜色
}

void Widget::showHumidityGraph()
{
    showTemperatureGraph();
}

void Widget::showBoomGasGraph()
{
    showTemperatureGraph();
}

void Widget::showSmogGraph()
{
    showTemperatureGraph();

}

/*
显示选择图表按钮
*/
void Widget::showChooseBox()
{
    /*
    ui->gridLayout->addWidget(ui->radioButton,   1, 7, 1, 1);
    ui->gridLayout->addWidget(ui->radioButton_2, 1, 8, 1, 1);
    ui->gridLayout->addWidget(ui->radioButton_3, 2, 7, 1, 1);
    ui->gridLayout->addWidget(ui->radioButton_4, 2, 8, 1, 1);
    */
    
}


void Widget::showTemperatureCircle()
{
    //圆弧部分1
    series_1->setHoleSize(0.35);     //圆环内控大小0——1
    series_1->append("", 60);    //非正常分块，占比60
    series_1->append("", 40); //正常圆弧部分
    //显示部分:
    chartView_1->setRenderHint(QPainter::Antialiasing);  //提示
    chartView_1->chart()->setTitle("温度");
    chartView_1->chart()->addSeries(series_1);  //对象添加到控件 中
    chartView_1->chart()->legend()->setAlignment(Qt::AlignHCenter);  //图例显示在底部
    chartView_1->chart()->setTheme(QChart::ChartThemeBrownSand);      //图的背景主题
    ui->horizontalLayout->addWidget(chartView_1);
    //end1
}

void Widget::showHumidityCircle()
{
    //圆弧部分2
    series_2->setHoleSize(0.35);     //圆环内控大小0——1
    series_2->append("", 50);    //非正常分块，占比50
    series_2->append("", 50);//正常圆弧部分
    //显示部分:
    chartView_2->setRenderHint(QPainter::Antialiasing);  //提示
    chartView_2->chart()->setTitle("湿度");
    chartView_2->chart()->addSeries(series_2);  //对象添加到控件 中
    chartView_2->chart()->legend()->setAlignment(Qt::AlignHCenter);  //图例显示在底部
    chartView_2->chart()->setTheme(QChart::ChartThemeBlueNcs);      //图的背景主题
    ui->horizontalLayout->addWidget(chartView_2);
    //end2
}

void Widget::showBoomGasCircle()
{
    //圆弧部分3
    series_3->setHoleSize(0.35);     //圆环内控大小0——1
    series_3->append("", 50);    //非正常分块，占比10
    series_3->append("", 50);//正常圆弧部分
   //显示部分:
    chartView_3->setRenderHint(QPainter::Antialiasing);  //提示
    chartView_3->chart()->setTitle("烟雾");
    chartView_3->chart()->addSeries(series_3);  //对象添加到控件 中
    chartView_3->chart()->legend()->setAlignment(Qt::AlignHCenter);  //图例显示在底部
    chartView_3->chart()->setTheme(QChart::ChartThemeBlueCerulean);      //图的背景主题
    ui->horizontalLayout->addWidget(chartView_3);
    //end3
}

void Widget::showSmogCircle()
{
    //圆弧部分4
    series_4->setHoleSize(0.35);     //圆环内控大小0——1
    series_4->append("", 30);    //分块，占比30
    series_4->append("", 70); //正常圆弧部分    
     //显示部分:
    chartView_4->setRenderHint(QPainter::Antialiasing);  //提示
    chartView_4->chart()->setTitle("可燃气体");
    chartView_4->chart()->addSeries(series_4);  //对象添加到控件 中
    chartView_4->chart()->legend()->setAlignment(Qt::AlignHCenter);  //图例显示在底部
    chartView_4->chart()->setTheme(QChart::ChartThemeDark);      //图的背景主题
    ui->horizontalLayout->addWidget(chartView_4);
    //end4
}


//////////////Functions

/*
生成折线图
*/
void Widget::on_radioButton_clicked()
{
    showTemperatureGraph();
}


//选中listwidget的一行，将这一行变为普通格式
void Widget::on_pushButton_clicked()
{

    if (ui->listWidget->currentRow() != -1) {

        int row = ui->listWidget->currentRow();

        ui->listWidget->item(row)->setTextColor(Qt::white);
    }

}

//清空报错栏
void Widget::on_pushButton_2_clicked()
{
    if (ui->listWidget->count() > 0) {
        ui->listWidget->disconnect();
        ui->listWidget->clear();
        ui->pushButton_2->setStyleSheet("QPushButton{background-color:rgb(180, 152, 73)}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(51, 180, 148)}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(180, 56, 47)}");
    }
}

//删除一行
void Widget::on_pushButton_3_clicked()
{
    if (ui->listWidget->currentRow() != -1) {
        int row = ui->listWidget->currentRow();
        ui->listWidget->takeItem(row);
    }
    if (ui->listWidget->count() == 0) {
        ui->pushButton_2->setStyleSheet("QPushButton{background-color:rgb(180, 152, 73)}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(51, 180, 148)}");
        ui->pushButton_3->setStyleSheet("QPushButton{background-color: rgb(180, 56, 47)}");
    }
}

//灯的响应
int click_light = 0;

void Widget::on_pushButton_4_clicked()
{
    click_light++;
    if (click_light % 2 == 1) {
        qDebug("灯亮了 ");

        ui->pushButton_4->setStyleSheet("QPushButton{background-color: rgb(255, 239, 157)}");
        //background-color: rgb(255, 239, 157);
    }
    else {
        qDebug("灯灭了 ");
        ui->pushButton_4->setStyleSheet("QPushButton{background-color:rgb(180, 169, 111)}");
    }
}



//响应文本框
void Widget::on_listWidget_clicked(const QModelIndex& index)
{
    if (ui->listWidget->currentRow() != -1) {
        // ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(51, 180, 148)}");

        qDebug("选中了");

        ui->pushButton->setStyleSheet("QPushButton{background-color:rgb(63, 220, 181)}");
        //_2
        //_3   background-color:rgb(255, 82, 67);
        ui->pushButton_3->setStyleSheet("QPushButton{ background-color:rgb(255, 82, 67)}");
    }

}


int suonum = 0;
//锁的响应
void Widget::on_pushButton_5_clicked()
{
    suonum++;
    if (suonum % 2 == 1) {
        qDebug("锁被撬了 ");

        ui->pushButton_5->setStyleSheet("QPushButton{background-color: rgb(255, 10, 10)}");
        //background-color: rgb(255, 239, 157);
    }
    else {
        qDebug("锁没事了 ");
        ui->pushButton_5->setStyleSheet("QPushButton{background-color:rgb(166, 175, 255)}");
    }

}




Widget::~Widget()
{
    delete ui;
}