#ifndef PARTENAIRE_H
#define PARTENAIRE_H

#include <QString>
#include <QSqlQueryModel>


class Partenaire
{
public:
    Partenaire();
    Partenaire(int,int,QString,QString,QString);

     int getid();
     int getnumero();
     QString getnom();
     QString getprenom();
     QString getadresse();


     void setid(int);
     void setnumero(int);
     void setnom(QString);
     void setprenom(QString);
     void setadresse(QString);
     bool ajouter();
     bool modifier();
     QSqlQueryModel* afficher();
     bool supprimer(int);

private:
    int id,numero; QString nom,prenom,adresse;

};

#endif //  PARTENAIRE_H
