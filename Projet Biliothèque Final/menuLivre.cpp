#include "menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include "livre.h"
using namespace std;

// SI ALI LYES

 void modifierlesinformationsconcernantunlivre(){
       int choix;
string mtf;
int nPrix;
cout << "Entrez les modifications " << endl ;
cout << "Nom 1 Auteur 2 Editeur 3 Annee 4 Prix 5" << endl ;
cin >> choix;
cout << "Entrez maintenant ce que vous voulez modifier"  << endl;
while (getline(cin, mtf))      //Pour avoir la ligne
    if (mtf != "")
    break;
cout << "Entrez le prix" << endl;
cin >> nPrix;
try {

// Les variables nécessaires pour la BDD

  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res ;

driver = get_driver_instance();

string ntt , slt;
switch (choix)
{
case 1:
    ntt = "update livre set  prix = '" + to_string(nPrix) + "' where locate('" + mtf + "',titre )  " ;
    slt = "select * from  livre where locate('" + mtf + "',titre )  " ;
    break;
case 2 : 
    ntt = "update livre set  prix = '" + to_string(nPrix) + "' where locate('" + mtf + "',auteur )  " ;
    slt = "select * from  livre where locate('" + mtf + "',auteur )  " ;
    break;
case 3 : 
    ntt = "update livre set  prix = '" + to_string(nPrix) + "' where locate('" + mtf + "',editeur )  " ;
    slt = "select * from  livre where locate('" + mtf + "',editeur )  " ;
    break;
case 4 : 
    ntt = "update livre set  prix = '" + to_string(nPrix) + "' where locate('" + mtf + "',annee )  " ;
    slt = "select * from  livre where locate('" + mtf + "',annee )  " ;
    break;
case 5 : 
    ntt = "update livre set prix = '" + to_string(nPrix) + "'  where locate('" + mtf + "',prix )  " ;
    slt = "select * from  livre where locate('" + mtf + "',prix )  " ;
    break;
default:
    break;
} 
con = driver->connect("tcp://localhost", "lyes", "lyes"); // on va se connecter sur l utilasteur lyes avec comme mot de passe lyes
con->setSchema("bibliotheque"); // on sélectionne notre bdd 
stmt = con->createStatement();
res = stmt->executeQuery(slt);
stmt->execute(ntt);
if (res = stmt->executeQuery(ntt)){

 while (res->next()) {
    cout << "Apres Modification" << endl ;
    cout <<  "Titre = "<< res->getString("titre") << endl;
    cout <<  "Auteur = "<< res->getString("auteur") << endl; 
    cout <<  "Editeur = "<< res->getString("editeur") << endl; 
    cout <<  "Date = "<< res->getString("annee") << endl; 
    cout <<  "Prix = "<< res->getString("prix") << endl; 
   
   
  }
 

}

delete res;
delete stmt;
delete con;
} 
catch (sql::SQLException &e) {
// déblocage
cout << "# ERR: " << e.what();
cout << " (code erreur MySQL: " << e.getErrorCode();
cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
cout <<  endl;
};
 void supprimerunlivredelaliste(){
       
  int choix;
string supp;
cout << "Entrez ce que vous voulez supprimer: " << endl ;
cout << "Nom 1 Auteur 2 Editeur 3 Annee 4 Prix 5 " << endl ;
cin >> choix;
cout << "Entrez maintenant ce que vous voulez supprimé"  << endl;
while (getline(cin, supp))
    if (supp != "")
    break;
try {
// Les variables nécessaires pour la BDD

  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res ;
// Etape 1 : créer une connexion à la BDD
driver = get_driver_instance();

string ntt;
switch (choix)
{
case 1:
    ntt = "delete from livre where locate('" + supp + "',titre )  " ;
    break;
case 2 : 
    ntt = "delete from livre where locate('" + supp + "',auteur )  " ;
    break;
case 3 : 
    ntt = "delete from livre where locate('" + supp + "',editeur )  " ;
    break;
case 4 : 
    ntt = "delete from livre where locate('" + supp + "',annee )  " ;
    break;
case 5 : 
    ntt = "delete from livre where locate('" + supp + "',prix )  " ;
    break;
default:
    break;
} 
con = driver->connect("tcp://localhost", "lyes", "lyes"); // on va se connecter sur l utilasteur lyes avec comme mot de passe lyes
con->setSchema("bibliotheque"); // on sélectionne notre bdd 
stmt = con->createStatement();

stmt->execute(ntt);
cout << "c'est suppimer"<< endl;
delete stmt;
delete con;
} 
catch (sql::SQLException &e) {
// vérification de problème
cout << "# ERR: " << e.what();
cout << " (code erreur MySQL: " << e.getErrorCode();
cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
cout << endl;
  

 };
    void afficherlalistedeslivres(){
           try {

// Les variables nécessaires pour la BDD

  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res ;

driver = get_driver_instance();

string ntt = "select * from livre ";

con = driver->connect("tcp://localhost", "lyes", "lyes");
con->setSchema("bibliotheque");
stmt = con->createStatement();

if (res = stmt->executeQuery(ntt)){
sql::ResultSetMetaData *res_meta = res -> getMetaData();

  int columns = res_meta -> getColumnCount();
  while (res->next()) {
    /* Access column data by index, 1-indexed*/
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
// Gestion des execeptions pour déboggage
cout << "# ERR: " << e.what();
cout << " (code erreur MySQL: " << e.getErrorCode();
cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
cout << endl;

 
           }
    
}
     void ajouterunnouveaulivre(){
         string titre , auteur , editeur ;
    float date , prix;
    cout << "Entrez un Nom pour le livre" << endl;
    while (getline(cin, titre))
    if (titre != "")
    break;
    cout << "Entrez le Nom de l'auteur" << endl;
    while (getline(cin, auteur))
    if (auteur != "")
    break;
    cout << "Entrez le Nom de l'editeur" << endl;
    while (getline(cin, editeur))
    if (editeur != "")
    break;
    cout << "Entrez la date" << endl;
    cin >> date;
    cout << "Entrez le prix" << endl;
    cin >> prix;
    Livre x("" ,titre , auteur , editeur , date , prix);

    try {

// Les variables nécessaires pour la BDD
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  
driver = get_driver_instance();




string ntt = "insert into livre (isbn , titre , auteur , editeur , annee , prix) values(isbn ,'" + this->Titre + "','" + this->Auteur + "','" + this->Editeur + "','" + to_string(this->Annee) +"','" + to_string(this->Prix)  +"')" ;
con = driver->connect("tcp://localhost", "lyes", "lyes");
con->setSchema("bibliotheque");
stmt = con->createStatement();

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

     void Rechercherunlivreetaffichersesinformations(){
          int choix;
string mtf;
cout << "Entrez le choix de recherche : " << endl ;
cout << "Nom 1 Auteur 2 Editeur 3 Annee 4 Prix 5" << endl ;
cin >> choix;
cout << "Entrez maintenant le livre"  << endl;
while (getline(cin, mtf))
    if (mtf != "")
    break;
try {
// Les variables nécessaires pour la BDD

  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res ;

driver = get_driver_instance(); // connexion à la BDD

string ntt;
switch (choix)
{
case 1:
    ntt = "select * from livre where locate('" + mtf + "',titre )  " ;
    break;
case 2 : 
    ntt = "select * from livre where locate('" + mtf + "',auteur )  " ;
    break;
case 3 : 
    ntt = "select * from livre where locate('" + mtf + "',editeur )  " ;
    break;
case 4 : 
    ntt = "select * from livre where locate('" + mtf + "',annee )  " ;
    break;
case 5 : 
    ntt = "select * from livre where locate('" + mtf + "',prix )  " ;
    break;
default:
    break;
} 
con = driver->connect("tcp://localhost", "lyes", "lyes");
con->setSchema("bibliotheque");
stmt = con->createStatement();

if (res = stmt->executeQuery(ntt)){

 while (res->next()) {
   
    cout <<  "Titre = "<< res->getString("titre") << endl;
    cout <<  "Auteur = "<< res->getString("auteur") << endl; 
    cout <<  "Editeur = "<< res->getString("editeur") << endl; 
    cout <<  "Date = "<< res->getString("annee") << endl; 
    cout <<  "Prix = "<< res->getString("prix") << endl; 
   
   
  }
 

}


delete res; 
delete stmt;
delete con;
} 
catch (sql::SQLException &e) {
// vérification en cas de problème
cout << "# ERR: " << e.what();
cout << " (code erreur MySQL: " << e.getErrorCode();
cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
cout << endl;
}


     

void Gestiondelalistedeslivresdisponibles (){ // Ici on a le choix de choisir entre 5 fonctions dans le menu
      int choixA=0;
       cout <<  "********** Gestion de la liste des livres disponibles **********"<< endl;
       cout <<    "1. Afficher la liste des livres." << endl;
       cout <<    "2. Ajouter un nouveau livre." << endl;
       cout <<    "3. Rechercher un livre et afficher ses informations." << endl;
       cout <<    "4. Mettre à jour (modifier) les informations concernant un livre." << endl;
       cout <<    "5. Supprimer un livre de la liste." << endl;
       cout <<    "6. Retourner au menu précédent." << endl;
       cin  >> choixA;
            
            // Sélectione la fonction de notre choix sinon on retourne en arrière
       switch (choixA)   
      {
            case 1:
                  afficherlalistedeslivres();
                  break;  
            case 2:
                   ajouterunnouveaulivre();
                  break;
            case 3:
                 Rechercherunlivreetaffichersesinformations();
            break;
            case 4:    
              modifierlesinformationsconcernantunlivre();
             break;
            case 5:
             supprimerunlivredelaliste();
             break;  
            case 6:
             GestiondelaBibliotheque();
             break;
      }


            void afficherlalistedeslivres();{
            int choix1;
            cin  >> choix1;

            switch (choix1)
            {
             case 5:
                     Gestiondelalistedeslivresdisponibles (); 
                     break;
            }


            void ajouterunnouveaulivre();{
            int choix2;
            cin  >> choix2;

            switch (choix2)
            {
             case 5:
                     Gestiondelalistedeslivresdisponibles (); 
                     break;
            }
            }


             void Rechercherunlivreetaffichersesinformations();{
            int choix3;
            cin  >> choix3;

            switch (choix3)
            {
             case 5:
                     Gestiondelalistedeslivresdisponibles (); 
                     break;
            }
             }


             void  modifierlesinformationsconcernantunlivre();{
            int choix4;
            cin  >> choix4;

            switch (choix4)
            {
             case 5:
                     Gestiondelalistedeslivresdisponibles (); 
                     break;
            }
             }


             void  supprimerunlivredelaliste();{
            int choix5;
            cin  >> choix5;

            switch (choix5)
            {
             case 5:
                     Gestiondelalistedeslivresdisponibles (); 
                     break;
            }
             }

             void  GestiondelaBibliotheque();{
            int choix6;
            cin  >> choix6;

            switch (choix6)
            {
             case 5:
                     Gestiondelalistedeslivresdisponibles (); 
                     break;
            }
             }
            }
}
             
             
             
             
            

            
            











         


     
    
             
