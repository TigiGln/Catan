#ifndef DEF_PLAYER
#define DEF_PLAYER

#include <unordered_map>
#include <vector>
#include <string>

class Player
{
    private:
        std::unordered_map<std::string, int> m_tabRessource;//dictionnaire des ressources
        //std::vector<Settlement> m_Settlements; //tableau d'objets Colonie
        std::string color; //couleur du joueur
        int score; // score du joueur 
        std::string name;//nom du joueur
        int nbRoads; //nombre de route placée sur la map
        int nbColony; //nombre de colonie placée sur la map
        int nbCities; //nombre de cité placée sur la map
        int nbColonyInit;//nombre de colonie pouvant être placée
        int nbRoadInit;//nombre de route pouvant être placée
        int nbCitiesInit;//nombre de cité pouvant être placée

    public:
        Player();// Constructeur
        ~Player();//Destructeur
        void getmap();//Affichage de la map
        int getmapSpe(std::string ressource);//Affichage spécifique
        void setmap(std::string key, std::string action);//permet de modifier le nombre pour une ressource
        int nbRessourceDispo(); //permet de savoir combien de carte ressource a le joueur;
        void start();//Début du jeu pour le joueur
        void startTurn();//Début du tour
        void stopTurn();//Fin du tour
        std::string placeSettlement();//Placement d'une colonie
        std::string placeRoad(); //Placement d'une route
        int rollingDice(); //Lancement des dés

};



#endif