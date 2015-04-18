#include <QApplication>

#include "gui/mainwindow.h"

//#include "scenes/example.cpp"
#include "scenes/dance.cpp"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QCoreApplication::setOrganizationName("turlicht");
	QCoreApplication::setOrganizationDomain("turlicht.tk");
	QCoreApplication::setApplicationName("Scenery");

    Manager_ project;
    project.init();
    MainWindow mainWindow(&project);
    mainWindow.show();
    return a.exec();
}
