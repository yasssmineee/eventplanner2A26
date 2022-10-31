#include "partenaire.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QObject>

Partenaire::Partenaire()
{
id=0;numero=0; nom=" "; prenom=" "; adresse=" ";
}


Partenaire::Partenaire(int id ,int numero ,QString nom ,QString prenom,QString adresse)

{this->id=id; this->nom=nom; this->prenom=prenom; this->numero=numero; this->adresse=adresse; }

int Partenaire::getid(){return id;}
int Partenaire::getnumero(){return numero;}
QString Partenaire::getnom(){return nom;}
QString Partenaire::getprenom(){ return prenom;}
QString Partenaire::getadresse() {return adresse;}

void Partenaire::setid(int id){this ->id=id;}
void Partenaire::setnumero(int numero){this->numero=numero;}
void Partenaire::setnom(QString nom){this->nom=nom;}
void Partenaire::setprenom(QString prenom){this->prenom=prenom;}
void Partenaire::setadresse(QString adresse){this->adresse=adresse;}

bool Partenaire::ajouter()
{
    bool test=false;


    QSqlQuery query;
    query.prepare("INSERT INTO partenaire (id, nom,prenom,numero,adresse) "
                  "VALUES (:id, :forename, :surname, :number, :adress)");
    query.bindValue(":id",id);
    query.bindValue(":forename",nom);
    query.bindValue(":surname",prenom);
    query.bindValue(":number",numero);
    query.bindValue(":adress",adresse);

    query.exec();

    return test;

}

bool Partenaire::modifier()
{
    bool test=false;


    QSqlQuery query;
    query.prepare(" update PARTENAIRE set NUMERO=:NUMERO, NOM=:NOM, PRENOM=:PRENOM, ADRESSE=:ADRESSE where ID=:ID  ; ");
    query.bindValue(":ID",id);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":NUMERO",numero);
    query.bindValue(":ADRESSE",adresse);

    query.exec();

    return test;

}

bool Partenaire::supprimer(int id)
{
    QSqlQuery query;
          query.prepare(" delete from PARTENAIRE where ID=:ID ");
          query.bindValue(":ID", id );
          return query.exec();
}

QSqlQueryModel* Partenaire::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


      model->setQuery("SELECT*  FROM PARTENAIRE");
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    return model;

}




