#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    operande1 = 0;
    operande2 = 0;
    operateur = 'o';
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bouttonAdd_clicked()
{
    if ((this->ui->resCalcul->text()).length() > 0 and this->operateur == 'o'){
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + " + ");
        this->operateur = '+';
    }
}


void MainWindow::on_bouttonSoustr_clicked()
{
    if ((this->ui->resCalcul->text()).length() > 0 and this->operateur == 'o'){
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + " - ");
        this->operateur = '-';
    }
}


void MainWindow::on_bouttonMult_clicked()
{
    if ((this->ui->resCalcul->text()).length() > 0 and this->operateur == 'o'){
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + " * ");
        this->operateur = '*';
    }
}


void MainWindow::on_bouttonDiv_clicked()
{
    if ((this->ui->resCalcul->text()).length() > 0 and this->operateur == 'o'){
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + " / ");
        this->operateur = '/';
    }
}


void MainWindow::on_boutton0_clicked()
{
    if (this->operande1 == 0 and this->operateur == 'o') {
        this->ui->resCalcul->setText("0");
    }
    else {
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + "0");
    }
    if (this->operateur == 'o') {
        this->operande1 = this->operande1*10 + 0;
    }
    else {
        this->operande2 = this->operande2*10 + 0;
    }
}


void MainWindow::on_boutton1_clicked()
{
    if (this->operande1 == 0 and this->operateur == 'o') {
        this->ui->resCalcul->setText("1");
    }
    else {
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + "1");
    }
    if (this->operateur == 'o') {
        this->operande1 = this->operande1*10 + 1;
    }
    else {
        this->operande2 = this->operande2*10 + 1;
    }
}


void MainWindow::on_boutton2_clicked()
{
    if (this->operande1 == 0 and this->operateur == 'o') {
        this->ui->resCalcul->setText("2");
    }
    else {
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + "2");
    }
    if (this->operateur == 'o') {
        this->operande1 = this->operande1*10 + 2;
    }
    else {
        this->operande2 = this->operande2*10 + 2;
    }
}


void MainWindow::on_boutton3_clicked()
{
    if (this->operande1 == 0 and this->operateur == 'o') {
        this->ui->resCalcul->setText("3");
    }
    else {
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + "3");
    }
    if (this->operateur == 'o') {
        this->operande1 = this->operande1*10 + 3;
    }
    else {
        this->operande2 = this->operande2*10 + 3;
    }
}


void MainWindow::on_boutton4_clicked()
{
    if (this->operande1 == 0 and this->operateur == 'o') {
        this->ui->resCalcul->setText("4");
    }
    else {
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + "4");
    }
    if (this->operateur == 'o') {
        this->operande1 = this->operande1*10 + 4;
    }
    else {
        this->operande2 = this->operande2*10 + 4;
    }
}


void MainWindow::on_boutton5_clicked()
{
    if (this->operande1 == 0 and this->operateur == 'o') {
        this->ui->resCalcul->setText("5");
    }
    else {
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + "5");
    }
    if (this->operateur == 'o') {
        this->operande1 = this->operande1*10 + 5;
    }
    else {
        this->operande2 = this->operande2*10 + 5;
    }
}


void MainWindow::on_boutton6_clicked()
{
    if (this->operande1 == 0 and this->operateur == 'o') {
        this->ui->resCalcul->setText("6");
    }
    else {
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + "6");
    }
    if (this->operateur == 'o') {
        this->operande1 = this->operande1*10 + 6;
    }
    else {
        this->operande2 = this->operande2*10 + 6;
    }
}


void MainWindow::on_boutton7_clicked()
{
    if (this->operande1 == 0 and this->operateur == 'o') {
        this->ui->resCalcul->setText("7");
    }
    else {
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + "7");
    }
    if (this->operateur == 'o') {
        this->operande1 = this->operande1*10 + 7;
    }
    else {
        this->operande2 = this->operande2*10 + 7;
    }
}


void MainWindow::on_boutton8_clicked()
{
    if (this->operande1 == 0 and this->operateur == 'o') {
        this->ui->resCalcul->setText("8");
    }
    else {
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + "8");
    }
    if (this->operateur == 'o') {
        this->operande1 = this->operande1*10 + 8;
    }
    else {
        this->operande2 = this->operande2*10 + 8;
    }
}


void MainWindow::on_boutton9_clicked()
{
    if (this->operande1 == 0 and this->operateur != 'o') {
        this->ui->resCalcul->setText("9");
    }
    else {
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + "");
    }
    if (this->operateur == 'o') {
        this->operande1 = this->operande1*10 + 9;
    }
    else {
        this->operande2 = this->operande2*10 + 9;
    }
}


void MainWindow::on_bouttonEgal_clicked()
{
    QString s;
    int res = 0;
    switch (this->operateur) {
    case '+':
        res = this->operande1 + this->operande2;
        break;
    case '-':
        res = this->operande1 - this->operande2;
        break;
    case '*':
        res = this->operande1 * this->operande2;
        break;
    case '/':
        res = this->operande1 / this->operande2;
        break;
    }
    s = QString::number(res);
    this->ui->resCalcul->setText(QString(s));
    this->operande1 = 0;
    this->operande2 = 0;
    this->operateur = 'o';
}

void MainWindow::on_bouttonReinit_clicked()
{
    this->operande1 = 0;
    this->operande2 = 0;
    this->operateur = 'o';
    this->ui->resCalcul->setText("");
}

