#include "client.h"

// SI ALI LYES
client::client(string IDC, string Nom, string  Adresse, int Tel,  int Anciennete)
{
    this->IDC =IDC;
    this->Nom =Nom;
    this->Adresse =Adresse;
    this->Tel =Tel;
    this->Anciennete =Anciennete;
}
client::client()
{
    this->IDC ="None";
    this->Nom ="None";
    this->Adresse ="None";
    this->Tel =0;
    this->Anciennete =0;
}

client::~client(){
    
}
string client::getIDC()
{
    return this->IDC;
}
void client::setIDC(string ident)
{
    ident= this->IDC;
}
string client::getNom()
{
    return this->Nom;
}
void client::setNom(string name)
{
  name= this->Nom;
}
string client::getAdresse()
{
    return this->Adresse;
}
void client::setAdresse(string Adr)
{
    Adr= this->Adresse;
}
int client::getTel()
{
    return this->Tel;
}
void client::setTel(int number)
{
    number= this->Tel;
}
int client::getAnciennete()
{
    return this->Anciennete;
}
void client::setAnciennete(int ancien)
{
    ancien= this->Anciennete;
}