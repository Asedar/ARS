#include "mainwindow.h"
#include <QApplication>

#include "WordProcessingCompiler.h"
using namespace DocxFactory;

int main(int argc, char *argv[])
{
	

			

	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
