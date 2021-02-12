#include <iostream> 
using namespace std;
// SI ALI LYES

class Livre
 {              
    public:
                Livre();    //Constructeur
                Livre(int ISBN, string Titre, string Auteur, string Editeur, int Annee, float Prix);
                ~Livre();   //Destructeur

                void setISBN(int code);
                int getISBN();

                void setTitre(string title);
                string getTitre();

                void setAuteur(string Autor);
                string getAuteur();

                void setEditeur(string Edit);
                string getEditeur();

                void setAnnee(int year);
                int getAnnee();

                void setPrix(float price);
                float getPrix();

                
    private:  // Ne peut pas être appelé depuis l'extérieur de l'objet.      
               int     ISBN;    // Code du livre.
               string  Titre;   // Titre du livre.
               string  Auteur;  // Premier auteur du livre. 
               string  Editeur; // Éditeur du livre.
               int     Annee;   // Année d'édition du livre.
               float   Prix;    // Prix du livre en Euros.
}; 