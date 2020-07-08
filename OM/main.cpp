#include "OM.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OM w;
	w.show();
	return a.exec();
}
