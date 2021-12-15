#ifndef DEF_MAP
#define DEF_MAP

#include "Case.hpp"

#include <vector>

class Map
{
    //Attributs
    private:
        char **m_matrix;//map du jeu avec emplacement des cases
        std::vector<Case> m_listCases;//liste d'objet cases
        std::vector<char> m_listId;//liste des noms des cases
    public:
        Map();//Constructeur
        ~Map();//Destructeur
        void getmatrix();//affichage matrice
        char getElemMatrix(int line, int column);//Répération un id de case de la matrice
        void setmatrix();//modication ou insertion dans la matrice
        void setCases();//modifications et création des cases de la matrice
        std::vector<Case> getCases();//Visualisation des données de chaque case de la matrice
        Case getCase(char id);
        void setRCases(); //modifications ou affectation des ressources au cases de la matrice
        void setNeighbours(); //Récupération des voisins pour chaques cases
        void setlistId();//Création ou modification de la liste des id de chaque case
        std::vector<char> getlistId(); //Récupération de la liste des id des cases
        std::vector<int> getCoordinateCase(char id);//récupère le vecteur de coordonnées (ligne/colonne) de la matrice
        void setCoordinateCase();//ajoute les coordonnées de la matrice à la case
        void setDictPositionVoisionDispo();
        void setMapPositionColonyDispo();
        void updateMapPositionColonyDispo(char nameCase, std::string positionCase, bool possible);
        void getMapPositionColonyDispo(char nameCase, std::string positionCase);
        char intersectNeighbours(char namecase1, char namecase2);//récupère l'intersection des voisins entre deux cases
        bool checkpositionColonyDispo(std::string position);//check si la position de la case est disponible ou pas et renvoie un bool
               
        
};

#endif