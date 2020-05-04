#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addFileInManager()
{
    if (!((ui->lineEditManager->text()).isEmpty()))
    {
        QFileInfo file(ui->lineEditManager->text());
        FileManager::getInstance()->addFile(ui->lineEditManager->text());
        updateManager();
        for(int i=0; i<listWatcher.size();i++)
        {
            if(listWatcher[i].getNameFile()==file.absoluteFilePath())
                listWatcher[i].change(file.absoluteFilePath(), file.size(),file.exists());
        }
    }
}

void MainWindow::addFileInWatcher()
{
    if (!((ui->lineEditWatcher->text()).isEmpty()))
    {
        listWatcher.append(FileWatcher(ui->lineEditWatcher->text()));
        QObject :: connect(FileManager::getInstance(), &FileManager::changegWatcher, &(listWatcher.last()), &FileWatcher::change);
        FileManager::getInstance()->changeIndex(FileManager::getInstance()->findFile(ui->lineEditWatcher->text()));
        //FManager::getInstance()->updateAll();
        updateWatcherList();
        QObject :: connect(&(listWatcher.last()), &FileWatcher::updateSignal, this, &MainWindow::updateWatcherList);
    }
}

void MainWindow::deleteFileFromManager()
{
    int i=ui->listWidgetManager->currentRow();
    FileManager::getInstance()->deleteFile(i);
    updateManager();
}

void MainWindow::deleteFileFromWatcher()
{
    int i=ui->listWidgetWatcher->currentRow();
    listWatcher.removeAt(i);
    updateWatcherList();
}

void MainWindow::renameWatcher()
{
    int i=ui->listWidgetWatcher->currentRow();
    if (i>=0 && !(ui->lineEditWatcher->text()).isEmpty())
    listWatcher[i].renameFile(ui->lineEditWatcher->text());
    FileManager::getInstance()->changeIndex(FileManager::getInstance()->findFile(ui->lineEditWatcher->text()));
    updateWatcherList();
}

void MainWindow::updateManager()
{
    ui->listWidgetManager->clear();
    ui->listWidgetManager->addItems(FileManager::getInstance()->getNameList());
}

void MainWindow::updateWatcherList()
{
    int i = ui->listWidgetWatcher->currentRow();
    ui->listWidgetWatcher->clear();
    for(int i=0; i<listWatcher.size(); i++)
        ui->listWidgetWatcher->addItem(listWatcher[i].outputWatcher());
    ui->listWidgetWatcher->setCurrentRow(i);
}

