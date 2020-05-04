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
    void addFileInManager();
    void addFileInWatcher();
    void deleteFileFromManager();
    void deleteFileFromWatcher();
    void updateWatcherList();
    void renameWatcher();

};
#endif
// MAINWINDOW_H
