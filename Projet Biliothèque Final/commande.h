#include <iostream>  
using namespace std;
// SI ALI LYES

class commande {  // Création de l'objet 

    public:

                commande();    //Constructeur 
                ~commande();   //Destructeur

                commande(int IDCM, string IDCGM, int DATE, float Total);

                void setIDCM(int ident);
                int getIDCM();

                void setIDCGM(string identcli);
                string getIDCGM();

                void setDATE(int jour);
                int getDATE();

                void setTotal(float totale);
                float getTotal();
    private :
                int IDCM;   // Identifiant de la commande.
                string IDCGM;  // Identifiant du client ayant passé la commande.
                int    DATE;   // Date de la commande.
                float  Total;  // Prix total de la commande.
};