#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
#include <unordered_map>


using namespace std;

#include "Map.hpp"
#include "Case.hpp"
#include "Player.hpp"
#include "Jeu.hpp"

bool isNumber(string s)
{
   
    return isdigit(s[0]); 
    
}
int startGame()
{
    
    cout << "***************************************************************************" << "\n";
    cout << "***************************************************************************" << "\n";
    cout << "***************************************************************************" << "\n";
    cout << "************************  COLON DE CATANE  ********************************" << "\n";
    cout << "***************************************************************************" << "\n";
    cout << "***************************************************************************" << "\n";
    cout << "***************************************************************************" << "\n";
    cout << endl;

    cout << "Bienvenue dans ce jeu de conquête des territoires, le premier qui atteint un score de 10 est déclarer grand vainqueur !!" << endl;
    string nbJoueurs;
    bool check;
    int nbJoueursChoice;
    do
    {
        
        cout << "Combien de joueur serez vous ? (2-6)" << "\n";
        cin >> nbJoueurs;
        check = isNumber(nbJoueurs);
        if(check == 1)
        {
            nbJoueursChoice = stoi(nbJoueurs);
            
        }
        
    } while(check != 1 || nbJoueursChoice < 2 || nbJoueursChoice > 6);
    return nbJoueursChoice;
}

vector<string> buildColony(unordered_map<std::string, int> mapRessource)
{
    vector<string> tabcoordinates;
    char response;
    if(mapRessource["bois"] >= 1 && mapRessource["argile"] >= 1 && mapRessource["blé"] >= 1 && mapRessource["laine"] >= 1)
    {
        cout << "Voulez vous construire une colonie : (y/n)";
        cin >> response;
        if(response == 'y')
        {
            string nameCase1, nameCase2,nameCase3;
            do
            {
                cout << "Selon les lettres de la matrice, veuillez choisir la première case qui va encadrer votre colonie ";
                cin >> nameCase1;
            } while (nameCase1.size() != 1);
            do
            {
                cout << "Veuillez choisir une deuxième lettre : ";
                cin >> nameCase2;
                
            } while (nameCase2.size() != 1);
            do
            {
                cout << "Veuillez choisir une troisième lettre : ";
                cin >> nameCase3;
                
            } while (nameCase3.size() != 1);
            transform(nameCase1.begin(), nameCase1.end(), nameCase1.begin(), ::toupper);
            transform(nameCase2.begin(), nameCase2.end(), nameCase2.begin(), ::toupper);
            transform(nameCase3.begin(), nameCase3.end(), nameCase3.begin(), ::toupper);
            tabcoordinates.push_back(nameCase1);
            tabcoordinates.push_back(nameCase2);
            tabcoordinates.push_back(nameCase3);
        } 
    }
    else
    {
        cout << "Vous n'avez pas assez de ressource pour construire une colonie, Voulez vous faire autre chose ?" << endl;;
    }

    return tabcoordinates;
}

int main()
{
    srand(time(NULL));
    int nbPlayers = startGame();
    Jeu j(nbPlayers);
    // Map m;
    // vector<Player> players = startGame();
    // for(int i=0; i<players.size(); i++)
    // {
    //     players[i].startTurn(players[i], m.getCases());
    //     vector<string> tabcoordinates = buildColony(players[i].returnRessources());
    //     if(tabcoordinates.size() == 3)
    //     {
    //         players[i].placementColony(m.getCase(tabcoordinates[0][0]), m.getCase(tabcoordinates[1][0]), m.getCase(tabcoordinates[2][0]));
    //     }
        
    // }
    // // m.getCase('$').getCoordinate();
    // Player p("tigi", "blue");
    // // p.getRessource("bois");
    // p.setRessource("bois", "add");
    // p.setRessource("argile", "add");
    // //p.setRessource("blé", "add");
    // // p.getRessources();
    // // p.nbRessourceDispo();
    // // p.rollingDice();
    // p.startTurn(m.getCases(), m.getlistId());
    // p.getTabRoad();

    // // p.winRessources(m.getCases());
    // // p.getRessources();
    return 0; 
}


