#include "uniquenesscheck.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UniquenessCheck w;
	w.setWindowTitle("SMT Program Uniqueness Check Ver:1.01 2020.02.26");
	w.show();
	return a.exec();
}
