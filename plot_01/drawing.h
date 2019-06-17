#ifndef DRAWING_H
#define DRAWING_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>
#include "globals.h"

namespace Ui {
class drawing;
}

class drawing : public QWidget
{
    Q_OBJECT

public:
    explicit drawing(QWidget *parent = 0);
    ~drawing();

protected:
    void paintEvent(QPaintEvent *);
    void paintplot(QImage&Plot_image);
    void lineplot(QImage&Line_image);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);

private:
    Ui::drawing *ui;
    QImage Line_image;
    QImage Plot_image;
    QPoint MousePoint;
    bool MouseFlag;
};

#endif // DRAWING_H
