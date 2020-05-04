#include <QCoreApplication>
#include "filemanager.h"
#include "filewatcher.h"
#include <QList>
#include <QString>
#include "QTimer"
#include <QSharedPointer>
#include <QPointer>
#include <QObject>
#include <QThread>
QList<FileWatcher> listWatcher;
QTimer timer;


void connectWatcher()
{
    for (int i=0; i<listWatcher.size(); i++)
        QObject :: connect(FileManager::getInstance(), &FileManager::changegWatcher, &(listWatcher[i]), &FileWatcher::change);
    FileManager::getInstance()->updateAll();
}

void outputListWatcher()
{
    cout<<"\n";
    for (int i=0; i<listWatcher.size(); i++)
        cout<<(listWatcher[i]).outputWatcher().toStdString();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileManager *F = FileManager::getInstance();
    listWatcher.append(FileWatcher("E:/QtProject/lab/labaone-dev/trew.txt"));
    listWatcher.append(FileWatcher("E:/QtProject/lab/labaone-dev/treww.txt"));
    listWatcher.append(FileWatcher("E:/QtProject/lab/labaone-dev/trewww.txt"));
    F->addFile("E:/QtProject/lab/labaone-dev/trew.txt");
    F->addFile("E:/QtProject/lab/labaone-dev/treww.txt");
    F->addFile("E:/QtProject/lab/labaone-dev/trewww.txt");
    connectWatcher();

    outputListWatcher();
    timer.setInterval(5000);
    QObject::connect(&timer, &QTimer::timeout, outputListWatcher);
    timer.start();
    listWatcher.removeAt(0);
    listWatcher[0].changeFile("E:/QtProject/lab/labaone-dev/treww1.txt");
    QFile file("E:/QtProject/lab/labaone-dev/trewww.txt");
    file.open(QIODevice::Append);
    file.write("mana11mama");
    file.close();
    return a.exec();
}
