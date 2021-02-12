#include <iostream>  
using namespace std;
// SI ALI LYES

class client { // Création de l'objet 

    public:

                client();    //Constructeur
              ~ client();    //Destructeur

                client(string IDC, string Nom, string  Adresse, int Tel,  int Anciennete);
                void setIDC(string ident);
                string getIDC();

                void setNom(string name);
                string getNom();

                void setAdresse(string Adr);
                string getAdresse();

                void setTel(int number);
                int getTel();

                void setAnciennete(int ancien);
                int getAnciennete();
        
    private :

               string IDC;     // Identification du client.
               string Nom;     // Nom ou raison sociable.
               string Adresse; // Adresse du client.
               int    Tel;     // Numéro de téléphone du client.
               int    Anciennete; // Date d'inscription du client.
};