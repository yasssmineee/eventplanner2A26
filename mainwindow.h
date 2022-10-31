#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <partenaire.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_ajouterpartenaire_clicked();

    void on_aviss_textChanged(const QString &arg1);

    void on_modifierpartenaire_clicked();

    void on_tabpartenaire_clicked();

    void on_afficherhistorique_clicked();
    
    void on_supprimerpartenaire_clicked();

private:
    Ui::MainWindow *ui;
    Partenaire P;
};

#endif // MAINWINDOW_H
