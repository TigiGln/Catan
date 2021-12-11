#ifndef DEF_PLAYER
#define DEF_PLAYER

#include <unordered_map>
#include <vector>
#include <string>

#include "Map.hpp"
#include "Case.hpp"
#include "Settlement.hpp"
#include "Road.hpp"


class Player
{
    private:
        std::unordered_map<std::string, int> m_tabRessource;//dictionnaire des ressources
        std::vector<Settlement> m_Settlements; //tableau d'objets Colonie
        std::vector<Road> m_tabRoad;//tableau de routes
        std::string m_color; //couleur du joueur
        int m_score; // score du joueur 
        std::string m_name;//nom du joueur
        int m_nbRoads; //nombre de route placée sur la map
        int m_nbColony; //nombre de colonie placée sur la map
        int m_nbCities; //nombre de cité placée sur la map
        int m_nbColonyInit;//nombre de colonie pouvant être placée
        int m_nbRoadInit;//nombre de route pouvant être placée
        int m_nbCitiesInit;//nombre de cité pouvant être placée

    public:
        Player(std::string name, std::string color);// Constructeur
        ~Player();//Destructeur
        void getRessources();//Affichage de la map
        std::unordered_map<std::string, int> returnRessources();
        int getRessource(std::string ressource);//Affichage spécifique
        void setRessource(std::string key, std::string action);//permet de modifier le nombre pour une ressource
        int nbRessourceDispo(); //permet de savoir combien de carte ressource a le joueur;
        int rollingDice(); //Lancement des dés
        void start();//Début du jeu pour le joueur
        void startTurn(Player player, std::vector<Case> list_Cases);//Début du tour
        char stopTurn();//Fin du tour
        void placementColony(Case case1, Case case2, Case case3);
        std::string placeSettlement(std::string nameCase, int positionCase);//Placement de colonie en cours de partie
        std::string placeRoad(); //Placement d'une route en début de partie
        std::string placeRoad(std::string nameCase1, std::string nameCase2, std::vector<Case> list_Cases);//Placement des routes en cours de partie avec coordonnée
        
        void getcolor();//Récupérer couleur joueur
        int getscore();// Récupérer le score
        void winRessources(int dices, std::vector<Case> list_Cases); //Gagne ressource avec les dés
        void getTabRoad();//Affiche le tableau
        int getnbRoads();//Récupère le nombre de route du joueur
        void getnbRoadsInit();//Affiche le nombre de route restantes
        void getnbColonyInit();//Affiche le nombre de colonie restantes à construire
        void getname();
};



#endif