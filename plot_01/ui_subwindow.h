/********************************************************************************
** Form generated from reading UI file 'subwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWINDOW_H
#define UI_SUBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "drawing.h"

QT_BEGIN_NAMESPACE

class Ui_subWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    drawing *drawing_01;

    void setupUi(QMainWindow *subWindow)
    {
        if (subWindow->objectName().isEmpty())
            subWindow->setObjectName(QStringLiteral("subWindow"));
        subWindow->resize(430, 347);
        centralwidget = new QWidget(subWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        drawing_01 = new drawing();
        drawing_01->setObjectName(QStringLiteral("drawing_01"));
        drawing_01->setGeometry(QRect(0, 0, 410, 327));
        scrollArea->setWidget(drawing_01);

        verticalLayout->addWidget(scrollArea);

        subWindow->setCentralWidget(centralwidget);

        retranslateUi(subWindow);

        QMetaObject::connectSlotsByName(subWindow);
    } // setupUi

    void retranslateUi(QMainWindow *subWindow)
    {
        subWindow->setWindowTitle(QApplication::translate("subWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class subWindow: public Ui_subWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWINDOW_H
