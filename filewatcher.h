#ifndef FILEWATCHER_H
#define FILEWATCHER_H
#include <QList>
#include <QObject>
#include <QFile>
#include <QString>
#include<iostream>
using namespace std;

class FileWatcher: public QObject
{
    Q_OBJECT
    QString fileName_;
    int length_;
    bool existFile_;
public:
    FileWatcher(QString);
    FileWatcher();
    QString outputWatcher();
    void renameFile(QString);
    FileWatcher(const FileWatcher &another);
    FileWatcher &operator=(const FileWatcher &another);
   ~FileWatcher(){}
    QString getNameFile();
public slots:

void change(QString name, int length_, bool existence);

signals:
    void updateSignal();
};

#endif
// FILEWATCHER_H
