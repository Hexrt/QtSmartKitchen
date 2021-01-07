#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BigProject.h"

class BigProject : public QMainWindow
{
    Q_OBJECT

public:
    BigProject(QWidget *parent = Q_NULLPTR);

private:
    Ui::BigProjectClass ui;
};
