#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QMainWindow>
#include "drawing.h"

namespace Ui {
class subWindow;
}

class subWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit subWindow(QWidget *parent = 0);
    ~subWindow();

private:
    Ui::subWindow *ui;
    drawing drawing_01;
};

#endif // SUBWINDOW_H
