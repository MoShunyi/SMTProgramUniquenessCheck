#include "uniquenesscheck.h"
using namespace std;
UniquenessCheck::UniquenessCheck(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ReadSettings();
	ConnectDatabase();
	OnRecheckButtonClicked();
	welcomeLabel.setText(QStringLiteral("Welcome！"));
	ui.statusBar->addWidget(&welcomeLabel);

	//状态栏显示时间日期
	currentTimeLabel = new QLabel;
	QTimer *timer = new QTimer(this);
	timer->start(1000); // 每次发射timeout信号时间间隔为1秒
	ui.statusBar->addWidget(currentTimeLabel);
	connect(timer,&QTimer::timeout,this,&UniquenessCheck::UpdateTime);

	connect(ui.pushButtonRecheck, static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked), this, &UniquenessCheck::OnRecheckButtonClicked);
	//connect(ui.pushButtonRecheck, static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked), this, &UniquenessCheck::CheckActionOnce);
	connect(ui.buttonBoxQuery,&QDialogButtonBox::clicked,this,&UniquenessCheck::OnButtonBoxQueryClicked);

	//tabWidget标签切换信号
	connect(ui.tabWidget, static_cast<void (QTabWidget::*)(int)>(&QTabWidget::currentChanged), [=](int index){OnTabWidgetCurrentChanged(index);});

	//查询界面 字典设置随线别改变而改变
	connect(ui.comboBoxLineNo,static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), [=]{setWordList();});
}

MySqlQueryModel::MySqlQueryModel()
{

}

QVariant MySqlQueryModel::data(const QModelIndex &index, int role) const
{
	QVariant value = QSqlQueryModel::data(index, role);

	if(role == Qt::TextAlignmentRole)
	{
		//value = (Qt::AlignCenter);//居中对齐
		//return value;
		return QVariant(Qt::AlignCenter);
	}

	return value;
}
void UniquenessCheck::ReadSettings()
{
	config = new QSettings("config.ini",QSettings::IniFormat);

    for (int i = 0; i < TOTALLINES; i++)
    {
		srcDir[i] = config->value(QStringLiteral("SrcDir/SMT%1").arg(i)).toString();
		qDebug()<<srcDir[i];
    }
	accessDatabaseDir = config->value("Access/dbDir").toString();
	accessDatabaseUID = config->value("Access/userId").toString();
	accessDatabasePWD = config->value("Access/password").toString();
}

bool UniquenessCheck::ConnectDatabase()
{
	accessDB = QSqlDatabase::addDatabase("QODBC");
	accessDB.setDatabaseName(QString("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=%1;UID=%2;PWD=%3")
		.arg(accessDatabaseDir,accessDatabaseUID,accessDatabasePWD));

	if(!accessDB.open())                                  //打开数据库
	{
		qDebug()<<accessDB.lastError().text();
		QMessageBox::critical(0, QObject::tr("Database error"), accessDB.lastError().text());

		ui.connDB->setText("DB not Connected");
		ui.connDB->setStyleSheet("background-color:red");
		return false;                                   //打开失败
	}
	else
	{
		qDebug()<<"database open success!";
		ui.connDB->setText("DB is Connected");
		ui.connDB->setStyleSheet("background-color:green");
		return true;
	}
}

QCompleter * UniquenessCheck::wordListProgramName(QString lineNo)
{
	if (!accessDB.open())
	{
		ConnectDatabase();
	}

	QSqlQuery *QueryProgramName = new QSqlQuery(accessDB);
	QString sqlQueryProgramName;
	if (lineNo.isEmpty())
	{
		sqlQueryProgramName = QString(QStringLiteral("select programName from smtProgram group by programName"));
	} 
	else
	{
		sqlQueryProgramName = QString(QStringLiteral("select programName from smtProgram where lineNo = '%1' group by programName").arg(lineNo));
	}
	
	QueryProgramName->exec(sqlQueryProgramName);

	QStringList wordList;
	while(QueryProgramName->next())
	{
		//设置字典,自动补全提示
		wordList << QueryProgramName->value("programName").toString();

	}
	//qDebug()<<wordList;
	QCompleter *completer = new QCompleter(wordList, this);
	completer->setCaseSensitivity(Qt::CaseInsensitive);

	return completer;
}

void UniquenessCheck::setWordList()
{
	QString lineNo = ui.comboBoxLineNo->currentText();
	ui.lineEditProgramName->setCompleter(wordListProgramName(lineNo));
}

void UniquenessCheck::UpdateTime()
{
	QDateTime currentTime = QDateTime::currentDateTime();
	QString strTime = currentTime.toString(QStringLiteral("yyyy-MM-dd hh:mm:ss"));
	currentTimeLabel->setText(strTime);
	if (!strTime.right(8).compare("07:30:36"))
	{
		OnRecheckButtonClicked();
	}
}

void UniquenessCheck::DecompressingFiles()
{
	for (int i = 0; i < TOTALLINES; i++)
	{
		if (!srcDir[i].isNull())
		{
			std::string delCommand = QString(QStringLiteral("del /f /s /q PPDFolder\\SMT%1\\*.*").arg(i)).toStdString();
			//std::cout<<delCommand.c_str();
			system(delCommand.c_str());//清空PPDFolder文件夹
			std::string rarCommand = QString(QStringLiteral("WinRar x -or %1\\*.zip PPDFolder\\SMT%2\\").arg(srcDir[i]).arg(i)).toStdString();
			//std::cout<<rarCommand.c_str();
			system(rarCommand.c_str());//解压文件
		}
	}
}

//C++方式实现文件查找
//void UniquenessCheck::FindCrbFiles()
//{
//	struct _finddata_t fileinfo;
//	
//	for (int i = 0; i < TOTALLINES; i++)
//	{
//		if (!srcDir[i].isNull())
//		{
//			std::string lineNo = QStringLiteral("SMT%1").arg(i).toStdString();
//			std::string crbDir = "PPDFolder\\" + srcDir[i].toStdString();
//			std::string fileType = crbDir + "\\*.crb";
//			std::string fileName;
//			long handle;
//			if ((handle = _findfirst(fileType.c_str(),&fileinfo)) == -1L)
//			{
//				qDebug()<<"Not found .crb file";
//			} 
//			else
//			{
//				fileName = crbDir + "\\" + fileinfo.name;
//				ReadCrbFiles(fileName,lineNo);
//				while (!(_findnext(handle,&fileinfo)))
//				{
//					fileName = crbDir + "\\" + fileinfo.name;
//					ReadCrbFiles(fileName,lineNo);
//				}
//				_findclose(handle);
//			}
//		}
//	}
//}

void UniquenessCheck::FindCrbFiles()
{
	for (int i = 0; i < TOTALLINES; i++)
	{
		if (!srcDir[i].isNull())
		{
			QString lineNo = QString("SMT%1").arg(i);
			QString crbDir = QString("PPDFolder\\").append(lineNo);
			QDir dir = QDir(crbDir);
			QStringList nameFilters;
			nameFilters << "*.crb";
			dir.setNameFilters(nameFilters);
			QFileInfoList fileInfo = dir.entryInfoList(nameFilters);
			for (int j = 0; j<fileInfo.size(); j++)
			{
				QString filePath = fileInfo.at(j).filePath();
				//qDebug()<<filePath;
				ReadCrbFiles(filePath,lineNo);
			}

		}
	}
}

void UniquenessCheck::ReadCrbFiles(QString filePath,QString lineNo)
{
	QFile file(filePath);
	qDebug()<<file.fileName();
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug()<<"open file error"<<endl;
		return;
	}
	QTextStream in(&file);
	QString line = in.readLine();
	int flag = 0;
	while (!line.isNull()) 
	{
		if (!line.compare("[LotNames]"))
		{
			flag = 1;
		}
		if (!line.compare("[BoardData<1>]"))
		{
			flag = 0;
			return;
			//in.seek(file.size());//指针移到文件末尾
		}
		if (flag == 1)
		{
			QStringList list = line.split("\"",QString::SkipEmptyParts);
			qDebug()<<list.size();
			if (list.size() > 8)
			{
				QString prgName = list.at(1);
				QString prgTrack = list.at(4).trimmed().right(1);
				QString prgVersion = list.at(8);
				qDebug()<<prgName<<" "<<prgVersion<<" "<<prgTrack;
				InsertData(prgName,prgVersion,lineNo,prgTrack);
			}
			
		}
		line = in.readLine();
	}
}

void UniquenessCheck::InsertData(QString prgName, QString prgVersion, QString lineNo, QString track)
{
	if(!accessDB.open()) 
	{
		ConnectDatabase();
	}
	if (prgName.isEmpty() || prgVersion.isEmpty() || lineNo.isEmpty())
	{
		qDebug()<<"the value of prgName or prgVersion or lineNo is null";
		return;
	}
	QSqlDatabase::database().transaction();
	QSqlQuery *sqlQuery = new QSqlQuery(accessDB);
	QString strInsert = QString(QStringLiteral("insert into smtProgram(lineNo,programName,track,version) values ('%1','%2','%3','%4')")
		                .arg(lineNo,prgName,track,prgVersion));
	sqlQuery->exec(strInsert);
	if (sqlQuery->numRowsAffected() > 0)
	{
		qDebug()<<"Insert data successed!";
		QSqlDatabase::database().commit();
	} 
	else
	{
		qDebug()<<"Insert data failed!";
		QSqlDatabase::database().rollback();
	}

}

void UniquenessCheck::ClearTable()
{
	if(!accessDB.open()) 
	{
		ConnectDatabase();
	}
	QSqlDatabase::database().transaction();
	QSqlQuery *sqlQuery = new QSqlQuery(accessDB);
	QString strDelete = QString(QStringLiteral("delete * from smtProgram"));//删除表中数据
	QString strCounter = QString(QStringLiteral("alter table smtProgram alter column ID counter(1,1)")); //修正自增列
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

}

void UniquenessCheck::CheckActionOnce()
{
	QString strQuerySameName = QString(QStringLiteral("select lineNo, programName, track, version from smtProgram a where programName in (select programName "))
        .append(QStringLiteral(" from smtProgram b where a.programName = b.programName and a.version <> b.version and a.lineNo <> b.lineNo ) order by programName, lineNo"));//查找不同线同名不同版本
	//QString strQuerySameLine = QString(QStringLiteral("select lineNo, programName, version from smtProgram where programName in "))
	//	.append(QStringLiteral("( select programName from smtProgram group by lineNo, programName having count(*) > 1 ) order by programName,lineNo ")); //查找同线同名
	QString strQuerySameLine = QString(QStringLiteral("select lineNo, programName, track, version from smtProgram a where programName in (select programName "))
		.append(QStringLiteral(" from smtProgram b where a.programName = b.programName and a.version <> b.version and a.lineNo = b.lineNo ) order by programName, lineNo")); //查找同线同名不同版本
	if (DisplayResult(strQuerySameName,strQuerySameLine) == true)
	{
		ui.labelResult->setText(QString(QStringLiteral("The Result is NOK")));
		ui.labelResult->setStyleSheet("background-color:red");
	} 
	else
	{
		ui.labelResult->setText(QString(QStringLiteral("The Result is OK")));
		ui.labelResult->setStyleSheet("background-color:green");
	}
	QDateTime currentTime = QDateTime::currentDateTime();
	QString strTime = currentTime.toString(QStringLiteral("hh:mm:ss yyyy-MM-dd"));
	ui.labelTime->setText(strTime);
}

void UniquenessCheck::OnRecheckButtonClicked()
{
	ClearTable();
	DecompressingFiles();
	FindCrbFiles();
	CheckActionOnce();
}

bool UniquenessCheck::DisplayResult(QString sqlQuerySameName, QString sqlQuerySameLine)
{
	if(!accessDB.open()) 
	{
		ConnectDatabase();
	}
	MySqlQueryModel *model1 = new MySqlQueryModel();
	model1->setQuery(sqlQuerySameName,accessDB);
	MySqlQueryModel *model2 = new MySqlQueryModel();
	model2->setQuery(sqlQuerySameLine,accessDB);
	
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
	QSqlQuery *queryAllLineNo = new QSqlQuery(accessDB);
	QString sqlLineNo = QString(QStringLiteral("select lineNo from smtProgram group by lineNo order by lineNo"));
	ui.comboBoxLineNo->clear();
	ui.comboBoxLineNo->addItem("");
	queryAllLineNo->exec(sqlLineNo);
	while (queryAllLineNo->next())
	{
		ui.comboBoxLineNo->addItem(queryAllLineNo->value("lineNo").toString());
	}
}

void UniquenessCheck::OnTabWidgetCurrentChanged(int idx)
{
	switch (idx)
	{
	case 0:
		CheckActionOnce();
		break;
	case 1:
		QueryAllLineNo();
		setWordList();
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
		MySqlQueryModel *model = new MySqlQueryModel();
		model->setQuery(sqlQueryProgramName,accessDB);
		
		//model->setHeaderData(0, Qt::Horizontal, QStringLiteral("LineNo"));
		//model->setHeaderData(1, Qt::Horizontal, QStringLiteral("ProgramName"));
		//model->setHeaderData(2, Qt::Horizontal, QStringLiteral("Version"));

		QHeaderView *hor = ui.tableView->horizontalHeader();
		hor->setSectionResizeMode(QHeaderView::Inteivracte);//表头可调整列宽
		hor->setSectionResizeMode(QHeaderView::ResizeToContents);  //按内容调整表头大小
		hor->setStretchLastSection(true);//最后一列填满

		ui.tableView->verticalHeader()->hide();//隐藏垂直表头(行标)
		ui.tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行，填满整个表
		ui.tableView->setModel(model);
		ui.tableView->show();
		
	}
}
UniquenessCheck::~UniquenessCheck()
{

}
