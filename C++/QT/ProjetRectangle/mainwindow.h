#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMouseEvent>
#include "crectangle.h"
namespace Ui { class MainWindow; }
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    CRectangle *r;
    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent *e);
};
#endif // MAINWINDOW_H
