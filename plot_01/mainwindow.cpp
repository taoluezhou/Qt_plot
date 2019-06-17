#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::textChangedFlag()
{
    ui->savefile->setText("*保存文件");
}

void MainWindow::on_openfile_clicked()
{
    globals::transitionList.clear();
    globals::placeList.clear();
    filepath = QFileDialog::getOpenFileName(this,"open","../data/","TXT(*.txt)");
    if(filepath.isEmpty()==false)
    {
        QFile file(filepath);
        bool isOK=file.open(QIODevice::ReadOnly);
        if(isOK==true)
        {
            QByteArray array;
            while(file.atEnd()==false)
            {
                QByteArray array_l=file.readLine();
                array+=array_l;
                QString thisLine=QString(array_l);
                if(thisLine[0]=='P')
                {
                    struct Placeplot newplace;
                    QStringList thislinelist=thisLine.split(" ");
                    //qDebug()<<thislinelist;
                    newplace.name=thislinelist[0];
                    for(int i=1;i<thislinelist.count();i++)
                    {
                        newplace.value<<thislinelist[i].toInt();
                    }
                    globals::placeList<<newplace;
                }
                else if(thisLine[0]=='T')
                {
                    struct Transitionplot newtransition;
                    QStringList thislinelist=thisLine.split(" ");
                    //qDebug()<<thislinelist;
                    newtransition.name=thislinelist[0];
                    for(int i=1;i<thislinelist.count();i++)
                    {
                        newtransition.value<<thislinelist[i].toInt();
                    }
                    globals::transitionList<<newtransition;
                }
            }
            ui->textEdit->setText(array);
        }
        file.close();
    }
    float y_axis=YBEGIN;
    for(int i=0;i<globals::transitionList.count();i++)
    {
        globals::transitionList[i].x=XBEGIN;
        globals::transitionList[i].y=y_axis;
        y_axis+=80;
    }
    for(int i=0;i<globals::placeList.count();i++)
    {
        globals::placeList[i].x=XBEGIN;
        globals::placeList[i].y=y_axis;
        y_axis+=80;
    }
    if(ui->textEdit->toPlainText()!=NULL)
    {
        connect(ui->textEdit,SIGNAL(textChanged()),this,SLOT(textChangedFlag()));
    }
}

void MainWindow::on_savefile_clicked()
{
    if(filepath.isEmpty()==false)
    {
         QFile file;
         file.setFileName(filepath);
         bool isOK=file.open(QIODevice::WriteOnly);
         if(isOK==true)
           {
                QString str=ui->textEdit->toPlainText();
                file.write(str.toUtf8());
           }
     file.close();
     ui->savefile->setText("保存文件");
     }
     else
     return;
}

void MainWindow::on_generate_Button_clicked()
{
    subwindow_01.show();
}
