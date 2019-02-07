/********************************************************************************
** Form generated from reading UI file 'moving.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVING_H
#define UI_MOVING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MovingClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MovingClass)
    {
        if (MovingClass->objectName().isEmpty())
            MovingClass->setObjectName(QStringLiteral("MovingClass"));
        MovingClass->resize(600, 400);
        menuBar = new QMenuBar(MovingClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MovingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MovingClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MovingClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MovingClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MovingClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MovingClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MovingClass->setStatusBar(statusBar);

        retranslateUi(MovingClass);

        QMetaObject::connectSlotsByName(MovingClass);
    } // setupUi

    void retranslateUi(QMainWindow *MovingClass)
    {
        MovingClass->setWindowTitle(QApplication::translate("MovingClass", "Moving", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MovingClass: public Ui_MovingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVING_H
