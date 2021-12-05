#include "Ressource.hpp"

#include <string>
#include <iostream>


using namespace std;

Ressource::Ressource()
{

}
Ressource::~Ressource(){}

void Ressource::setType()
{
    string tabRessource[6] = {"bois", "laine", "minerai", "argile", "blé", "désert"};
    int indexRandom = rand() % 6;
    m_type = tabRessource[indexRandom];
}
void Ressource::setType(std::string ressource)
{
    m_type = ressource;
}

string Ressource::getType()
{
    return m_type;
}