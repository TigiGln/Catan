#include <iostream>
#include <time.h>

using namespace std;

#include "Map.hpp"
#include "Case.hpp"
#include "Player.hpp"



int main()
{
    srand(time(NULL));
    Map m;
    Player p;
    p.getmapSpe("bois");
    p.setmap("bois", "add");
    p.setmap("argile", "add");
    p.setmap("blé", "add");
    p.getmap();
    p.nbRessourceDispo();
    p.rollingDice();
    p.startTurn();
    return 0; 
}