#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QDebug>

#include "globals.h"
#include "subwindow.h"

#define XBEGIN 150
#define YBEGIN 100

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openfile_clicked();

    void on_savefile_clicked();

    void textChangedFlag();

    void on_generate_Button_clicked();

private:
    Ui::MainWindow *ui;
    QString filepath;
    subWindow subwindow_01;
};

#endif // MAINWINDOW_H
