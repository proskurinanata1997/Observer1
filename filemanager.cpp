#include "filemanager.h"

FileManager::FileManager()
{
    connect(&timer_, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer_.start(1000);
}

int FileManager::findFile(QString name)
{
    for(int i=0; i<listFile_.size(); i++)
        if(listFile_[i].fileName()==name)
            return i;
    return -1;
}

void FileManager::deleteFile(QString name)
{
    int index_del=this->findFile(name);
    if (index_del==-1) return;
    listFile_.removeAt(index_del);
    length_.removeAt(index_del);
}

void FileManager::addFile(QString name)
{
    listFile_.append(QFileInfo(name));
    if (QFileInfo(name).exists())
        length_.append(QFileInfo(name).size());
    else
        length_.append(-1);
}

void FileManager::updateTime()
{

    for(int i=0; i<listFile_.size(); i++){
        listFile_[i].refresh();
        if ((listFile_[i].size())!=length_[i])
            changeIndex(i);
    }
}

void FileManager::changeIndex(int i)
{
    QString name = listFile_[i].absoluteFilePath();
    if (listFile_[i].exists())
        length_[i] = listFile_[i].size();
    else
        length_[i]=-1;
    emit changegWatcher(name, length_[i], listFile_[i].exists());
}

void FileManager::updateAll()
{
    for(int i=0; i<listFile_.size();i++)
        changeIndex(i);
}

FileManager *FileManager::instance = 0;
