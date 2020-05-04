#include "filemanager.h"

FileManager::FileManager()
{
    connect(&timer_, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer_.start(1000);
}

void FileManager::addFile(QString name)
{
    if (findFile(name)<0){
        QFileInfo f(name);
        listFile_.append(f);
        length_.append(returnFileSize(listFile_.size()-1));
    }
}

void FileManager::deleteFile(QString name)
{
    int indexDelete=findFile(name);
    if (indexDelete < 0) return;
    listFile_.removeAt(indexDelete);
    length_.removeAt(indexDelete);
}

void FileManager::deleteFile(int i)
{
    if (i < 0) return;
    listFile_.removeAt(i);
    length_.removeAt(i);
}

int FileManager::findFile(QString name)
{
    QFileInfo f(name);
    return FileManager::getNameList().indexOf(f.absoluteFilePath());
}

void FileManager::updateAll()
{
    for(int i=0; i<listFile_.size();i++)
        fileInformationUpdate(i);
}


int FileManager::returnFileSize(int i)
{
    listFile_[i].refresh();
    if (listFile_[i].exists())
        return (listFile_[i].size());
    else
        return (-1);
}

void FileManager::fileInformationUpdate(int i)
{
    if (i >= 0)
    {
        QString name = listFile_[i].absoluteFilePath();
        length_[i]=returnFileSize(i);
        emit changegWatcher(name, length_[i], listFile_[i].exists());
    }
}

void FileManager::updateTime()
{

    for(int i=0; i<listFile_.size(); i++){
        if (length_[i]!=returnFileSize(i))
            fileInformationUpdate(i);
    }
}

QStringList FileManager::getNameList()
{
    QStringList nameList;
    for(int i=0; i<listFile_.size(); i++)
            nameList.append(listFile_[i].absoluteFilePath()/* + QString::number(state[i])*/);
    return nameList;
}

FileManager *FileManager::instance = 0;


