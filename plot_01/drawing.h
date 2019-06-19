#ifndef DRAWING_H
#define DRAWING_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>
#include <QPushButton>

#include "globals.h"
#include "qcustomplot.h"

namespace Ui {
class drawing;
}

class drawing : public QWidget
{
    Q_OBJECT

public:
    explicit drawing(QWidget *parent = 0);
    ~drawing();


//protected:


private slots:
    void Expand(struct Placeplot);

private:
    Ui::drawing *ui;

};

#endif // DRAWING_H
