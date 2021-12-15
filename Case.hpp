#ifndef DEF_CASE
#define DEF_CASE

#include "Ressource.hpp"

#include <string>
#include <vector>
#include <map>

class Case
{
    //Attributs
    private:
        char m_id; //lettre de la matrice correspondant à la case
        int m_num; // numéro du jeton pour le lancer des dés
        bool m_tabPosition[6]; //position contruction colonie ou ville
        std::map<std::string, bool> m_positionDispoColony; //position disponible pour la construction des colonies.
        Ressource m_r; //ressource associé à la case
        std::vector<char> m_neighbours; //liste des cases voisines de la case
        std::map<std::string, int> m_dictCoordinates; //coordonnees sur la map
        std::map<char, bool> m_dictPositionDispo;//dictionnaire coordonnées de la case sur la matrice

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
        void displayNeighbour();
        bool getNeighbour(char idNeighbour);
        void setCoordinate(int line, int column);
        void getCoordinate();
        void setPositionRoadDispo(char idVoisin, bool possible);
        void getPositionRoadDispo(char idVoisin);
        void setPositionColonyDispo(std::string combinaison, bool possible, std::string add);
        bool getPositionColonyDispo(std::string combinaison);
        
};

#endif