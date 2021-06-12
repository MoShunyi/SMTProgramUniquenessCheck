/********************************************************************************
** Form generated from reading UI file 'loadingwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGWIDGET_H
#define UI_LOADINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadingWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *labelLoading;

    void setupUi(QWidget *LoadingWidget)
    {
        if (LoadingWidget->objectName().isEmpty())
            LoadingWidget->setObjectName(QStringLiteral("LoadingWidget"));
        LoadingWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(LoadingWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelLoading = new QLabel(LoadingWidget);
        labelLoading->setObjectName(QStringLiteral("labelLoading"));
        labelLoading->setPixmap(QPixmap(QString::fromUtf8(":/AOIKeyParameterMonitor/Resources/loading1.gif")));
        labelLoading->setScaledContents(true);

        horizontalLayout->addWidget(labelLoading);


        retranslateUi(LoadingWidget);

        QMetaObject::connectSlotsByName(LoadingWidget);
    } // setupUi

    void retranslateUi(QWidget *LoadingWidget)
    {
        LoadingWidget->setWindowTitle(QApplication::translate("LoadingWidget", "LoadingWidget", 0));
        labelLoading->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoadingWidget: public Ui_LoadingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGWIDGET_H
