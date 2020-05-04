#include "filewatcher.h"

FileWatcher::FileWatcher(QString name)
{
    fileName_=name;
}

FileWatcher::FileWatcher()
{
    fileName_="";
    length_=-1;
    existFile_=false;
}

FileWatcher::FileWatcher(const FileWatcher &another)
{
    fileName_=another.fileName_;
    length_=another.length_;
    existFile_=another.existFile_;
}

QString FileWatcher::outputWatcher()
{
    cout<<"\n";
    QString print("\nname: ");
   print += fileName_ + QString("\nsize:") + QString::number(length_) + QString("\nexistence: ") + QString::number(existFile_);
    return print;
}

void FileWatcher::changeFile(const char *newName)
{
  fileName_=newName;
}

void FileWatcher::change(QString name, int length, bool existence)
{
    if (name==fileName_)
    {
        if (existence)
            length_=length;
        else
            length_=0;
        existFile_=existence;
    }
}

