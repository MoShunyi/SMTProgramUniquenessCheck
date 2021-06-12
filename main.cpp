#include "uniquenesscheck.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UniquenessCheck w;
	w.setWindowTitle("SMT Program Uniqueness Check Ver:2.01 2021-06-12");
	w.show();
	return a.exec();
}
