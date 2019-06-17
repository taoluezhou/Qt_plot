#include "subwindow.h"
#include "ui_subwindow.h"

subWindow::subWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::subWindow)
{
    ui->setupUi(this);
    this->resize(600,400);
    setWindowTitle("plot");
    ui->drawing_01->setMinimumSize(4000,2000);
}

subWindow::~subWindow()
{
    delete ui;
}
