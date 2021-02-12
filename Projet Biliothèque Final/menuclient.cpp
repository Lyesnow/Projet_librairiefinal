#include "menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include "client.h"
using namespace std;

// SI ALI LYES

  void afficherlalistedesclients()try {
// Les variables pour la BDD

  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res ;
//  connexion à la BDD
driver = get_driver_instance();

string ntt = "select * from client ";

con = driver->connect("tcp://localhost", "lyes", "lyes");
con->setSchema("bibliotheque");
stmt = con->createStatement();

if (res = stmt->executeQuery(ntt)){
sql::ResultSetMetaData *res_meta = res -> getMetaData();

  int columns = res_meta -> getColumnCount();
  while (res->next()) {
    
     for (int i = 1; i <= columns; i++) {
      cout << res_meta->getColumnLabel(i) << " = " << res->getString(i) << " | " ;
    } 
    cout << endl;
  }
 

}


delete res;
delete stmt;
delete con;
} 
catch (sql::SQLException &e) {
// verification en cas de problème
cout << "# ERR: " << e.what();
cout << " (code erreur MySQL: " << e.getErrorCode();
cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
cout << endl;

 
}
    
 void ajouterunnouveauclient(){
       string nom , addresse ;
    float tel , anci;
    cout << "Entrez un Nom du client" << endl;
    while (getline(cin, nom))
    if (nom != "")
    break;
    cout << "Entrez l'addresse du client" << endl;
    while (getline(cin, addresse))
    if (addresse != "")
    break;
    cout << "Entrez le tel" << endl;
    cin >> tel;
    cout << "Entrez l'anciennete" << endl;
    cin >> anci;
    Client x("" ,nom , addresse , tel , anc);

    try {
// 

  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  
//  une connexion à la BDD
driver = get_driver_instance();


// cree la table
string newTable = " create table if not exists client(idc int not null primary key auto_increment , nom char(30) , addresse char(40), tel int(11) ,anciennete int(10) )";
// remplir les informations
string ntt = "insert into client (idc , nom , addresse , tel , anciennete) values(idc ,'" + this->Nom + "','" + this->Adresse + "','" + to_string(this->Tel) +"','" + to_string(this->Anciennete)  +"')" ;
con = driver->connect("tcp://localhost", "lyes", "lyes");
con->setSchema("bibliotheque");
stmt = con->createStatement();
stmt->execute(newTable);
stmt->execute(ntt);

delete stmt;
delete con;
} catch (sql::SQLException &e) {
// vérification en cas de problème
cout << "# ERR: " << e.what();
cout << " (code erreur MySQL: " << e.getErrorCode();
cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
cout << endl;



}
void Rechercherunclientetaffichersesinformations()
{
int choix;
string mtf;
cout << "Entrez le choix de recherche : " << endl ;
cout << "Nom 1 Addresse 2 Tel 3  Anciennete 4" << endl ;
cin >> choix;
cout << "Entrez maintenant la recherche"  << endl;
while (getline(cin, mtf))
    if (mtf != "")
    break;
try {
// variables pour la bdd

  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res ;
// créer une connexion à la BDD
driver = get_driver_instance();

string ntt;
switch (choix)
{
case 1:
    ntt = "select * from client where locate('" + mtf + "',nom )  " ;
    break;
case 2 : 
   ntt = "select * from client where locate('" + mtf + "',addresse )  " ;
    break;
case 3 : 
    ntt = "select * from client where locate('" + mtf + "',tel )  " ;
    break;
case 4 : 
    ntt = "select * from client where locate('" + mtf + "',anciennete )  " ;
    break;

default:
    break;
} 
con = driver->connect("tcp://localhost", "lyes", "lyess"); // on va se connecter sur l utilasteur lyes avec comme mot de passe lyes
con->setSchema("bibliotheque"); // on selectionne notre bdd
stmt = con->createStatement();

if (res = stmt->executeQuery(ntt)){

 while (res->next()) {
   
    cout <<  "Titre = "<< res->getString("nom") << endl;
    cout <<  "Auteur = "<< res->getString("addresse") << endl; 
    cout <<  "Editeur = "<< res->getString("tel") << endl; 
    cout <<  "Date = "<< res->getString("anciennete") << endl; 
    
   
   
  }
 

}


delete res;
delete stmt;
delete con;
} 
catch (sql::SQLException &e) {
// verification en cas de problème
cout << "# ERR: " << e.what();
cout << " (code erreur MySQL: " << e.getErrorCode();
cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
cout << endl;
}

void modifierlesinformationsconcernantunclient() 
{
string nMtt;
int choix,choix2;
cout << "Vous voulez modifier le nom 1  adresse 2 telephone 3" << endl;
cin >> choix;
cout<< "Entrez l'id du client que vous voulez modifer"<<endl;
cin>>choix2;
cout << "Entrez l'information" << endl;
cin >> nMtt;
try {
// les variables pour la bddd
sql::Driver *driver;
sql::Connection *con;
sql::Statement *stmt;
sql::ResultSet *res ;
//  connexion à la bdd
driver = get_driver_instance();
string ntt , slt;

switch (choix)
{
case 1:
ntt = "UPDATE client SET nom = '" + nMtt + "' WHERE idccm = '"+ to_string(choix2) +"'  " ;
slt = "SELECT * FROM  client WHERE LOCATE('" + nMtt + "',nom )  " ;
break;



case 2 : 
ntt = "UPDATE client SET adresse = '" + nMtt + "' WHERE idccm='" + to_string(choix2)  + "' " ;
slt = "SELECT * FROM  client WHERE LOCATE('" + nMtt + "',adresse )  " ;
break;

case 3 : 
ntt = "UPDATE client SET telephone = '" + nMtt + "' WHERE idccm='" + to_string(choix2)  + "'  " ;
slt = "SELECT * FROM  client WHERE LOCATE('" + nMtt + "',telephone )  " ;
break;

default:
break;
} 


con = driver->connect("tcp://localhost", "lyes", "lyes");
con->setSchema("bibliotheque");
stmt = con->createStatement();
stmt->execute(ntt);
if (res = stmt->executeQuery(slt)){
while (res->next()) {
cout << "Apres Modification" << endl ;
cout <<  "nom = "<< res->getString("nom") << endl; 
cout <<  "adresse = "<< res->getString("adresse") << endl; 
cout <<  "telephone = "<< res->getString("telephone") << endl; 
}
}
delete res;
delete stmt;
delete con;
} 
catch (sql::SQLException &e) {
// verification en cas de probleme
cout << "# ERR: " << e.what();
cout << " (code erreur MySQL: " << e.getErrorCode();
cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
cout <<  endl;
}
 void supprimerunclientdelaliste() 
 {
  int choix;
string mtf;
cout << "Entrez ce que vous voulez supprimé  : " << endl ;
cout << "Nom 1 Auteur 2 Editeur 3 Annee 4 Prix 5" << endl ;
cin >> choix;
cout << "Entrez maintenant la suppression "  << endl;
while (getline(cin, mtf))
    if (mtf != "")
    break;
try {
//variables pour la bddd

  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res ;
// connexion à la BDD
driver = get_driver_instance();

string ntt;
switch (choix)
{
case 1:
    ntt = "delete from client where locate('" + mtf + "',nom )  " ;
    break;
case 2 : 
    ntt = "delete from client where locate('" + mtf + "',adrresse)  " ;
    break;
case 3 : 
    ntt = "delete from client where locate('" + mtf + "',tel)  " ;
    break;
case 4 : 
    attribution = "delete from client where locate('" + mtf + "',anciennete )  " ;
    break;

default:
    break;
} 
con = driver->connect("tcp://localhost", "lyes", "lyes");
con->setSchema("bibliotheque");
stmt = con->createStatement();

stmt->execute(ntt);
cout << "c'est supprimé"<< endl;
delete stmt;
delete con;
} 
catch (sql::SQLException &e) {
// verification en cas de probleme
cout << "# ERR: " << e.what();
cout << " (code erreur MySQL: " << e.getErrorCode();
cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
cout << endl;
  
 }


void  Gestiondelalistedesclients() { // Différent choix pour le clients dans le menu
      int choix3;
      cout <<  "********** Gestion de la liste des clients **********"<< endl;
      cout <<    "1. Afficher la liste des clients." << endl;
      cout <<    "2. Ajouter un nouveau client." << endl;
      cout <<    "3. Rechercher un client et afficher ses informations." << endl;
      cout <<    "4. Mettre à jour (modifier) les informations concernant un client." << endl;
      cout <<    "5. Supprimer un client de la liste." << endl;
      cout <<    "6. Retourner au menu précédent." << endl;
      cin >> choix3;

 switch (choix3) // Il selectionne sinon il retourne sur le menu
      {
             case 1:
                   afficherlalistedesclients();
                  break;
            case 2:
                   ajouterunnouveauclient();
                  break;
            case 3:
            void Rechercherunclientetaffichersesinformations();
            break;
            case 4:    
             void modifierlesinformationsconcernantunclient();
             break;
            case 5:
             void supprimerunclientdelaliste();
             break;    
            case 6:
             GestiondelaBibliotheque();
             break;
      }
}
