/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QPushButton *pushButton_Num1;
    QPushButton *pushButton_Num2;
    QPushButton *pushButton_Num3;
    QPushButton *pushButton_Num4;
    QPushButton *pushButton_Num5;
    QPushButton *pushButton_Num6;
    QPushButton *pushButton_Num7;
    QPushButton *pushButton_Num8;
    QPushButton *pushButton_Num9;
    QPushButton *pushButton_Num0;
    QPushButton *pushButton_Sum;
    QPushButton *pushButton_Sub;
    QPushButton *pushButton_Mul;
    QPushButton *pushButton_Div;
    QLineEdit *lineEdit;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_Dot;
    QPushButton *pushButton_Eql;
    QLabel *labelFirstNum;
    QPushButton *pushButton_ChangeSig;
    QPushButton *pushButton_LPar;
    QPushButton *pushButton_RPar;
    QMenuBar *menubar;
    QMenu *menuCalculation;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(320, 340);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(320, 340));
        MainWindow->setMaximumSize(QSize(320, 340));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_Num1 = new QPushButton(centralwidget);
        pushButton_Num1->setObjectName("pushButton_Num1");
        pushButton_Num1->setGeometry(QRect(5, 140, 96, 27));
        pushButton_Num2 = new QPushButton(centralwidget);
        pushButton_Num2->setObjectName("pushButton_Num2");
        pushButton_Num2->setGeometry(QRect(105, 140, 96, 27));
        pushButton_Num3 = new QPushButton(centralwidget);
        pushButton_Num3->setObjectName("pushButton_Num3");
        pushButton_Num3->setGeometry(QRect(205, 140, 101, 27));
        pushButton_Num4 = new QPushButton(centralwidget);
        pushButton_Num4->setObjectName("pushButton_Num4");
        pushButton_Num4->setGeometry(QRect(5, 170, 96, 27));
        pushButton_Num5 = new QPushButton(centralwidget);
        pushButton_Num5->setObjectName("pushButton_Num5");
        pushButton_Num5->setGeometry(QRect(105, 170, 96, 27));
        pushButton_Num6 = new QPushButton(centralwidget);
        pushButton_Num6->setObjectName("pushButton_Num6");
        pushButton_Num6->setGeometry(QRect(205, 170, 101, 27));
        pushButton_Num7 = new QPushButton(centralwidget);
        pushButton_Num7->setObjectName("pushButton_Num7");
        pushButton_Num7->setGeometry(QRect(5, 200, 96, 27));
        pushButton_Num8 = new QPushButton(centralwidget);
        pushButton_Num8->setObjectName("pushButton_Num8");
        pushButton_Num8->setGeometry(QRect(105, 200, 96, 27));
        pushButton_Num9 = new QPushButton(centralwidget);
        pushButton_Num9->setObjectName("pushButton_Num9");
        pushButton_Num9->setGeometry(QRect(205, 200, 101, 27));
        pushButton_Num0 = new QPushButton(centralwidget);
        pushButton_Num0->setObjectName("pushButton_Num0");
        pushButton_Num0->setGeometry(QRect(5, 230, 96, 27));
        pushButton_Sum = new QPushButton(centralwidget);
        pushButton_Sum->setObjectName("pushButton_Sum");
        pushButton_Sum->setGeometry(QRect(5, 110, 51, 27));
        pushButton_Sub = new QPushButton(centralwidget);
        pushButton_Sub->setObjectName("pushButton_Sub");
        pushButton_Sub->setGeometry(QRect(65, 110, 51, 27));
        pushButton_Mul = new QPushButton(centralwidget);
        pushButton_Mul->setObjectName("pushButton_Mul");
        pushButton_Mul->setGeometry(QRect(125, 110, 51, 27));
        pushButton_Div = new QPushButton(centralwidget);
        pushButton_Div->setObjectName("pushButton_Div");
        pushButton_Div->setGeometry(QRect(185, 110, 51, 27));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(5, 60, 301, 41));
        pushButton_Clear = new QPushButton(centralwidget);
        pushButton_Clear->setObjectName("pushButton_Clear");
        pushButton_Clear->setGeometry(QRect(245, 110, 61, 27));
        pushButton_Dot = new QPushButton(centralwidget);
        pushButton_Dot->setObjectName("pushButton_Dot");
        pushButton_Dot->setGeometry(QRect(105, 230, 96, 27));
        pushButton_Eql = new QPushButton(centralwidget);
        pushButton_Eql->setObjectName("pushButton_Eql");
        pushButton_Eql->setGeometry(QRect(205, 230, 101, 27));
        labelFirstNum = new QLabel(centralwidget);
        labelFirstNum->setObjectName("labelFirstNum");
        labelFirstNum->setGeometry(QRect(10, 10, 301, 31));
        pushButton_ChangeSig = new QPushButton(centralwidget);
        pushButton_ChangeSig->setObjectName("pushButton_ChangeSig");
        pushButton_ChangeSig->setGeometry(QRect(210, 260, 91, 27));
        pushButton_LPar = new QPushButton(centralwidget);
        pushButton_LPar->setObjectName("pushButton_LPar");
        pushButton_LPar->setGeometry(QRect(10, 260, 81, 27));
        pushButton_RPar = new QPushButton(centralwidget);
        pushButton_RPar->setObjectName("pushButton_RPar");
        pushButton_RPar->setGeometry(QRect(110, 260, 91, 27));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 320, 24));
        menuCalculation = new QMenu(menubar);
        menuCalculation->setObjectName("menuCalculation");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuCalculation->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        pushButton_Num1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_Num2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_Num3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_Num4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_Num5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_Num6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_Num7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_Num8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_Num9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_Num0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_Sum->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_Sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_Mul->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_Div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_Dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_Eql->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        labelFirstNum->setText(QString());
        pushButton_ChangeSig->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_LPar->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_RPar->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        menuCalculation->setTitle(QCoreApplication::translate("MainWindow", "Calculation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
