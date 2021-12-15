#ifndef DEF_WINDOW
#define DEF_WINDOW

#include <gtkmm.h>
#include <iostream>

class Interface : public Gtk::Window
{
    public:
        Interface();
        virtual ~Interface();
        void newGame();
        void rollingDice();

    private:
        Gtk::Frame m_frame;//création du frame
        Gtk::Button button; //Déclaration du bouton
        Gtk::Image imagefond;//Création de l'objet image
        Gtk::Grid  mainGrid;//Création de la grille de positionnement
        Gtk::Label label; //Création du label
};

#endif