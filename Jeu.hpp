#ifndef DEF_JEU
#define DEF_JEU


#include <vector>
#include <string>

#include "Map.hpp"
#include "Player.hpp"

class Jeu
{
    private:
        Map m_map;
        std::vector<Player> m_listPlayers;
    public:
        Jeu(int nbPlayers);
        ~Jeu();
        void setPlayers(int nbPlayers);
        void getPlayers();
        void tour(std::string namePlayer, int indexplayer);
        void PlacementInitial();
        void placementColonyInitial(int indexplayer);
        int nbArgument();
        std::string coordinatesAsk(int nbCasesTotal);
        char coordinatesAsk(int nbCasesTotal, char nameCase);
        char coordinatesAsk(int nbCasesTotal, char nameCase, char nameCase2);
        bool isNumber(std::string s);
};

#endif