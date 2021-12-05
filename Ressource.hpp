#ifndef DEF_RESSOURCE
#define DEF_RESSOURCE

#include <string>

class Ressource
{
    //Attributs
    private:
        std::string m_type;//type de ressource

    //Méthodes
    public:
        Ressource();//Constructeur
        ~Ressource();//Destructeur
        void setType();//Affectation de type de ressource aléatoirement
        void setType(std::string ressource);//Affectation ciblé de ressource
        std::string getType();//Récupération du type de ressource

};

#endif