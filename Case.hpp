#ifndef DEF_CASE
#define DEF_CASE

#include "Ressource.hpp"

#include <string>
#include <vector>

class Case
{
    //Attributs
    private:
        char m_id; //lettre de la matrice correspondant à la case
        int m_num; // numéro du jeton pour le lancer des dés
        bool m_tabPosition[6]; //position contruction colonie ou ville
        Ressource m_r; //ressource associé à la case
        std::vector<char> m_neighbours; //liste des cases voisines de la case

    public:
        Case();//Constructeur basic
        Case(char id); //Constructeur
        ~Case(); //Destructeur
        void setTabPosition(int pos);//modification des positions lors d'une construction
        std::string getR();
        void setId(char id);//génère la place de la case aléatoirement.
        char getId(); //récupérer la lettre associé
        int getNum(); //récupérer le numéro associé
        bool getTabPosition(); // récupérer les position disponible de construction
        void setR(std::string ressource);//Modification de la ressource de la Case
        std::string setRJoueur(int dice);//ajout ressource joueurs
        void setNeighbours(char idCase);//modification de la liste cases voisines dans la map
        std::vector<char> getNeighbours();
        void getNeighbour();
        

};

#endif