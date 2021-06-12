/********************************************************************************
** Form generated from reading UI file 'uniquenesscheck.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNIQUENESSCHECK_H
#define UI_UNIQUENESSCHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UniquenessCheckClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *logo;
    QLabel *title;
    QLabel *connDB;
    QLabel *label;
    QLabel *labelUnderline;
    QTabWidget *tabWidget;
    QWidget *tabResult;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelInterval;
    QComboBox *comboBoxInterval;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButtonWriteOnce;
    QPushButton *pushButtonAutoWrite;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelTiming;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox1;
    QVBoxLayout *verticalLayout_10;
    QTableView *tableView_1;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox1_2;
    QVBoxLayout *verticalLayout_11;
    QTableView *tableView_2;
    QWidget *tabQuery;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelLineNo;
    QComboBox *comboBoxLineNo;
    QSpacerItem *horizontalSpacer_6;
    QLabel *labelProgramName;
    QLineEdit *lineEditProgramName;
    QSpacerItem *horizontalSpacer_7;
    QDialogButtonBox *buttonBoxQuery;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UniquenessCheckClass)
    {
        if (UniquenessCheckClass->objectName().isEmpty())
            UniquenessCheckClass->setObjectName(QStringLiteral("UniquenessCheckClass"));
        UniquenessCheckClass->resize(1339, 817);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UniquenessCheckClass->sizePolicy().hasHeightForWidth());
        UniquenessCheckClass->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(UniquenessCheckClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        logo = new QLabel(centralWidget);
        logo->setObjectName(QStringLiteral("logo"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy1);
        logo->setMinimumSize(QSize(189, 20));
        logo->setMaximumSize(QSize(380, 80));
        logo->setSizeIncrement(QSize(9, 1));
        logo->setBaseSize(QSize(392, 60));
        logo->setInputMethodHints(Qt::ImhNone);
        logo->setPixmap(QPixmap(QString::fromUtf8(":/UniquenessCheck/Resources/\344\274\201\344\270\232\346\240\207\345\277\227\344\270\216\344\274\201\344\270\232\344\270\255\350\213\261\346\226\207\345\205\250\347\247\260\347\273\204\345\220\210_\350\223\235\357\274\215Logo with Company Name in Chinese and English_Blue.jpg")));
        logo->setScaledContents(true);
        logo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        logo->setWordWrap(false);
        logo->setIndent(-1);
        logo->setOpenExternalLinks(false);
        logo->setTextInteractionFlags(Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(logo);

        title = new QLabel(centralWidget);
        title->setObjectName(QStringLiteral("title"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy2);
        title->setMinimumSize(QSize(500, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("font: 75 20pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 57, 115);"));
        title->setScaledContents(true);
        title->setAlignment(Qt::AlignCenter);
        title->setWordWrap(false);
        title->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        horizontalLayout->addWidget(title);

        connDB = new QLabel(centralWidget);
        connDB->setObjectName(QStringLiteral("connDB"));
        sizePolicy1.setHeightForWidth(connDB->sizePolicy().hasHeightForWidth());
        connDB->setSizePolicy(sizePolicy1);
        connDB->setMinimumSize(QSize(0, 0));
        connDB->setMaximumSize(QSize(200, 200));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        connDB->setFont(font1);
        connDB->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        connDB->setScaledContents(true);
        connDB->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(connDB);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(189, 20));
        label->setMaximumSize(QSize(380, 60));
        label->setSizeIncrement(QSize(2, 1));
        label->setPixmap(QPixmap(QString::fromUtf8(":/UniquenessCheck/Resources/bosch.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        labelUnderline = new QLabel(centralWidget);
        labelUnderline->setObjectName(QStringLiteral("labelUnderline"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelUnderline->sizePolicy().hasHeightForWidth());
        labelUnderline->setSizePolicy(sizePolicy3);
        labelUnderline->setBaseSize(QSize(300, 0));
        labelUnderline->setPixmap(QPixmap(QString::fromUtf8(":/UniquenessCheck/Resources/bottom.png")));
        labelUnderline->setScaledContents(true);

        verticalLayout->addWidget(labelUnderline);


        verticalLayout_5->addLayout(verticalLayout);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\351\273\221\344\275\223\";"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(20, 20));
        tabResult = new QWidget();
        tabResult->setObjectName(QStringLiteral("tabResult"));
        horizontalLayout_7 = new QHBoxLayout(tabResult);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelInterval = new QLabel(tabResult);
        labelInterval->setObjectName(QStringLiteral("labelInterval"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        labelInterval->setFont(font2);
        labelInterval->setAutoFillBackground(true);
        labelInterval->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelInterval);

        comboBoxInterval = new QComboBox(tabResult);
        comboBoxInterval->setObjectName(QStringLiteral("comboBoxInterval"));
        comboBoxInterval->setFont(font2);

        horizontalLayout_3->addWidget(comboBoxInterval);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        pushButtonWriteOnce = new QPushButton(tabResult);
        pushButtonWriteOnce->setObjectName(QStringLiteral("pushButtonWriteOnce"));
        pushButtonWriteOnce->setFont(font2);

        horizontalLayout_3->addWidget(pushButtonWriteOnce);

        pushButtonAutoWrite = new QPushButton(tabResult);
        pushButtonAutoWrite->setObjectName(QStringLiteral("pushButtonAutoWrite"));
        pushButtonAutoWrite->setFont(font2);

        horizontalLayout_3->addWidget(pushButtonAutoWrite);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelTiming = new QLabel(tabResult);
        labelTiming->setObjectName(QStringLiteral("labelTiming"));
        sizePolicy1.setHeightForWidth(labelTiming->sizePolicy().hasHeightForWidth());
        labelTiming->setSizePolicy(sizePolicy1);
        labelTiming->setMinimumSize(QSize(0, 60));
        labelTiming->setFont(font2);
        labelTiming->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(labelTiming);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox1 = new QGroupBox(tabResult);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        verticalLayout_10 = new QVBoxLayout(groupBox1);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        tableView_1 = new QTableView(groupBox1);
        tableView_1->setObjectName(QStringLiteral("tableView_1"));
        tableView_1->setFont(font2);

        verticalLayout_10->addWidget(tableView_1);


        horizontalLayout_4->addWidget(groupBox1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        groupBox1_2 = new QGroupBox(tabResult);
        groupBox1_2->setObjectName(QStringLiteral("groupBox1_2"));
        verticalLayout_11 = new QVBoxLayout(groupBox1_2);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        tableView_2 = new QTableView(groupBox1_2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setFont(font2);

        verticalLayout_11->addWidget(tableView_2);


        horizontalLayout_4->addWidget(groupBox1_2);


        verticalLayout_4->addLayout(horizontalLayout_4);


        horizontalLayout_7->addLayout(verticalLayout_4);

        tabWidget->addTab(tabResult, QString());
        tabQuery = new QWidget();
        tabQuery->setObjectName(QStringLiteral("tabQuery"));
        horizontalLayout_6 = new QHBoxLayout(tabQuery);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        labelLineNo = new QLabel(tabQuery);
        labelLineNo->setObjectName(QStringLiteral("labelLineNo"));

        horizontalLayout_11->addWidget(labelLineNo);

        comboBoxLineNo = new QComboBox(tabQuery);
        comboBoxLineNo->setObjectName(QStringLiteral("comboBoxLineNo"));
        sizePolicy2.setHeightForWidth(comboBoxLineNo->sizePolicy().hasHeightForWidth());
        comboBoxLineNo->setSizePolicy(sizePolicy2);
        comboBoxLineNo->setMinimumSize(QSize(0, 0));

        horizontalLayout_11->addWidget(comboBoxLineNo);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);

        labelProgramName = new QLabel(tabQuery);
        labelProgramName->setObjectName(QStringLiteral("labelProgramName"));
        labelProgramName->setFont(font2);

        horizontalLayout_11->addWidget(labelProgramName);

        lineEditProgramName = new QLineEdit(tabQuery);
        lineEditProgramName->setObjectName(QStringLiteral("lineEditProgramName"));
        sizePolicy1.setHeightForWidth(lineEditProgramName->sizePolicy().hasHeightForWidth());
        lineEditProgramName->setSizePolicy(sizePolicy1);
        lineEditProgramName->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_11->addWidget(lineEditProgramName);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);

        buttonBoxQuery = new QDialogButtonBox(tabQuery);
        buttonBoxQuery->setObjectName(QStringLiteral("buttonBoxQuery"));
        sizePolicy1.setHeightForWidth(buttonBoxQuery->sizePolicy().hasHeightForWidth());
        buttonBoxQuery->setSizePolicy(sizePolicy1);
        buttonBoxQuery->setMaximumSize(QSize(200, 16777215));
        buttonBoxQuery->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Reset);

        horizontalLayout_11->addWidget(buttonBoxQuery);


        verticalLayout_3->addLayout(horizontalLayout_11);

        tableView = new QTableView(tabQuery);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_3->addWidget(tableView);


        horizontalLayout_6->addLayout(verticalLayout_3);

        tabWidget->addTab(tabQuery, QString());

        verticalLayout_5->addWidget(tabWidget);


        horizontalLayout_2->addLayout(verticalLayout_5);

        UniquenessCheckClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UniquenessCheckClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1339, 26));
        UniquenessCheckClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UniquenessCheckClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        UniquenessCheckClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UniquenessCheckClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        UniquenessCheckClass->setStatusBar(statusBar);

        retranslateUi(UniquenessCheckClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UniquenessCheckClass);
    } // setupUi

    void retranslateUi(QMainWindow *UniquenessCheckClass)
    {
        UniquenessCheckClass->setWindowTitle(QApplication::translate("UniquenessCheckClass", "UniquenessCheck", 0));
        logo->setText(QString());
        title->setText(QApplication::translate("UniquenessCheckClass", "SMT Program Uniqueness Check", 0));
        connDB->setText(QApplication::translate("UniquenessCheckClass", "DB", 0));
        label->setText(QString());
        labelUnderline->setText(QString());
        labelInterval->setText(QApplication::translate("UniquenessCheckClass", "\346\227\266\351\227\264\351\227\264\351\232\224(H)\357\274\232", 0));
        comboBoxInterval->clear();
        comboBoxInterval->insertItems(0, QStringList()
         << QApplication::translate("UniquenessCheckClass", "15", 0)
         << QApplication::translate("UniquenessCheckClass", "30", 0)
         << QApplication::translate("UniquenessCheckClass", "60", 0)
        );
        pushButtonWriteOnce->setText(QApplication::translate("UniquenessCheckClass", "\347\253\213\345\215\263\346\243\200\346\237\245\344\270\200\346\254\241", 0));
        pushButtonAutoWrite->setText(QApplication::translate("UniquenessCheckClass", "\350\207\252\345\212\250\345\276\252\347\216\257\346\243\200\346\237\245", 0));
        labelTiming->setText(QString());
        groupBox1->setTitle(QApplication::translate("UniquenessCheckClass", "Same Name In Different Line:", 0));
        groupBox1_2->setTitle(QApplication::translate("UniquenessCheckClass", "Same Name In Same Line:     ", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabResult), QApplication::translate("UniquenessCheckClass", "Check", 0));
        labelLineNo->setText(QApplication::translate("UniquenessCheckClass", "LineNo\357\274\232", 0));
        labelProgramName->setText(QApplication::translate("UniquenessCheckClass", "ProgramName\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabQuery), QApplication::translate("UniquenessCheckClass", "Query", 0));
    } // retranslateUi

};

namespace Ui {
    class UniquenessCheckClass: public Ui_UniquenessCheckClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNIQUENESSCHECK_H
