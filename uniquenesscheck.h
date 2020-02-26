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
#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include "ui_uniquenesscheck.h"

#define TOTALLINES 20  //SMT������

//�Զ����ѯģ��
class MySqlQueryModel:public QSqlQueryModel
{
public:
	explicit  MySqlQueryModel();
public:
	QVariant data(const QModelIndex &index, int role) const;
protected:
};

class UniquenessCheck : public QMainWindow
{
	Q_OBJECT

public:
	UniquenessCheck(QWidget *parent = 0);
	~UniquenessCheck();
	void ReadSettings();
	bool ConnectDatabase();
	bool DisplayResult(QString sqlQuerySameName, QString sqlQuerySameLine);
	QCompleter * wordListProgramName(QString lineNo);//���������Զ���ȫ�ֵ�

	void setWordList();
	void UpdateTime();
	void DecompressingFiles();
	void FindCrbFiles();
	void ReadCrbFiles(QString filePath, QString lineNo);
	void InsertData(QString prgName, QString prgVersion, QString lineNo, QString track);
	void ClearTable();//������ݿ�������
	void CheckActionOnce();//ִ��һ�μ�鶯��
	void OnRecheckButtonClicked();

	void QueryAllLineNo();
	void OnTabWidgetCurrentChanged(int idx);
	void OnButtonBoxQueryClicked(QAbstractButton *button);

private:
	Ui::UniquenessCheckClass ui;
	QSettings *config;
	QSqlDatabase accessDB;
	QLabel welcomeLabel;
	QLabel *currentTimeLabel;

	QString srcDir[TOTALLINES];


	//Access 2010
	QString accessDatabaseDir;
	QString accessDatabaseUID;
	QString accessDatabasePWD;
};

#endif // UNIQUENESSCHECK_H
