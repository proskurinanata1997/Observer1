#include "filewatcher.h"

FileWatcher::FileWatcher(QString name)
{
    fileName_=name;
    length_=-1;
    existFile_=0;
}

FileWatcher::FileWatcher(const FileWatcher &another)
{
    fileName_=another.fileName_;
    length_=another.length_;
    existFile_=another.existFile_;
}

FileWatcher::FileWatcher()
{
    fileName_="";
    length_=-1;
    existFile_=false;
}

QString FileWatcher::outputWatcher()
{
    cout<<"\n";
    QString print("\nname: ");
    print += fileName_ + QString("\nsize:") + QString::number(length_) + QString("\nexistence: ") + QString::number(existFile_);
    return print;
}

void FileWatcher::changeStateWatcher(QString name, int length, bool existence)
{
    if (name==fileName_)
    {
        if (existence)
            length_=length;
        else
            length=0;
        existFile_=existence;
        emit updateSignal();
    }
}

void FileWatcher::renameFile(QString newName)
{
    fileName_ = newName;
}

QString FileWatcher::getNameFile()
{
    return fileName_;
}
