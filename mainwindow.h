#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "filemanager.h"
#include "filewatcher.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    void updateManager();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<FileWatcher> listWatcher;

public slots:
    void addFileManager();
    void addFileWatcher();
    void deleteFileManager();
    void deleteFileWatcher();
    void updateWatcher();
    void renameWatcher();

};
#endif
// MAINWINDOW_H
