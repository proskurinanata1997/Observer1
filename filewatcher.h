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
    FileWatcher(const FileWatcher &another);
    FileWatcher &operator=(const FileWatcher &another);
    QString outputWatcher();
    void changeFile(const char*);
    ~FileWatcher(){}

public slots:

    void change(QString name, int length_, bool existence);
};

#endif // FILEWATCHER_H
