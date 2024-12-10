#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void calculerRes();
    void afficher(int nombre);
    void modifierOperande(int nombre);
    void modifierOperateur(char op);

private slots:
    void on_bouttonAdd_clicked();

    void on_bouttonSoustr_clicked();

    void on_bouttonMult_clicked();

    void on_bouttonDiv_clicked();

    void on_boutton0_clicked();

    void on_boutton1_clicked();

    void on_boutton2_clicked();

    void on_boutton3_clicked();

    void on_boutton4_clicked();

    void on_boutton5_clicked();

    void on_boutton6_clicked();

    void on_boutton7_clicked();

    void on_boutton8_clicked();

    void on_boutton9_clicked();

    void on_bouttonEgal_clicked();

    void on_bouttonReinit_clicked();

private:
    Ui::MainWindow *ui;
    QString etat;
    int operande1;
    int operande2;
    char operateur;
};
#endif // MAINWINDOW_H
