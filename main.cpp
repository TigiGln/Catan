#include <iostream>
#include <time.h>


using namespace std;

#include "Map.hpp"
#include "Case.hpp"
#include "Player.hpp"

void startGame()
{
    int nbJoueurs;
    cout << "***************************************************************************" << "\n";
    cout << "***************************************************************************" << "\n";
    cout << "***************************************************************************" << "\n";
    cout << "************************  COLON DE CATANE  ********************************" << "\n";
    cout << "***************************************************************************" << "\n";
    cout << "***************************************************************************" << "\n";
    cout << "***************************************************************************" << "\n";
    cout << endl;
    while(nbJoueurs == 0 || nbJoueurs < 2 || nbJoueurs > 6)
    {
        cout << "Combien de joueur serez vous ? (2-6)" << "\n";
        cin >> nbJoueurs;
    }
    int joueur;
    while(joueur < nbJoueurs)
    {
        joueur++;
        cout << "Joueur N°" << joueur  << endl;
        
    }
    
}

int main()
{
    //startGame();
    srand(time(NULL));
    Map m;
    Player p("tigi", "blue");
    // p.getRessource("bois");
    p.setRessource("bois", "add");
    p.setRessource("argile", "add");
    //p.setRessource("blé", "add");
    // p.getRessources();
    // p.nbRessourceDispo();
    // p.rollingDice();
    p.startTurn(m.getCases(), m.getlistId());
    // p.winRessources(m.getCases());
    // p.getRessources();
    return 0; 
}


