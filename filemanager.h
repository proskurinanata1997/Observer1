#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QList>
#include <QTimer>
#include <QTime>
#include <QFileInfo>
#include <QString>
#include<iostream>
using namespace std;

class FileManager:public QObject
{
    Q_OBJECT
    FileManager();
    QList<QFileInfo> listFile_;
    QList<int> length_;
    QTimer timer_;
    static FileManager *instance;//единственный экземпляр
    ~FileManager(){delete instance;}
public:
    static FileManager *getInstance(){
        if (!instance)
            instance=new FileManager;
        return instance;
    }

    void addFile(QString);
    void deleteFile(QString);
    void deleteFile(int);
    int findFile(QString);
    void changeIndex(int);
    void updateAll();
    QStringList getNameList();
    int returnFileSize(int);

public slots:
void updateTime();

signals:
void changegWatcher(QString name, int length_, bool existence);
};

#endif // FILEMANAGER_H
