#include "mainwindow.h"
#include <QApplication>
#include <QList>
#include <QString>
#include <QObject>
#include <QThread>
#include "filemanager.h"
#include "filewatcher.h"
#include "QTimer"
#include <QSharedPointer>
#include <QPointer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
