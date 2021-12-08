#include "Player.hpp"
#include "Map.hpp"
#include "Case.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

Player::Player(string name, string color):m_score(0), m_name(name), m_color(color), m_nbRoads(0), m_nbColony(0), m_nbCities(0), m_nbColonyInit(5), m_nbRoadInit(15), m_nbCitiesInit(4)
{
    m_tabRessource.insert(make_pair("argile", 0));
    m_tabRessource.insert(make_pair("ble", 0));
    m_tabRessource.insert(make_pair("minerai", 0));
    m_tabRessource.insert(make_pair("bois", 0));
    m_tabRessource.insert(make_pair("laine", 0));
    
}

Player::~Player(){}

void Player::getRessources()
{
    for(const auto & it : m_tabRessource)
    {
        cout << it.first << ": " << it.second << endl;
    }
}

int Player::getRessource(string ressource)
{
    auto iter = m_tabRessource.find(ressource);
    cout << "Il vous reste " << iter->second << " unité de " << iter->first << endl;
    return iter->second;
}

void Player::setRessource(string key, string action)
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

void Player::startTurn(vector<Case> list_Cases, vector<char> listId)
{
    cout << "startTurn: " << "\n";
    rollingDice();
    char response;
    string test;
    if(m_tabRessource["bois"] >= 1 && m_tabRessource["argile"] >= 1)
    {
        do
        {
            cout << "Voulez vous construire une route : (y/n)";
            cin >> response;
            if(response == 'y')
            {
                string nameCase1, nameCase2;
                do
                {
                    cout << "Selon les lettres de la matrice, veuillez choisir une des cases encadrant votre route : ";
                    cin >> nameCase1;
                } while (nameCase1.size() != 1);
                do
                {
                    cout << "Veuillez choisir une lettre parmi les suivantes ";
                    cin >> nameCase2;
                    
                } while (nameCase2.size() != 1);
                transform(nameCase1.begin(), nameCase1.end(), nameCase1.begin(), ::toupper);
                transform(nameCase2.begin(), nameCase2.end(), nameCase2.begin(), ::toupper); 
                test = placeRoad(nameCase1, nameCase2, list_Cases);
            }
        } while (test != "OK");
    }
    if(m_tabRessource["bois"] >= 1 && m_tabRessource["argile"] >= 1 && m_tabRessource["blé"] >= 1 && m_tabRessource["laine"] >= 1)
    {
        cout << "Voulez vous construire une colonie : (y/n)";
        cin >> response;
        if(response == 'y')
        {
            string nameCase1, nameCase2,nameCase3;
        }
    }
}

int Player::getscore()
{
    return m_score;
}

char Player::stopTurn()
{
    int score = getscore();
    if(score < 10)
    {
        char response;
        cout << "Avez vous fini votre tour ? (y/n)";
        cin >> response;
        return response;
    }
    else
    {
        cout << "Vous êtes le grand gagnant de cette partie !!!";
        return 'q'; 
    }
}

void Player::winRessources(vector<Case> list_Cases)
{
    cout << "winRessource : " << "\n";
    int dices = rollingDice();
    for(int i=0; i<list_Cases.size(); i++)
    {
        if(list_Cases[i].getNum() == dices)
        {
            setRessource(list_Cases[i].getR(), "add");

        }
    }
}

string Player::placeRoad(string nameCase1, string nameCase2, vector<Case> list_Cases)
{
    for(int index=0; index<list_Cases.size(); index++)
    {
        if(list_Cases[index].getId() == nameCase1[0])
        {
            vector<char> list_neighbour = list_Cases[index].getNeighbours();
            for(int neighbour = 0; neighbour < list_neighbour.size(); neighbour++)
            {
                if(list_neighbour[neighbour] == nameCase2[0])
                {
                    m_nbRoadInit--;
                    m_nbRoads++;
                    Road r(nameCase1[0], nameCase2[0]);
                    m_tabRoad.push_back(r);
                    getnbRoadsInit();
                    getnbRoads();
                    cout << "Votre route a bien été ajouté." << "\n";
                    return "OK";
                }
                
            }
        }
    }
    cout << "Vous avez donné des paramètres erronés, veuillez réessayer !!" << endl;
    return "No";
    
}

void Player::getTabRoad()
{
    for(int index=0; index<m_tabRoad.size(); index++)
    {
        vector<char> m_tab = m_tabRoad[index].getCoordinates();
        cout << "[";
        for(int i=0; i<m_tab.size(); i++)
        {
            if(i<m_tab.size())
            {
                cout << m_tab[i] << ",";
            }
            else
            {
                cout << m_tab[i] ;
            }
            
        }
        cout << "]" << endl;
    }
}

int Player::getnbRoads()
{
    cout << "Vous disposez maintenant de " << m_nbRoads << " routes" << endl;
    return m_nbRoads;
}

void Player::getnbRoadsInit()
{
    cout << "Il ne vous reste plus que " << m_nbRoadInit << " route à construire." << endl;
}
void Player::getnbColonyInit()
{
    cout << m_nbColonyInit << endl;
}