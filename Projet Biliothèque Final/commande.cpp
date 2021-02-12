#include "commande.h"

// SI ALI LYES
commande::commande(int IDCM, string IDCGM, int DATE, float Total)
{
    this->IDCM =IDCM;
    this->IDCGM =IDCGM;
    this->DATE =DATE;
    this->Total =Total;
}
int commande::getIDCM()
{
    return this->IDCM;
}
void commande::setIDCM(int ident)
{
    ident = this->IDCM;
}
string commande::getIDCGM()
{
    return this->IDCGM;
}
void commande::setIDCGM(string identcli)
{
    identcli = this->IDCGM;
}
int commande::getDATE()
{
    return this->DATE;
}
void commande::setDATE(int jour)
{
    jour = this->DATE;
}
float commande::getTotal()
{
    return this->Total;
}
void commande::setTotal(float totale)
{
    totale = this->Total;
}