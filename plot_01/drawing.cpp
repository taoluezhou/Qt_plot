#include "drawing.h"
#include "ui_drawing.h"

drawing::drawing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drawing)
{
    ui->setupUi(this);


}

drawing::~drawing()
{
    delete ui;
}


