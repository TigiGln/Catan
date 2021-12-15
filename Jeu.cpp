#include "Jeu.hpp"
#include "Case.hpp"
#include "Map.hpp"

#include <iostream>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <vector>

using namespace std;

Jeu::Jeu(int nbPlayers)
{
    setPlayers(nbPlayers);
    PlacementInitial();
    bool score = false;
    string namePlayer {""};
    while(score == false)
    {
        for(int player=0; player<m_listPlayers.size(); player++)
        {
            tour(namePlayer, player);
            if(m_listPlayers[player].getscore() == 10)
            {
                score = true;
                break;
            }
            namePlayer = m_listPlayers[player].getname();
           
        }
    
    }
    cout << "Félicitation à " << namePlayer << ", il est déclaré grand vainqueur de la partie" << endl;
    
    
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

void Jeu::tour(string namePlayer, int indexplayer)
{
    cout << "C'est au tour de " <<  namePlayer << "." << endl;
    m_listPlayers[indexplayer].rollingDice();
    /* C'est dans cette methode qu'on va ensuite mettre 
    les instruction pour chaque tour jusqu'à ce que le score d'un des joueurs arrive à 10 */
}

void Jeu::PlacementInitial()
{
    for(int player=0; player<m_listPlayers.size(); player++)
    {
        cout << m_listPlayers[player].getname() << " A vous de jouer" << endl;
        placementColonyInitial(player); 
    }
    for(int player=m_listPlayers.size()-1; player>=0; --player)
    {
        cout << m_listPlayers[player].getname() << " A vous de jouer" << endl;
        placementColonyInitial(player);
    }

}

void Jeu::placementColonyInitial(int indexplayer)
{
    vector<char> listnameCases;
    int nbCases = nbArgument();
    int nbCasesTotal = nbCases;
    int nbtour {0};
    char idCase;
    string positionColony;
    while(nbCases > 0)
    {
        if(nbtour == 0)
        {
            positionColony = coordinatesAsk(nbCasesTotal);
            idCase = positionColony[0];
        }
        else if(nbtour == 1) 
        {
            idCase = coordinatesAsk(nbCasesTotal, listnameCases[nbtour-1]);
            positionColony = idCase;
            string strtmp; 
            strtmp = listnameCases[nbtour-1];
            positionColony = strtmp + positionColony;
        }
        else
        {
            idCase = coordinatesAsk(nbCasesTotal, listnameCases[nbtour-2], listnameCases[nbtour-1]);
            positionColony = idCase;
            string strtmp;
            string strtmp2;
            strtmp = listnameCases[nbtour-2];
            strtmp2 = listnameCases[nbtour-1];
            positionColony = strtmp + strtmp2 + positionColony;
        }
        
        listnameCases.push_back(idCase);
        nbCases--;
        nbtour++;
        
    }
    bool dispo {true};
    if(nbCasesTotal == 1)
    { 
        if(m_map.checkpositionColonyDispo(positionColony) == 1)
        {
            
            m_listPlayers[indexplayer].placeSettlement("start", nbCasesTotal, listnameCases[0]);
            m_map.updateMapPositionColonyDispo(idCase, positionColony, false);
        }
        else
        {
            cout << "Désolé cette place est déjà occupé" << endl;
            placementColonyInitial(indexplayer);
        }   
    }
    else if (nbCasesTotal == 2)
    {
        
        if(m_map.checkpositionColonyDispo(positionColony) == 1)
        {
            string positionColony2;
            string strtmp, strtmp2;
            strtmp = listnameCases[0];
            strtmp2 = listnameCases[1];
            positionColony2 = strtmp2 + strtmp;
            m_listPlayers[indexplayer].placeSettlement("start", nbCasesTotal, listnameCases[0], listnameCases[1]);
            m_map.updateMapPositionColonyDispo(listnameCases[0], positionColony, false);
            m_map.updateMapPositionColonyDispo(listnameCases[1], positionColony2, false);
        }
        else 
        {
            cout << "Désolé cette place est déjà occupé, veuillez recommencer" << endl;
            placementColonyInitial(indexplayer);
        }
        
    }
    else if (nbCasesTotal == 3)
    {
        
        if(m_map.checkpositionColonyDispo(positionColony) == 1)
        {
            string positionColony2;
            string positionColony3;
            string strtmp, strtmp2, strtmp3;
            strtmp = listnameCases[0];
            strtmp2 = listnameCases[1];
            strtmp3 = listnameCases[2];
            positionColony2 = strtmp3 + strtmp + strtmp3;
            positionColony3 = strtmp3 + strtmp + strtmp2;
            m_listPlayers[indexplayer].placeSettlement("start", nbCasesTotal, listnameCases[0], listnameCases[1], listnameCases[2]);
            m_map.updateMapPositionColonyDispo(listnameCases[0], positionColony, false);
            m_map.updateMapPositionColonyDispo(listnameCases[0], positionColony2, false);
            m_map.updateMapPositionColonyDispo(listnameCases[0], positionColony3, false);
            
        }
        else
        {
            cout << "Désolé cette place est déjà occupé, veuillez recommencer" << endl;
            placementColonyInitial(indexplayer);
        }
        
    }
        
        
    
}
bool Jeu::isNumber(string s)
{
   
    return isdigit(s[0]); 
    
}
int Jeu::nbArgument()
{
    int NbCases;
    string nbCases;
    bool check;
    do
    {
        cout << "Combien de cases entourent la colonie que vous souhaitez poser ? (1/2/3)" << endl;
        cin >> nbCases;
        check = isNumber(nbCases);
        if(check == 1)
        {
            NbCases = stoi(nbCases);
        }
        
    } while (check != 1 && NbCases < 1 || NbCases > 3);
    
    
    
    return NbCases;
}

string Jeu::coordinatesAsk(int nbCasesTotal)
{
    string idCase;
    string posCase;
    string idCasereturn;
    bool check;
    bool check2 {false};
    bool check3;
    do
    {
        cout << "Choisissez une lettre ou un symbole selon cette liste ";
        cout << "[A, B, C, D, E, F, G, H, I, J, K, L, M, N O, P, Q, R, S, T, U, V, W, X, Y, Z, &, #, @, $]" << endl;
        cin >> idCase;
        check = isNumber(idCase);
        if(check == 1)
        {
            cout << "Merci de donner un identifiant de case valide" << endl;
        }
        else
        {
            transform(idCase.begin(), idCase.end(), idCase.begin(), ::toupper);
        }
        if(nbCasesTotal == 1)
        {
            if(idCase[0] == 'A' || idCase[0] == 'G' || idCase[0] == 'J' || idCase[0] == 'U' || idCase[0] == 'X' || idCase[0] == '$')
            {
                do
                {
                    cout << "Merci d'indiquer une position (1/2)" << endl;
                    cin >> posCase;
                    check3 = isNumber(posCase);
                    if(posCase == "1" || posCase == "2")
                    {
                        check2 = true;
                    }
                    idCasereturn = idCase + posCase;
                } while(check2 == false || check3 == 0);
            }
        }
        else
        {
            idCasereturn = idCase;
        }
        
    } while(idCase.size() != 1 || check != 0);

    return idCasereturn;
}

char Jeu::coordinatesAsk(int nbCasesTotal, char nameCase)
{
    string idCase;
    bool check;
    do
    {
        cout << "Choisissez une lettre ou un symbole selon cette liste ";
        m_map.getCase(nameCase).displayNeighbour();
        cin >> idCase;
        check = isNumber(idCase);
        if(check == 1)
        {
            cout << "Merci de donner un identifiant de case valide" << endl;
        }
        else
        {
            transform(idCase.begin(), idCase.end(), idCase.begin(), ::toupper);
        }
    } while (m_map.getCase(nameCase).getNeighbour(idCase[0]) == false);

    return idCase[0];
}

char Jeu::coordinatesAsk(int nbCasesTotal, char nameCase, char nameCase2)
{
    string idCase;
    bool check;
    char elem;
    do
    {
        cout << "Choisissez une lettre ou un symbole selon cette liste ";
        elem = m_map.intersectNeighbours(nameCase, nameCase2);
        cout << endl;
        cin >> idCase;
        check = isNumber(idCase);
        if(check == 1)
        {
            cout << "Merci de donner un identifiant de case valide" << endl;
        }
        else
        {
            transform(idCase.begin(), idCase.end(), idCase.begin(), ::toupper);
        }
    } while (idCase[0] != elem);
    
    return idCase[0];

}




