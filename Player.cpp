#include "Player.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

Player::Player()
{
    m_tabRessource.insert(make_pair("argile", 0));
    m_tabRessource.insert(make_pair("ble", 0));
    m_tabRessource.insert(make_pair("minerai", 0));
    m_tabRessource.insert(make_pair("bois", 0));
    m_tabRessource.insert(make_pair("laine", 0));
    
}

Player::~Player(){}

void Player::getmap()
{
    for(const auto & it : m_tabRessource)
    {
        cout << it.first << ": " << it.second << endl;
    }
}

int Player::getmapSpe(string ressource)
{
    auto iter = m_tabRessource.find(ressource);
    cout << "Il vous reste " << iter->second << " unité de " << iter->first << endl;
    return iter->second;
}

void Player::setmap(string key, string action)
{
    if(action == "add")
    {
        m_tabRessource[key] ++;
    }
    else if(action == "remove")
    {
        m_tabRessource[key] --;
    }
}

int Player::nbRessourceDispo()
{
    int nbRessource = 0;
    for(auto & iter : m_tabRessource)
    {
        nbRessource += iter.second;
    }
    cout << nbRessource << endl;
    return nbRessource;
}

int Player::rollingDice()
{
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 +1;
    int sumDice = dice1 + dice2;
    cout << sumDice << endl;
    return sumDice;
}

// void Player::start()
// {
//     string nameCase;
//     int positionCase;
//     cout << "Veuillez choisir une case : \n";
//     cin >> nameCase;
//     cout << "Veuillez entrer la position entre 1 et 6 sur laquelle va être placé votre colonie : ";
//     cin >> positionCase;
//     placeSettlement(nameCase, positionCase);
//     placeRoad();
//     rollingDice();
// }

void Player::startTurn()
{
    rollingDice();
    char response;
    cout << "Voulez vous construire une route : (y/n)";
    cin >> response;
    if(response == 'y')
    {
        string nameCase1, nameCase2;
        while(nameCase1.size() != 1 && nameCase2.size() != 1)
        {
            cout << "Veuillez choisir une des cases encadrant votre route : ";
            cin >> nameCase1;
            cout << "Veuillez la seconde case : ";
            cin >> nameCase2;
        }
        transform(nameCase1.begin(), nameCase1.end(), nameCase1.begin(), ::toupper);
        transform(nameCase2.begin(), nameCase2.end(), nameCase2.begin(), ::toupper);
        cout << nameCase1 << "\n";
        cout << nameCase2 << "\n";
    }

}