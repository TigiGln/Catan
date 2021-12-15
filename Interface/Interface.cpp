#include "Interface.hpp"


#include <string>
using namespace std;


Interface::Interface()
{
    this->set_title("Colon de Catane");
    this->set_size_request(300, 300);
    this->set_border_width(10);

    this->add(m_frame);
    

    m_frame.set_label("Frame");

    imagefond.set("../pictures/FOND1.png");

    button.add_label("Nouvelle Partie");//Ajout du label au bouton
    button.signal_clicked().connect(sigc::mem_fun(*this, &Interface::newGame));
    
    mainGrid.attach(button, 0, 0, 1, 1);
    mainGrid.attach(label, 0, 1, 1, 1);
    mainGrid.attach(imagefond, 1, 0, 100, 100);

    m_frame.add(mainGrid);
    mainGrid.show_all();
   
    // Display the main grid in the main window
    this->show_all_children();
}
Interface::~Interface(){}

void Interface::newGame()
{
    imagefond.set("../pictures/FOND_Map.png");
    button.set_label("Lancer les dés");
    button.signal_clicked().connect(sigc::mem_fun(*this, &Interface::rollingDice));
}
void Interface::rollingDice()
{
    
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int sumDice = dice1 + dice2;
    label.set_label(to_string(sumDice));
    
}


