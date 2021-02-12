#include "livre.h"

#include <fstream>

#include <string>

// SI ALI LYES

Livre::Livre(int ISBN, string Titre, string Auteur, string Editeur, int Annee, float Prix)
{
     this->ISBN    =ISBN;
     this->Titre   =Titre;
     this->Auteur  =Auteur;
     this->Editeur =Editeur;
     this->Annee   =Annee;
     this->Prix    =Prix;
}
Livre::Livre()
{
     this->ISBN    = 0;
     this->Titre   =" None";
     this->Auteur  =" None";
     this->Editeur =" None";
     this->Annee   =0;
     this->Prix    =0;
}
Livre::~Livre(){
    
}
int Livre::getISBN()
{
    return this->ISBN;
}
void Livre::setISBN(int code)
{
    code = this->ISBN;
}
string Livre::getTitre()
{
    return this->Titre;
}
void Livre::setTitre(string title)
{
    title = this->Titre;
}
string Livre::getAuteur()
{
    return this->Auteur;
}
void Livre::setAuteur(string autor)
{
    autor = this->Auteur;
}
string Livre::getEditeur()
{
    return this->Editeur;
}
void Livre::setEditeur(string Edit)
{
    Edit = this->Editeur;
}
int Livre::getAnnee()
{
    return this->Annee;
}
void Livre::setAnnee(int year)
{
    year = this->Annee;
}
float Livre::getPrix()
{
    return this->Prix;
}
void Livre::setPrix(float price)
{
    price = this->Prix;
}
        
