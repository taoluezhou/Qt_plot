#include "drawing.h"
#include "ui_drawing.h"

drawing::drawing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drawing)
{
    ui->setupUi(this);
    QColor backcolor(255,255,255);
    Line_image = QImage(4000,2000,QImage::Format_ARGB32);//QImage::Format_ARGB32支持透明
    Line_image.fill(QColor(254,254,254,0));
    Button_widget.setParent(this);
    Button_widget.resize(4000,2000);
    Button_widget.setAutoFillBackground(true);
    //Button_widget->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(0,0,0,0));
    Button_widget.setPalette(palette);
    Plot_image = QImage(4000,2000,QImage::Format_RGB32);
    Plot_image.fill(backcolor);
    MouseFlag=false;

}

drawing::~drawing()
{
    delete ui;
}

void drawing::paintplot(QImage&Plot_image)
{

    QPainter p(&Plot_image);
    //设定画笔
    QPen pen;
    pen.setWidth(2);//设置线宽
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    //设定画刷
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    //将画笔交给“画家”
    p.setPen(pen);
    //将画刷交给“画家”
    p.setBrush(brush);
    //设置字体
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setLetterSpacing(QFont::AbsoluteSpacing,0);
    font.setPointSize(20);
    //将字体交给“画家”
    p.setFont(font);

    int x_head_begin=190;
    for(int i=0;i<globals::transitionList[0].value.count();i++)
    {
        p.drawText(x_head_begin, 30,QString::number(i, 10));
        x_head_begin+=100;
    }
    for(int tran_num=0;tran_num<globals::transitionList.count();tran_num++)
    {
        float x_axis=globals::transitionList[tran_num].x;
        float y_axis=globals::transitionList[tran_num].y;
        p.drawText(15, y_axis,globals::transitionList[tran_num].name);
        if(globals::transitionList[tran_num].value[0]==0)
        {
            p.drawLine(x_axis, y_axis + 20,x_axis + 100, y_axis + 20);
        }
        else if(globals::transitionList[tran_num].value[0]==1)
        {
            p.drawLine(x_axis, y_axis - 20,x_axis + 100, y_axis - 20);
        }
        x_axis+=100;
        for(int i=1;i<globals::transitionList[tran_num].value.count();i++)
        {
            if(globals::transitionList[tran_num].value[i]!=globals::transitionList[tran_num].value[i-1])
            {
                p.drawLine(x_axis, y_axis + 20,x_axis, y_axis - 20);
            }
            if(globals::transitionList[tran_num].value[i]==0)
            {
                p.drawLine(x_axis, y_axis + 20,x_axis + 100, y_axis + 20);
                x_axis+=100;
            }
            else if(globals::transitionList[tran_num].value[i]==1)
            {
                p.drawLine(x_axis, y_axis - 20,x_axis + 100, y_axis - 20);
                x_axis+=100;
            }
        }
    }
    for(int pla_num=0;pla_num<globals::placeList.count();pla_num++)
    {
        float x_axis=globals::placeList[pla_num].x;
        float y_axis=globals::placeList[pla_num].y;
        p.drawText(15, y_axis,globals::placeList[pla_num].name);
        p.drawLine(x_axis, y_axis + 25,x_axis + 100, y_axis + 25);
        p.drawLine(x_axis, y_axis - 25,x_axis + 100, y_axis - 25);
        x_axis+=100;
        font.setPointSize(10);
        p.setFont(font);
        pen.setColor(Qt::red);
        p.setPen(pen);
        p.drawText(x_axis + 35, y_axis-14,QString("0x"+QString::number(globals::placeList[pla_num].value[0], 10)));
        pen.setColor(Qt::black);
        p.setPen(pen);
        for(int i=1;i<globals::placeList[pla_num].value.count();i++)
        {
            if(globals::placeList[pla_num].value[i]==globals::placeList[pla_num].value[i-1])
            {
                p.drawLine(x_axis, y_axis + 25,x_axis + 100, y_axis + 25);
                p.drawLine(x_axis, y_axis - 25,x_axis + 100, y_axis - 25);
                x_axis+=100;
            }
            else if(globals::placeList[pla_num].value[i]!=globals::placeList[pla_num].value[i-1])
            {
                p.drawLine(x_axis, y_axis + 25,x_axis + 20, y_axis + 25);
                p.drawLine(x_axis, y_axis - 25,x_axis + 20, y_axis - 25);
                p.drawLine(x_axis + 20, y_axis - 25,x_axis + 80, y_axis + 25);
                p.drawLine(x_axis + 20, y_axis + 25,x_axis + 80, y_axis - 25);
                p.drawLine(x_axis + 80, y_axis + 25,x_axis + 100, y_axis + 25);
                p.drawLine(x_axis + 80, y_axis - 25,x_axis + 100, y_axis - 25);
                pen.setColor(Qt::red);
                p.setPen(pen);
                p.drawText(x_axis + 35, y_axis-14,QString("0x"+QString::number(globals::placeList[pla_num].value[i], 10)));
                pen.setColor(Qt::black);
                p.setPen(pen);
                x_axis+=100;
            }           
        }
        pen.setColor(Qt::black);
        p.setPen(pen);
        font.setPointSize(20);
        p.setFont(font);
    }
    //Buttonplot(Button_widget);
    update();
    //delete newButton;
}

void drawing::lineplot(QImage&Line_image)
{
    QPainter p(&Line_image);
    //设定画笔
    QPen pen;
    pen.setWidth(3);//设置线宽
    pen.setColor(Qt::green);
    pen.setStyle(Qt::SolidLine);
    //设定画刷
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    //将画笔交给“画家”
    p.setPen(pen);
    //将画刷交给“画家”
    p.setBrush(brush);
    //设置字体
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setLetterSpacing(QFont::AbsoluteSpacing,0);
    font.setPointSize(10);
    //将字体交给“画家”
    p.setFont(font);
    p.drawLine(MousePoint.rx(), 10,MousePoint.rx(), 125+80*(globals::placeList.count()+globals::transitionList.count()-1));
    pen.setColor(Qt::blue);
    p.setPen(pen);
    int time;
    time=(MousePoint.rx()-150)/100;
    //qDebug()<<time;
    for(int i=0;i<globals::transitionList.count();i++)
    {
        p.drawText(80, globals::transitionList[i].y,QString("0x"+QString::number(globals::transitionList[i].value[time], 10)));

    }
    for(int i=0;i<globals::placeList.count();i++)
    {
        p.drawText(80, globals::placeList[i].y,QString("0x"+QString::number(globals::placeList[i].value[time], 10)));
    }
    for(int i=0;i<globals::transitionList.count();i++)
    {
        p.drawText(MousePoint.rx(), globals::transitionList[i].y,QString("0x"+QString::number(globals::transitionList[i].value[time], 10)));

    }
    for(int i=0;i<globals::placeList.count();i++)
    {
        p.drawText(MousePoint.rx(), globals::placeList[i].y,QString("0x"+QString::number(globals::placeList[i].value[time], 10)));
    }
    //Buttonplot(Button_widget);
}

void drawing::Buttonplot(QWidget&Button_widget)
{
   for(int i=0;i<globals::placeList.count();i++)
    {
        globals::placeList[i].ExpandButton = new QPushButton("+",&Button_widget);
        globals::placeList[i].ExpandButton->setGeometry(50,globals::placeList[i].y-20,20,20);
        globals::placeList[i].ExpandButton->setFont(QFont("Time",10,QFont::Black));
        globals::placeList[i].ExpandButton->show();
        connect(globals::placeList[i].ExpandButton,SIGNAL(clicked(globals::placeList[i])),this,SLOT(Expand(globals::placeList[i])));
    }
}

void drawing::mousePressEvent(QMouseEvent*)
{
    MouseFlag=true;
    Buttonplot(Button_widget);// 放在这里比较流畅（？）

}

void drawing::Expand(struct Placeplot place)
{
    qDebug()<<place.name;
    qDebug()<<"111";
}


void drawing::mouseMoveEvent(QMouseEvent*event)
{
    if(MouseFlag==false)
    {
       return;
    }
    if(event->pos().rx()<150||event->pos().rx()>(150+100*(globals::transitionList[0].value.count())))
    {
       return;
    }
    MousePoint=event->pos();
    Line_image.fill(QColor(254,254,254,0));
    lineplot(Line_image);
    //Buttonplot(Button_widget);
}

void drawing::mouseReleaseEvent(QMouseEvent*)
{
    MouseFlag=false;
    //Buttonplot(Button_widget);
}

void drawing::paintEvent(QPaintEvent *)
{

    QPainter pai(this);
    //Buttonplot(Button_widget);
    pai.drawImage(0,0,Plot_image);
    pai.drawImage(0,0,Line_image);    
    paintplot(Plot_image);

    //qDebug()<<globals::placeList[0].name;

}
