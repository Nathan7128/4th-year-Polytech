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
    QPushButton *bouttonReinit;
    QPushButton *boutton7;
    QPushButton *boutton3;
    QPushButton *boutton6;
    QPushButton *boutton2;
    QPushButton *bouttonAdd;
    QPushButton *boutton9;
    QPushButton *boutton1;
    QPushButton *boutton4;
    QPushButton *bouttonEgal;
    QPushButton *boutton8;
    QLineEdit *resCalcul;
    QPushButton *boutton0;
    QPushButton *boutton5;
    QPushButton *bouttonSoustr;
    QPushButton *bouttonDiv;
    QPushButton *bouttonMult;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        bouttonReinit = new QPushButton(centralwidget);
        bouttonReinit->setObjectName("bouttonReinit");
        bouttonReinit->setGeometry(QRect(460, 320, 31, 31));
        boutton7 = new QPushButton(centralwidget);
        boutton7->setObjectName("boutton7");
        boutton7->setGeometry(QRect(400, 170, 31, 31));
        boutton3 = new QPushButton(centralwidget);
        boutton3->setObjectName("boutton3");
        boutton3->setGeometry(QRect(520, 270, 31, 31));
        boutton6 = new QPushButton(centralwidget);
        boutton6->setObjectName("boutton6");
        boutton6->setGeometry(QRect(520, 220, 31, 31));
        boutton2 = new QPushButton(centralwidget);
        boutton2->setObjectName("boutton2");
        boutton2->setGeometry(QRect(460, 270, 31, 31));
        bouttonAdd = new QPushButton(centralwidget);
        bouttonAdd->setObjectName("bouttonAdd");
        bouttonAdd->setGeometry(QRect(340, 170, 31, 31));
        boutton9 = new QPushButton(centralwidget);
        boutton9->setObjectName("boutton9");
        boutton9->setGeometry(QRect(520, 170, 31, 31));
        boutton1 = new QPushButton(centralwidget);
        boutton1->setObjectName("boutton1");
        boutton1->setGeometry(QRect(400, 270, 31, 31));
        boutton4 = new QPushButton(centralwidget);
        boutton4->setObjectName("boutton4");
        boutton4->setGeometry(QRect(400, 220, 31, 31));
        bouttonEgal = new QPushButton(centralwidget);
        bouttonEgal->setObjectName("bouttonEgal");
        bouttonEgal->setGeometry(QRect(520, 320, 31, 31));
        boutton8 = new QPushButton(centralwidget);
        boutton8->setObjectName("boutton8");
        boutton8->setGeometry(QRect(460, 170, 31, 31));
        resCalcul = new QLineEdit(centralwidget);
        resCalcul->setObjectName("resCalcul");
        resCalcul->setGeometry(QRect(390, 110, 171, 41));
        boutton0 = new QPushButton(centralwidget);
        boutton0->setObjectName("boutton0");
        boutton0->setGeometry(QRect(400, 320, 31, 31));
        boutton5 = new QPushButton(centralwidget);
        boutton5->setObjectName("boutton5");
        boutton5->setGeometry(QRect(460, 220, 31, 31));
        bouttonSoustr = new QPushButton(centralwidget);
        bouttonSoustr->setObjectName("bouttonSoustr");
        bouttonSoustr->setGeometry(QRect(340, 220, 31, 31));
        bouttonDiv = new QPushButton(centralwidget);
        bouttonDiv->setObjectName("bouttonDiv");
        bouttonDiv->setGeometry(QRect(340, 320, 31, 31));
        bouttonMult = new QPushButton(centralwidget);
        bouttonMult->setObjectName("bouttonMult");
        bouttonMult->setGeometry(QRect(340, 270, 31, 31));
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
        bouttonReinit->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        boutton7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        boutton3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        boutton6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        boutton2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        bouttonAdd->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        boutton9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        boutton1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        boutton4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        bouttonEgal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        boutton8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        boutton0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        boutton5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        bouttonSoustr->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        bouttonDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        bouttonMult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
