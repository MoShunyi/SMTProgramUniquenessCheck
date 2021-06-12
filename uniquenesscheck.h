#ifndef UNIQUENESSCHECK_H
#define UNIQUENESSCHECK_H

#include <QtWidgets/QMainWindow>
#include <QSettings>
#include <QMessageBox>
#include <QPushButton>
#include <QTimer>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QFileInfo>
#include <QDir>
#include <QFileInfoList>
#include <QStringList>
#include <QCompleter>
#include <QThread>
#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include "ui_uniquenesscheck.h"
#include "loadingwidget.h"

//自定义查询模型
class MySqlQueryModel:public QSqlQueryModel
{
public:
	explicit  MySqlQueryModel();
    ~MySqlQueryModel();
public:
	QVariant data(const QModelIndex &index, int role) const;
protected:
};

class UniquenessCheck : public QMainWindow
{
	Q_OBJECT
    QThread workerThread;
public:
	UniquenessCheck(QWidget *parent = 0);
	~UniquenessCheck();
	void ReadSettings();
	bool ConnectDatabase();
	bool DisplayResult(QString sqlQuerySameName, QString sqlQuerySameLine);

	
	void DecompressingFiles();
	void FindCrbFiles(QFileInfoList &fileInfo, QString lineNo);
	void ReadCrbFiles(QString filePath, QStringList &insertDataList);
	void InsertData(QStringList &insertDataList, QString lineNo);
	void ClearTable(); // 清除数据库表格内容
	void CheckActionOnce(); // 执行一次检查动作

signals:
    void StartCheck();
    void CheckFinished();
public slots:
	void OnPushButtonWriteOnceClicked();
    void OnPushButtonAutoWriteClicked();
	void QueryAllLineNo();
	void OnTabWidgetCurrentChanged(int idx);
	void OnButtonBoxQueryClicked(QAbstractButton *button);
    void OnComboBoxLineNoCurrentTextChanged();
    void ShowLoadingWidget();
    void CloseLoadingWidget();

private:
	Ui::UniquenessCheckClass ui;
	QSettings *config;
	LoadingWidget *loadingWidget;
	QLabel welcomeLabel;
    QPixmap okIcon;
    QPixmap failIcon;
	QLabel *currentTimeLabel;

    QTimer *timer;  // 定时自动循环检查
    QTimer *timing; // 倒计时
    int remainSec;    // 倒计时剩余（秒）
    int intervalSec;  // 时间间隔（秒）
    int totalLines; 

    QString interval; // 监控时间间隔(小时) 
    QMap<QString, QString> srcDirMap; // "线别，PPD文件路径"，例："SMT14, \\174.36.151.193\PPDFolder\743A6568AA7B"
    QStringList insertDataList; // "prgName, prgVersion, lineNo, track"

	// Access 2010
    QSqlDatabase accessDB;
	QString accessDatabaseDir;
	QString accessDatabaseUID;
	QString accessDatabasePWD;

    MySqlQueryModel *model1;
    MySqlQueryModel *model2;
    MySqlQueryModel *queryModel;
    QCompleter *completer;
};

#endif // UNIQUENESSCHECK_H
