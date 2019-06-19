/********************************************************************************
** Form generated from reading UI file 'drawing.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWING_H
#define UI_DRAWING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_drawing
{
public:
    QHBoxLayout *horizontalLayout;
    QCustomPlot *customplot;

    void setupUi(QWidget *drawing)
    {
        if (drawing->objectName().isEmpty())
            drawing->setObjectName(QStringLiteral("drawing"));
        drawing->resize(400, 300);
        horizontalLayout = new QHBoxLayout(drawing);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        customplot = new QCustomPlot(drawing);
        customplot->setObjectName(QStringLiteral("customplot"));

        horizontalLayout->addWidget(customplot);


        retranslateUi(drawing);

        QMetaObject::connectSlotsByName(drawing);
    } // setupUi

    void retranslateUi(QWidget *drawing)
    {
        drawing->setWindowTitle(QApplication::translate("drawing", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class drawing: public Ui_drawing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWING_H
