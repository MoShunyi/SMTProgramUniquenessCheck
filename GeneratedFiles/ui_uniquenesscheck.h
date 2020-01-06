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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *logo;
    QSpacerItem *horizontalSpacer_2;
    QLabel *title;
    QSpacerItem *horizontalSpacer_3;
    QLabel *connDB;
    QTabWidget *tabWidget;
    QWidget *tabResult;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *labelTime;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonRecheck;
    QLabel *labelResult;
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
        UniquenessCheckClass->resize(1057, 732);
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
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        logo = new QLabel(centralWidget);
        logo->setObjectName(QStringLiteral("logo"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy1);
        logo->setMaximumSize(QSize(380, 16777215));
        logo->setBaseSize(QSize(392, 60));
        logo->setInputMethodHints(Qt::ImhNone);
        logo->setPixmap(QPixmap(QString::fromUtf8(":/image/Resources/image/Logo with Slogan_Blue.jpg")));
        logo->setScaledContents(true);
        logo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        logo->setWordWrap(false);
        logo->setIndent(-1);
        logo->setOpenExternalLinks(false);
        logo->setTextInteractionFlags(Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(logo);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        title = new QLabel(centralWidget);
        title->setObjectName(QStringLiteral("title"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy2);
        title->setMinimumSize(QSize(0, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("font: 75 16pt \"\351\273\221\344\275\223\";\n"
"color: rgb(0, 57, 115);"));
        title->setScaledContents(true);
        title->setAlignment(Qt::AlignCenter);
        title->setWordWrap(false);
        title->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        horizontalLayout->addWidget(title);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        connDB = new QLabel(centralWidget);
        connDB->setObjectName(QStringLiteral("connDB"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(connDB->sizePolicy().hasHeightForWidth());
        connDB->setSizePolicy(sizePolicy3);
        connDB->setMinimumSize(QSize(200, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        connDB->setFont(font1);
        connDB->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        connDB->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(connDB);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\351\273\221\344\275\223\";"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(20, 20));
        tabResult = new QWidget();
        tabResult->setObjectName(QStringLiteral("tabResult"));
        horizontalLayout_5 = new QHBoxLayout(tabResult);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(tabResult);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(label_2);

        labelTime = new QLabel(tabResult);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        sizePolicy4.setHeightForWidth(labelTime->sizePolicy().hasHeightForWidth());
        labelTime->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(labelTime);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonRecheck = new QPushButton(tabResult);
        pushButtonRecheck->setObjectName(QStringLiteral("pushButtonRecheck"));

        horizontalLayout_3->addWidget(pushButtonRecheck);


        verticalLayout_2->addLayout(horizontalLayout_3);

        labelResult = new QLabel(tabResult);
        labelResult->setObjectName(QStringLiteral("labelResult"));
        labelResult->setMinimumSize(QSize(0, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        labelResult->setFont(font2);
        labelResult->setStyleSheet(QString::fromUtf8("font: 75 18pt \"\351\273\221\344\275\223\";"));
        labelResult->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelResult);

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
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(9);
        tableView_1->setFont(font3);

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
        tableView_2->setFont(font3);

        verticalLayout_11->addWidget(tableView_2);


        horizontalLayout_4->addWidget(groupBox1_2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_2);

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
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(comboBoxLineNo->sizePolicy().hasHeightForWidth());
        comboBoxLineNo->setSizePolicy(sizePolicy5);
        comboBoxLineNo->setMinimumSize(QSize(0, 0));

        horizontalLayout_11->addWidget(comboBoxLineNo);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);

        labelProgramName = new QLabel(tabQuery);
        labelProgramName->setObjectName(QStringLiteral("labelProgramName"));
        labelProgramName->setFont(font3);

        horizontalLayout_11->addWidget(labelProgramName);

        lineEditProgramName = new QLineEdit(tabQuery);
        lineEditProgramName->setObjectName(QStringLiteral("lineEditProgramName"));
        sizePolicy2.setHeightForWidth(lineEditProgramName->sizePolicy().hasHeightForWidth());
        lineEditProgramName->setSizePolicy(sizePolicy2);
        lineEditProgramName->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_11->addWidget(lineEditProgramName);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);

        buttonBoxQuery = new QDialogButtonBox(tabQuery);
        buttonBoxQuery->setObjectName(QStringLiteral("buttonBoxQuery"));
        sizePolicy2.setHeightForWidth(buttonBoxQuery->sizePolicy().hasHeightForWidth());
        buttonBoxQuery->setSizePolicy(sizePolicy2);
        buttonBoxQuery->setMaximumSize(QSize(200, 16777215));
        buttonBoxQuery->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Reset);

        horizontalLayout_11->addWidget(buttonBoxQuery);


        verticalLayout_3->addLayout(horizontalLayout_11);

        tableView = new QTableView(tabQuery);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_3->addWidget(tableView);


        horizontalLayout_6->addLayout(verticalLayout_3);

        tabWidget->addTab(tabQuery, QString());

        verticalLayout->addWidget(tabWidget);


        horizontalLayout_2->addLayout(verticalLayout);

        UniquenessCheckClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UniquenessCheckClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1057, 26));
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
        connDB->setText(QApplication::translate("UniquenessCheckClass", "DB Connected", 0));
        label_2->setText(QApplication::translate("UniquenessCheckClass", "Check Uniqueness at:", 0));
        labelTime->setText(QApplication::translate("UniquenessCheckClass", "TextLabel", 0));
        pushButtonRecheck->setText(QApplication::translate("UniquenessCheckClass", "Recheck", 0));
        labelResult->setText(QApplication::translate("UniquenessCheckClass", "The result is OK", 0));
        groupBox1->setTitle(QApplication::translate("UniquenessCheckClass", "Same Name Different Version:", 0));
        groupBox1_2->setTitle(QApplication::translate("UniquenessCheckClass", "Same Name In Same Line:     ", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabResult), QApplication::translate("UniquenessCheckClass", "Result", 0));
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
