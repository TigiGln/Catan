#include "Jeu.hpp"

#include <iostream>
#include <string>

using namespace std;

Jeu::Jeu(int nbPlayers)
{
    
    setPlayers(nbPlayers);
    getPlayers();
}


Jeu::~Jeu(){}


void Jeu::setPlayers(int nbPlayers)
{
    vector<string> tabColor = {{"blue", "red", "green", "yellow", "black", "white"}};
    for(int i=0; i<nbPlayers; i++)
    {
        string name="player" + to_string(i+1);
        Player p(name, tabColor[i]);
        m_listPlayers.push_back(p);
    }
}

void Jeu::getPlayers()
{
    for(int i=0; i<m_listPlayers.size(); i++)
    {
        m_listPlayers[i].getname();
        m_listPlayers[i].getcolor();
    }
}