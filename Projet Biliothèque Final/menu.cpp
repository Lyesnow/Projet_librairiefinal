#include "menu.h"

// SI ALI LYES


int main() { 
      GestiondelaBibliotheque();
      return 0;
}

void GestiondelaBibliotheque(){ //On va pouvoir choisir dans le menu entre livre, clients et commandes
      int choix1=0;
      cout << " ********** Gestion de la bibliothèque **********" << endl;
      cout << "1. Gestion de la liste des livres disponibles " << endl;
      cout << "2. Gestion de la liste des clients " << endl;
      cout << "3. Gestion de la liste des commandes " << endl;
      cout << "4. Quitter " << endl;
      cin >> choix1;

      switch (choix1)  // Si il choisit le choix 1,2,3  il sera dirigé vers les livres, clients out commandes si non il retourne au menu
      {
            case 1:
                  Gestiondelalistedeslivresdisponibles(); 
                  break;
      case 2:
            Gestiondelalistedesclients();
            break;
       case 3:    
             Gestiondelalistedescommandes();
             break;
      case 4:
             break;       
      }


void Gestiondelalistedeslivresdisponibles ();{
      int choix2;
       cin  >> choix2;

       switch (choix2)
       {
             case 5:
                     GestiondelaBibliotheque();   // retour sur le menu
                     break;
       }

    } 
void  Gestiondelalistedesclients() ;{
      int choix3;
      cin >> choix3;
 

       switch (choix3)
       {
             case 5:
                     GestiondelaBibliotheque(); // retour sur le menu
                     break;
       }



}
void Gestiondelalistedescommandes();{
      int choix4;
      cin >>choix4;
    
      switch (choix4)
       {
             case 5:
                     GestiondelaBibliotheque(); // retour sur le menu
                     break;
       }

}
}

