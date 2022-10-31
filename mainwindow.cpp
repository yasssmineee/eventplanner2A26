 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partenaire.h"
#include <QMessageBox>
#include <QIntValidator>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

   ui->le_id->setValidator(new QIntValidator(100, 9999999 , this));
   ui->tabpartenaire->setModel(P.afficher());

}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouterpartenaire_clicked()
{
    int id=ui->le_id->text().toUInt();
    int numero=ui->le_numero->text().toUInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui-> le_prenom->text();
    QString adresse=ui-> l_adresse->text();

    Partenaire p(id,numero,nom,prenom,adresse);
    p.ajouter();

}




void MainWindow::on_aviss_textChanged(const QString &arg1)
{
    //setMaximum(5)
}



void MainWindow::on_modifierpartenaire_clicked()
{

    int id=ui->le_id2->text().toInt();
   // int numero=ui->le_numero2->text().toUInt();
    QString nom=ui->le_nom2->text();
    QString prenom=ui->le_prenom2->text();
    QString adresse=ui->le_adresse2->text();

    Partenaire p(id,5,nom,prenom,adresse);
    p.modifier();
}


void MainWindow::on_supprimerpartenaire_clicked()
{

 QMessageBox msgBox;
 Partenaire P1;

 int id = ui->lineEdit_12->text().toInt();
 bool test=P1.supprimer(id);


if (test)
{

    ui->tabpartenaire->setModel(P.afficher());
     msgBox.setText("supprimer avec succes");
}

else
    msgBox.setText("echec de suppression ");
    msgBox.exec();


}
