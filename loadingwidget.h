#ifndef LOADINGWIDGET_H
#define LOADINGWIDGET_H

#include <QWidget>
#include <QDesktopWidget>
#include <QMovie>
#include "ui_loadingwidget.h"

class LoadingWidget : public QWidget
{
    Q_OBJECT

public:
    LoadingWidget(QWidget *parent = 0);
    ~LoadingWidget();

private:
    Ui::LoadingWidget ui;
    QMovie *movie;
};

#endif // LOADINGWIDGET_H
