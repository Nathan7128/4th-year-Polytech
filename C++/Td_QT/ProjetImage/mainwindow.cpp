#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crectangle.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    r = new CRectangle(10,50,70,30);
}
MainWindow::~MainWindow() {
    delete ui;
    delete r ;
}

void MainWindow::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);
    QPainter painter(this);

    painter.setPen( QPen(Qt::red, 1) );
    painter.setFont(QFont("Arial",16));
    painter.drawText(10,30,QString("Exemple de tracés 2D"));
    painter.drawPixmap(10,100,100,100,QPixmap(":/images/image.jpg"));
    r->dessiner(&painter);
}
void MainWindow::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton)
    {
        r->deplacer(e->x(),e->y());
        this->repaint();
    }
}
