/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *boutton8;
    QPushButton *boutton9;
    QPushButton *boutton5;
    QPushButton *boutton4;
    QPushButton *boutton1;
    QPushButton *boutton2;
    QPushButton *boutton3;
    QPushButton *boutton6;
    QPushButton *boutton7;
    QPushButton *bouttonMult;
    QPushButton *bouttonSoustr;
    QPushButton *bouttonAdd;
    QPushButton *boutton0;
    QPushButton *bouttonEgal;
    QPushButton *bouttonDiv;
    QLineEdit *resCalcul;
    QPushButton *bouttonReinit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        boutton8 = new QPushButton(centralwidget);
        boutton8->setObjectName("boutton8");
        boutton8->setGeometry(QRect(490, 180, 31, 31));
        boutton9 = new QPushButton(centralwidget);
        boutton9->setObjectName("boutton9");
        boutton9->setGeometry(QRect(550, 180, 31, 31));
        boutton5 = new QPushButton(centralwidget);
        boutton5->setObjectName("boutton5");
        boutton5->setGeometry(QRect(490, 230, 31, 31));
        boutton4 = new QPushButton(centralwidget);
        boutton4->setObjectName("boutton4");
        boutton4->setGeometry(QRect(430, 230, 31, 31));
        boutton1 = new QPushButton(centralwidget);
        boutton1->setObjectName("boutton1");
        boutton1->setGeometry(QRect(430, 280, 31, 31));
        boutton2 = new QPushButton(centralwidget);
        boutton2->setObjectName("boutton2");
        boutton2->setGeometry(QRect(490, 280, 31, 31));
        boutton3 = new QPushButton(centralwidget);
        boutton3->setObjectName("boutton3");
        boutton3->setGeometry(QRect(550, 280, 31, 31));
        boutton6 = new QPushButton(centralwidget);
        boutton6->setObjectName("boutton6");
        boutton6->setGeometry(QRect(550, 230, 31, 31));
        boutton7 = new QPushButton(centralwidget);
        boutton7->setObjectName("boutton7");
        boutton7->setGeometry(QRect(430, 180, 31, 31));
        bouttonMult = new QPushButton(centralwidget);
        bouttonMult->setObjectName("bouttonMult");
        bouttonMult->setGeometry(QRect(370, 280, 31, 31));
        bouttonSoustr = new QPushButton(centralwidget);
        bouttonSoustr->setObjectName("bouttonSoustr");
        bouttonSoustr->setGeometry(QRect(370, 230, 31, 31));
        bouttonAdd = new QPushButton(centralwidget);
        bouttonAdd->setObjectName("bouttonAdd");
        bouttonAdd->setGeometry(QRect(370, 180, 31, 31));
        boutton0 = new QPushButton(centralwidget);
        boutton0->setObjectName("boutton0");
        boutton0->setGeometry(QRect(430, 330, 31, 31));
        bouttonEgal = new QPushButton(centralwidget);
        bouttonEgal->setObjectName("bouttonEgal");
        bouttonEgal->setGeometry(QRect(550, 330, 31, 31));
        bouttonDiv = new QPushButton(centralwidget);
        bouttonDiv->setObjectName("bouttonDiv");
        bouttonDiv->setGeometry(QRect(370, 330, 31, 31));
        resCalcul = new QLineEdit(centralwidget);
        resCalcul->setObjectName("resCalcul");
        resCalcul->setGeometry(QRect(420, 120, 171, 41));
        bouttonReinit = new QPushButton(centralwidget);
        bouttonReinit->setObjectName("bouttonReinit");
        bouttonReinit->setGeometry(QRect(490, 330, 31, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        boutton8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        boutton9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        boutton5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        boutton4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        boutton1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        boutton2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        boutton3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        boutton6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        boutton7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        bouttonMult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        bouttonSoustr->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        bouttonAdd->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        boutton0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        bouttonEgal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        bouttonDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        bouttonReinit->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
