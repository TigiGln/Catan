#ifndef DEF_JEU
#define DEF_JEU


#include <vector>

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
};

#endif