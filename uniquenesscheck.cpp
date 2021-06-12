#include "uniquenesscheck.h"
using namespace std;
UniquenessCheck::UniquenessCheck(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    loadingWidget = nullptr;
    timer = new QTimer(this);
    timing = new QTimer(this);
    model1 = new MySqlQueryModel();
    model2 = new MySqlQueryModel();
    queryModel = new MySqlQueryModel();
    completer = nullptr;

	ReadSettings();
	ConnectDatabase();
	
    okIcon.load(":/UniquenessCheck/Resources/icon-ok.png");
    failIcon.load(":/UniquenessCheck/Resources/icon-fail.png");
	

    QStringList intervalList = interval.split(",");
    ui.comboBoxInterval->clear();
    for (int i = 0; i < intervalList.size(); i++)
    {
        ui.comboBoxInterval->addItem(intervalList.at(i));
    }

    ui.buttonBoxQuery->button(QDialogButtonBox::Ok)->setText(QStringLiteral("确定")); // 将buttonbox中的ok汉化
    ui.buttonBoxQuery->button(QDialogButtonBox::Reset)->setText(QStringLiteral("重置"));

    connect(ui.pushButtonWriteOnce, &QPushButton::clicked, this, &UniquenessCheck::OnPushButtonWriteOnceClicked);
    connect(ui.pushButtonAutoWrite, &QPushButton::clicked, this, &UniquenessCheck::OnPushButtonAutoWriteClicked);
	connect(ui.buttonBoxQuery, &QDialogButtonBox::clicked, this, &UniquenessCheck::OnButtonBoxQueryClicked);
    connect(this, &UniquenessCheck::StartCheck, this, &UniquenessCheck::ShowLoadingWidget);
    connect(this, &UniquenessCheck::CheckFinished, this, &UniquenessCheck::CloseLoadingWidget);
	//tabWidget标签切换信号
	connect(ui.tabWidget, static_cast<void (QTabWidget::*)(int)>(&QTabWidget::currentChanged), [=](int index){OnTabWidgetCurrentChanged(index);});

	//查询界面 字典设置随线别改变而改变
    connect(ui.comboBoxLineNo, &QComboBox::currentTextChanged, [=](){OnComboBoxLineNoCurrentTextChanged();});
	//connect(ui.comboBoxLineNo,static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), [=]{setWordList();});

    connect(timer, &QTimer::timeout, 
        [=]()
    {
        if (loadingWidget == nullptr)
        {
            OnPushButtonWriteOnceClicked();
        } 
        else if (!loadingWidget->isVisible())
        {
            OnPushButtonWriteOnceClicked();
        }
    });

    connect(timing, &QTimer::timeout,
        [=]()
    {
        if (remainSec == 0)
        {
            remainSec = intervalSec;
        }
        int hh = remainSec / 3600;
        int mm = (remainSec % 3600) / 60;
        int ss = remainSec % 60;
        QString text = QStringLiteral("自动检查已设置，距离下次检查还有: ");
        text.append(QString("  %1 hh").arg(hh, 2, 10, QLatin1Char('0')));
        text.append(QString(" %1 mm").arg(mm, 2, 10, QLatin1Char('0')));
        text.append(QString(" %1 ss").arg(ss, 2, 10, QLatin1Char('0')));
        ui.labelTiming->setText(text);
        ui.labelTiming->setStyleSheet(QStringLiteral("font: 75 14pt \"微软雅黑\";background-color:green"));
        remainSec--;
    });
}

UniquenessCheck::~UniquenessCheck()
{
    delete model1;
    delete model2;
    delete queryModel;
    delete completer;
}

MySqlQueryModel::MySqlQueryModel()
{

}

MySqlQueryModel::~MySqlQueryModel()
{

}

QVariant MySqlQueryModel::data(const QModelIndex &index, int role) const
{
	QVariant value = QSqlQueryModel::data(index, role);

	if(role == Qt::TextAlignmentRole)
	{
        value = Qt::AlignCenter; // 居中对齐
        return value;
	}

	return value;
}

void UniquenessCheck::ReadSettings()
{
    config = new QSettings("config.ini", QSettings::IniFormat);
    totalLines = config->value("/TotalLines/TotalLines").toInt();
    interval = config->value("/TotalLines/interval").toString();
    for (int i = 1; i <= totalLines; i++)
    {
        srcDirMap[QString("SMT%1").arg(i, 2, 10, QLatin1Char('0'))] = config->value(QStringLiteral("SrcDir/SMT%1")
            .arg(i, 2, 10, QLatin1Char('0'))).toString();	
    }
    
	accessDatabaseDir = config->value("Access/dbDir").toString();
	accessDatabaseUID = config->value("Access/userId").toString();
	accessDatabasePWD = config->value("Access/password").toString();
    delete config;
}

bool UniquenessCheck::ConnectDatabase()
{
	accessDB = QSqlDatabase::addDatabase("QODBC");
	accessDB.setDatabaseName(QString("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=%1;UID=%2;PWD=%3")
		.arg(accessDatabaseDir,accessDatabaseUID,accessDatabasePWD));

	if(!accessDB.open()) 
	{
		qDebug()<<accessDB.lastError().text();
		QMessageBox::critical(this, QObject::tr("Database error"), accessDB.lastError().text(), QMessageBox::Yes);

		ui.connDB->setText("DB NG");
		ui.connDB->setStyleSheet("font: 75 16pt;background-color:red");
		return false;
	}
	else
	{
		ui.connDB->setText("DB OK");
		ui.connDB->setStyleSheet("font: 75 16pt;background-color:green");
		return true;
	}
}

void UniquenessCheck::DecompressingFiles()
{
    for (int i = 1; i <= totalLines; i++)
    {
        if (!srcDirMap.value(QString("SMT%1").arg(i, 2, 10, QLatin1Char('0'))).isEmpty())
        {
            std::string delCommand = QString(QStringLiteral("del /f /s /q PPDFolder\\SMT%1\\*.*")
                .arg(i, 2, 10, QLatin1Char('0'))).toStdString();
            system(delCommand.c_str()); // 清空PPDFolder文件夹
            std::string rarCommand = QString(QStringLiteral("WinRar x -or -y %1\\*.zip PPDFolder\\SMT%2\\")
                .arg(srcDirMap[QString("SMT%1").arg(i, 2, 10, QLatin1Char('0'))])
                .arg(i, 2, 10, QLatin1Char('0'))).toStdString();
            system(rarCommand.c_str()); // 解压文件
        }
    }
}


void UniquenessCheck::FindCrbFiles(QFileInfoList &fileInfo, QString lineNo)
{
    QString crbDir = QString("PPDFolder\\").append(lineNo);
    QDir dir = QDir(crbDir);
    QStringList nameFilters;
    nameFilters << "*.crb";
    dir.setNameFilters(nameFilters);
    fileInfo = dir.entryInfoList(nameFilters);
}

void UniquenessCheck::ReadCrbFiles(QString filePath, QStringList &insertDataList)
{
	QFile file(filePath);
	qDebug()<<file.fileName();
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
        QMessageBox mb;
        mb.setIcon(QMessageBox::Critical);
        mb.setIconPixmap(failIcon);
        mb.setText(QStringLiteral("<font size = 6>文件%1打开失败！</font>").arg(filePath));
        mb.exec();
		return;
	}
	QTextStream in(&file);
	int flag = 0;
	while (!in.atEnd()) 
	{
        QString line = in.readLine();
		if (!line.compare("[LotNames]"))
		{
			flag = 1;
            in.readLine();
            continue;
		}
		if (!line.compare("[BoardData<1>]"))
		{
			flag = 0;
			return;
			//in.seek(file.size());//指针移到文件末尾
		}
		if (flag == 1)
		{
			QStringList list = line.split(" ", QString::KeepEmptyParts);
			qDebug()<<list.size();
			if (list.size() > 11)
			{
				QString prgName = list.at(2);
                prgName.replace("\"", "");
				QString prgTrack = list.at(7);
				QString prgVersion = list.at(11);
                prgVersion.replace("\"", "");
				qDebug()<<prgName<<" "<<prgVersion<<" "<<prgTrack;
                QString insertRecord = prgName + ";" + prgTrack + ";" + prgVersion;
				insertDataList.append(insertRecord);
			}
		}
	}
    file.close();
}

void UniquenessCheck::InsertData(QStringList &insertDataList, QString lineNo)
{
	if (insertDataList.isEmpty() || lineNo.isEmpty())
	{
		qDebug()<<"the value of insertDataList or lineNo is null";
		return;
	}
    if(!accessDB.open()) 
    {
        ConnectDatabase();
    }
	QSqlDatabase::database().transaction();
    int flag = 0;
	QSqlQuery *sqlQuery = new QSqlQuery(accessDB);
    for (int i = 0; i < insertDataList.size(); i++)
    {
        QStringList list = insertDataList.at(i).split(";");
        if (list.size() < 3)
        {
            continue;
        }
        QString prgName = list.at(0);
        QString prgTrack = list.at(1);
        QString prgVersion = list.at(2);
        QString strInsert = QString(QStringLiteral("insert into smtProgram(lineNo, programName, track, version) values ('%1','%2','%3','%4')")
            .arg(lineNo, prgName, prgTrack, prgVersion));
        sqlQuery->exec(strInsert);
        if (sqlQuery->numRowsAffected() == 0 || sqlQuery->numRowsAffected() == -1)
        {
            flag = -1;
            QFile log("./log/errorLog.txt");
            log.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
            QString strLog = QDateTime::currentDateTime().toString() + strInsert + "\n" + sqlQuery->lastError().text();
            QByteArray byteLog(strLog.toLocal8Bit());
            log.write(byteLog);
            log.close();
        }
    }
	
	if (flag == -1)
	{
        qDebug()<<"Insert data failed!";
        QSqlDatabase::database().rollback();
		
	} 
	else
	{
        qDebug()<<"Insert data successed!";
        QSqlDatabase::database().commit();
	}
    delete sqlQuery;
}

void UniquenessCheck::ClearTable()
{
	if(!accessDB.open()) 
	{
		ConnectDatabase();
	}
	QSqlDatabase::database().transaction();
	QSqlQuery *sqlQuery = new QSqlQuery(accessDB);
	QString strDelete = QString(QStringLiteral("delete * from smtProgram")); // 删除表中数据
	QString strCounter = QString(QStringLiteral("alter table smtProgram alter column ID counter(1,1)")); // 修正自增列
	sqlQuery->exec(strDelete);
	if (sqlQuery->numRowsAffected() > 0)
	{
		qDebug()<<"Clear table successed!";
		qDebug()<<strCounter;
		sqlQuery->exec(strCounter);
		QSqlDatabase::database().commit();
	} 
	else
	{
		qDebug()<<"Clear table failed!";
		QSqlDatabase::database().rollback();
	}
    delete sqlQuery;
}

void UniquenessCheck::CheckActionOnce()
{
	QString strQuerySameName = QString(QStringLiteral("select lineNo, programName, track, version from smtProgram a where programName in (select programName "))
        .append(QStringLiteral(" from smtProgram b where a.programName = b.programName and a.version <> b.version and a.lineNo <> b.lineNo ) order by programName, lineNo"));//查找不同线同名不同版本
	//QString strQuerySameLine = QString(QStringLiteral("select lineNo, programName, version from smtProgram where programName in "))
	//	.append(QStringLiteral("( select programName from smtProgram group by lineNo, programName having count(*) > 1 ) order by programName,lineNo ")); //查找同线同名
	QString strQuerySameLine = QString(QStringLiteral("select lineNo, programName, track, version from smtProgram a where programName in (select programName "))
		.append(QStringLiteral(" from smtProgram b where a.programName = b.programName and a.version <> b.version and a.lineNo = b.lineNo ) order by programName, lineNo")); //查找同线同名不同版本
	if (DisplayResult(strQuerySameName, strQuerySameLine) == true)
	{
        QMessageBox mb;
        mb.setIcon(QMessageBox::Critical);
        mb.setIconPixmap(failIcon);
        mb.setText(QStringLiteral("<font size = 6>程序版本异常!(%1)</font>").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
        ui.labelTiming->setStyleSheet(QStringLiteral("font: 75 14pt \"微软雅黑\";background-color:red"));
        mb.exec();
        emit CheckFinished();
	} 
	else
	{
        QMessageBox mb;
        mb.setIcon(QMessageBox::Information);
        mb.setIconPixmap(okIcon);
        mb.setText(QStringLiteral("<font size = 6>检查完成，程序版本正常(%1)</font>").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
        ui.labelTiming->setStyleSheet(QStringLiteral("font: 75 14pt \"微软雅黑\";background-color:green"));
        mb.exec();
        emit CheckFinished();
	}
}

void UniquenessCheck::OnPushButtonWriteOnceClicked()
{
    emit StartCheck();

    ClearTable();
    DecompressingFiles();
    QMapIterator<QString, QString> i(srcDirMap);
    while (i.hasNext())
    {
        i.next();
        if (i.value().isEmpty())
        {
            continue;
        }
        QString lineNo = i.key();
        QFileInfoList fileInfo;
        FindCrbFiles(fileInfo, lineNo);
        for (int j = 0; j < fileInfo.size(); j++)
        {
            QString filePath = fileInfo.at(j).filePath();
            QString fileName = fileInfo.at(j).baseName();
            QStringList insertDataList;
            ReadCrbFiles(filePath, insertDataList);
            InsertData(insertDataList, lineNo);
        }
    }
    
    CheckActionOnce();
}
    
void UniquenessCheck::OnPushButtonAutoWriteClicked()
{
    int h = ui.comboBoxInterval->currentText().toInt();
    if (timer->isActive())
    {
        timer->stop();
    }
    timer->setInterval(60 * 60 * 1000 * h);
    timer->start();

    if (timing->isActive())
    {
        timing->stop();
    }
    timing->setInterval(1000);
    intervalSec = h * 60 * 60;
    remainSec = intervalSec;
    timing->start();
}
bool UniquenessCheck::DisplayResult(QString sqlQuerySameName, QString sqlQuerySameLine)
{
	if(!accessDB.open()) 
	{
		ConnectDatabase();
	}
	
	model1->setQuery(sqlQuerySameName, accessDB);
	model2->setQuery(sqlQuerySameLine, accessDB);
	
	bool returnFlag;
	if (model1->rowCount() > 0 || model2->rowCount() > 0)
	{
		returnFlag = true;
	} 
	else
	{
		returnFlag = false;
	}
	
	model1->setHeaderData(0, Qt::Horizontal, QStringLiteral("LineNo"));
	model1->setHeaderData(1, Qt::Horizontal, QStringLiteral("ProgramName"));
	model1->setHeaderData(2, Qt::Horizontal, QStringLiteral("Track"));
	model1->setHeaderData(3, Qt::Horizontal, QStringLiteral("Version"));

	QHeaderView *hor1 = ui.tableView_1->horizontalHeader();
	hor1->setSectionResizeMode(QHeaderView::Inteivracte);//表头可调整列宽
	hor1->setSectionResizeMode(QHeaderView::ResizeToContents);  //按内容调整表头大小
	hor1->setStretchLastSection(true);//最后一列填满

	ui.tableView_1->verticalHeader()->hide();//隐藏垂直表头(行标)
	ui.tableView_1->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行，填满整个表
	ui.tableView_1->setModel(model1);
	ui.tableView_1->show();

	
	model2->setHeaderData(0, Qt::Horizontal, QStringLiteral("LineNo"));
	model2->setHeaderData(1, Qt::Horizontal, QStringLiteral("ProgramName"));
	model2->setHeaderData(2, Qt::Horizontal, QStringLiteral("Track"));
	model2->setHeaderData(3, Qt::Horizontal, QStringLiteral("Version"));
	QHeaderView *hor2 = ui.tableView_2->horizontalHeader();
	hor2->setSectionResizeMode(QHeaderView::Inteivracte);//表头可调整列宽
	hor2->setSectionResizeMode(QHeaderView::ResizeToContents);  //按内容调整表头大小
	hor2->setStretchLastSection(true);//最后一列填满

	ui.tableView_2->verticalHeader()->hide();//隐藏垂直表头(行标)
	ui.tableView_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行，填满整个表
	ui.tableView_2->setModel(model2);
	ui.tableView_2->show();
	
	return returnFlag;
}

void UniquenessCheck::QueryAllLineNo()
{
	if (!accessDB.open())
	{
		ConnectDatabase();
	}
	QSqlQuery *sqlQurey = new QSqlQuery(accessDB);
	QString sqlLineNo = QString(QStringLiteral("select lineNo from smtProgram group by lineNo order by lineNo"));
	ui.comboBoxLineNo->clear();
	ui.comboBoxLineNo->addItem("");
	sqlQurey->exec(sqlLineNo);
	while (sqlQurey->next())
	{
		ui.comboBoxLineNo->addItem(sqlQurey->value("lineNo").toString());
	}
    delete sqlQurey;
}

void UniquenessCheck::OnTabWidgetCurrentChanged(int idx)
{
	switch (idx)
	{
	case 0:
        workerThread.wait(50);
        ui.tableView_1->setModel(model1);
        ui.tableView_1->show();
        ui.tableView_2->setModel(model2);
        ui.tableView_2->show();
		break;
	case 1:
		QueryAllLineNo();
		OnComboBoxLineNoCurrentTextChanged();
        ui.tableView->setModel(queryModel);
        ui.tableView->show();
		break;
	}
}

void UniquenessCheck::OnButtonBoxQueryClicked(QAbstractButton *button)
{
	if (button == ui.buttonBoxQuery->button(QDialogButtonBox::Reset))
	{
		ui.comboBoxLineNo->setCurrentIndex(0);
		ui.lineEditProgramName->setText("");
		return;
	}

	if (button == ui.buttonBoxQuery->button(QDialogButtonBox::Ok))
	{
		if(!accessDB.open()) 
		{
			ConnectDatabase();
		}
		QString lineNo = ui.comboBoxLineNo->currentText().trimmed();
		QString programName = ui.lineEditProgramName->text().trimmed();
		QString sqlQueryProgramName;
		if (lineNo.isEmpty())
		{
			sqlQueryProgramName = QString(QStringLiteral("select * from smtProgram where programName like '%%%1%%'order by ID, lineNo, programName").arg(programName));
		} 
		else
		{
			sqlQueryProgramName = QString(QStringLiteral("select * from smtProgram where lineNo = '%1' and programName like '%%%2%%' order by ID,lineNo, programName").arg(lineNo).arg(programName));
		}
		queryModel->setQuery(sqlQueryProgramName, accessDB);
		
		//model->setHeaderData(0, Qt::Horizontal, QStringLiteral("LineNo"));
		//model->setHeaderData(1, Qt::Horizontal, QStringLiteral("ProgramName"));
		//model->setHeaderData(2, Qt::Horizontal, QStringLiteral("Version"));

		QHeaderView *hor = ui.tableView->horizontalHeader();
		hor->setSectionResizeMode(QHeaderView::Inteivracte);//表头可调整列宽
		hor->setSectionResizeMode(QHeaderView::ResizeToContents);  //按内容调整表头大小
		hor->setStretchLastSection(true);//最后一列填满

		ui.tableView->verticalHeader()->hide();//隐藏垂直表头(行标)
		ui.tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行，填满整个表
		ui.tableView->setModel(queryModel);
		ui.tableView->show();
		
	}
}

void UniquenessCheck::OnComboBoxLineNoCurrentTextChanged()
{
    if (!accessDB.open())
    {
        ConnectDatabase();
    }
    QString lineNo = ui.comboBoxLineNo->currentText();
    QSqlQuery *sqlQuery = new QSqlQuery(accessDB);
    QString sqlQueryProgramName;
    if (lineNo.isEmpty())
    {
        sqlQueryProgramName = QString(QStringLiteral("select programName from smtProgram group by programName"));
    } 
    else
    {
        sqlQueryProgramName = QString(QStringLiteral("select programName from smtProgram where lineNo = '%1' group by programName").arg(lineNo));
    }

    sqlQuery->exec(sqlQueryProgramName);

    QStringList wordList;
    while(sqlQuery->next())
    {
        //设置字典,自动补全提示
        wordList << sqlQuery->value("programName").toString();

    }

    if (completer != nullptr)
    {
        delete completer;
        completer = nullptr;
    }
    completer = new QCompleter(wordList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    completer->setFilterMode(Qt::MatchContains);
    ui.lineEditProgramName->setCompleter(completer);

    delete sqlQuery;
}

void UniquenessCheck::ShowLoadingWidget()
{
    loadingWidget = new LoadingWidget(this);
    loadingWidget->setWindowModality(Qt::WindowModal);
    loadingWidget->show();
}

void UniquenessCheck::CloseLoadingWidget()
{
    if (loadingWidget->isVisible())
    {
        loadingWidget->close();
        delete loadingWidget;
        loadingWidget = nullptr;
    }
}

