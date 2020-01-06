#include "uniquenesscheck.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UniquenessCheck w;
	w.setWindowTitle("SMT Program Uniqueness Check Ver:1.0 2019.12.30");
	w.show();
	return a.exec();
}
