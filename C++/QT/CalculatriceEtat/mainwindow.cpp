#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->etat = "operande1";
    this->operande1 = 0;
    this->operande2 = 0;
    this->ui->resCalcul->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficher(int nombre) {
    QString s = QString::number(nombre);
    if (this->etat == "operande1") {
        this->ui->resCalcul->setText(s);
    }
    else {
        this->ui->resCalcul->setText(this->ui->resCalcul->text() + s);
    }
}

void MainWindow::calculerRes()
{
    switch (this->operateur) {
    case '+':
        this->operande1 += this->operande2;
        break;
    case '-':
        this->operande1 -= this->operande2;
        break;
    case '*':
        this->operande1 *= this->operande2;
        break;
    case '/':
        this->operande1 /= this->operande2;
        break;
    }
    this->ui->resCalcul->setText("");
    this->afficher(this->operande1);
    this->operande2 = 0;
}

void MainWindow::modifierOperande(int nombre) {
    if (this->etat == "operande1") {
        this->operande1 = this->operande1*10 + nombre;
        this->afficher(this->operande1);
    }
    else {
        if (this->etat == "operateur") {
            this->etat = "operande2";
        }
        this->operande2 = this->operande2*10 + nombre;
        this->afficher(this->operande2);
    }
}

void MainWindow::modifierOperateur(char op) {
    if (this->etat == "operande2") {
        this->calculerRes();
    }
    this->etat = "operateur";
    this->operateur = op;
    this->ui->resCalcul->setText(this->ui->resCalcul->text() + " " + op + " ");
}

void MainWindow::on_bouttonAdd_clicked()
{
    this->modifierOperateur('+');
}


void MainWindow::on_bouttonSoustr_clicked()
{
    this->modifierOperateur('-');
}


void MainWindow::on_bouttonMult_clicked()
{
    this->modifierOperateur('*');
}


void MainWindow::on_bouttonDiv_clicked()
{
    this->modifierOperateur('/');
}


void MainWindow::on_boutton0_clicked()
{
    this->modifierOperande(0);
}


void MainWindow::on_boutton1_clicked()
{
    this->modifierOperande(1);
}


void MainWindow::on_boutton2_clicked()
{
    this->modifierOperande(2);
}


void MainWindow::on_boutton3_clicked()
{
    this->modifierOperande(3);
}


void MainWindow::on_boutton4_clicked()
{
    this->modifierOperande(4);
}


void MainWindow::on_boutton5_clicked()
{
    this->modifierOperande(5);
}


void MainWindow::on_boutton6_clicked()
{
    this->modifierOperande(6);
}


void MainWindow::on_boutton7_clicked()
{
    this->modifierOperande(7);
}


void MainWindow::on_boutton8_clicked()
{
    this->modifierOperande(8);
}


void MainWindow::on_boutton9_clicked()
{
    this->modifierOperande(9);
}


void MainWindow::on_bouttonEgal_clicked()
{
    if (this->etat != "operateur") {
        this->calculerRes();
    }
}

void MainWindow::on_bouttonReinit_clicked()
{
    this->operande1 = 0;
    this->operande2 = 0;
    this->etat = "operande1";
    this->ui->resCalcul->setText("0");
}
