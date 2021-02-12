#include "menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include "commande.h"
using namespace std;
// SI ALI LYES
 void afficherlescommandes(){
            try {
// Les variables pour la bdd

  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res ;
//  connexion à la BDD
driver = get_driver_instance();

string ntt = "select * from commande ";  // on va afficher tout qu'il y a dans commande

con = driver->connect("tcp://localhost", "lyes", "lyes"); // on va se connecter sur l utilasteur lyes avec comme mot de passe lyes
con->setSchema("bibliotheque"); // on selectionne notre bdd 
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
// verification en cas de probleme 
cout << "# ERR: " << e.what();
cout << " (code erreur MySQL: " << e.getErrorCode();
cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
cout << endl;

 
}
    
 void creerunenouvellecommande(){
       string idcm , idcgm ;
    float date , total;
    cout << "Entrez  l'idcm de la commande" << endl;
    while (getline(cin, idcm))
    if (idcm != "")
    break;
    cout << "Entrez l'idcgm de la commande" << endl;
    while (getline(cin, idcgm))
    if (idccm != "")
    break;
    cout << "Entrez la date de la commande" << endl;
    cin >> date;
    cout << "Entrez le prix total de la ou les commande " << endl;
    cin >> total;
    Commande x(idcm , idcgm, date , total);

    try {
// variables pour la bdd

  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
 
// connexion à la BDD
driver = get_driver_instance();


// cree la table
string newTable = " create table if not exists commande(idcm int not null primary key auto_increment,idcm int , idl int   foreign key (idcgm) references `livre`(`isbn`) , foreign key (idcm) references `client`(`idcm`) , date int(40))";
// remplir les informations
string ntt = "insert into commande (idccm , idcm , idl ,date ) values(id ,'" + this->IDCGM+ "','" + this->IDCM + "','" + to_string(this->Date) +"','" + to_string(this->Total)  +"')" ;
con = driver->connect("tcp://localhost", "lyes", "lyes"); // on va se connecter sur l utilasteur lyes avec comme mot de passe lyes
con->setSchema("bibliotheque"); // on selectionne notre bdd 
stmt = con->createStatement();
stmt->execute(newTable);
stmt->execute(ntt);

delete stmt;
delete con;
} catch (sql::SQLException &e) {
// verification en cas de probleme 
cout << "# ERR: " << e.what();
cout << " (code erreur MySQL: " << e.getErrorCode();
cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
cout << endl;
}
     
void Rechercherunecommandeetaffichersesinformations();
int choix;
string mtf;
cout << "Entrez le choix de votre recherche " << endl ;
cout << " date 1" << endl ;
cin >> choix;
cout << "Entrez maintenant la recherche que vous desirez"  << endl;
while (getline(cin, mtf))
    if (mtf != "")
    break;
try {
//variable pour la bdd

  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res ;
//  connexion à la BDD
driver = get_driver_instance();

string ntt;
switch (choixt)
{
case 1:
    ntt = "select * from commande where locate('" + mtf + "',date )  " ;
    break;

default:
    break;
} 
con = driver->connect("tcp://localhost", "lyes", "lyes"); // on va se connecter sur l utilasteur lyes avec comme mot de passe lyes
con->setSchema("biliotheque"); // on selectionne notre bdd 
stmt = con->createStatement();

if (res = stmt->executeQuery(ntt)){

 while (res->next()) {
   
    
    cout <<  "date = "<< res->getString("date") << endl; 
      
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
cout << endl;
}
 void modifierlesinformationsconcernantlacommande();
 {
   string mtf;
   int var1,var2;
   cout << "modifier votre choix , date 1 " << endl;
   cin >> var1;
   cout << " id commande" << endl;
   cin >> var2;
   cout << "entrez votre recherche "<< endl;
   cin >> mtf;
   try{
         //variable pour la bdd

  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res ;
//  connexion à la BDD
driver = get_driver_instance();
string ntt, slt ;

switch (var1)
{
      case 1:
      ntt = "UPDATE commande SET date = '" + mtf + "' where idcm = '" + to_string(var2) + "'";
      slt= " select * from commande where locate ('"+ mtf + "',date ) ";
      break;
      default:
      break;
}
con = driver->connect("tcp://localhost", "lyes", "lyes");// on va se connecter sur l utilasteur lyes avec comme mot de passe lyes
con->setSchema("bibliotheque");// on selectionne notre bdd
stmt = con->createStatement();
stmt->execute(ntt);
if (res = stmt->executeQuery(ntt)){
while (res->next()) {
    // affichage après la modification
cout <<  "Date = "<< res->getString("date") << endl; 
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
cout <<  endl;
}


 void supprimerunecommandedelaliste();
 {
  int choix;
string mtf;
cout << "Entrez ce que vous voulez supprimer " << endl ;
cout << "Idcm ->1 Idcgm ->2 Date ->3 total ->4" << endl ;
cin >> choix;
cout << "Entrez maintenant la recherche"  << endl;
while (getline(cin, mtf))
    if (mtf != "")
    break;
try {
// Les variables nécessaires à notre programme

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
    ntt = "delete from commande where locate('" + mtf + "',idcm )  " ;
    break;
case 2 : 
    ntt = "delete from commande where locate('" + mtf + "',Idcgm)  " ;
    break;
case 3 : 
    ntt = "delete from commande where locate('" + mtf + "',date)  " ;
    break;
case 4 : 
    ntt = "delete from commande where locate('" + mtf + "',total)  " ;
    break;

default:
    break;
} 
con = driver->connect("tcp://localhost", "lyes", "lyes");
con->setSchema("bibliotheque");
stmt = con->createStatement();

stmt->execute(ntt);
cout << "C'est supprimé "<< endl;
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
 

void Gestiondelalistedescommandes(){
      int choix4;
      cout <<  "********** Gestion de la liste des commandes **********"<< endl;
      cout <<    "1.Afficher les commandes." << endl;
      cout <<    "2.Créer une nouvelle commande." << endl;
      cout <<    "3. Rechercher une commande et afficher ces informations." << endl;
      cout <<    "4. Mettre à jour (modifier) les informations concernant une commande." << endl;
      cout <<    "5. Supprimer une commande de la liste." << endl;
      cout <<    "6. Retourner au menu précédent." << endl;
      cin >> choix4;

       switch (choix4)
      {
            case 1:
                  void Afficherlescommandes();
                  break;
            case 2:
                  void creerunenouvellecommande();
                  break;
            case 3:
            void Rechercherunecommandeetaffichersesinformations();
            break;
            case 4:    
             void modifierlesinformationsconcernantlacommande();
             break;
            case 5:
             void supprimerunecommandedelaliste();
             break;    
            case 6:
             GestiondelaBibliotheque();
             break;
      }

}
