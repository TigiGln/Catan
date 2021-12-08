#include "Road.hpp"

#include <iostream>
using namespace std;


Road::Road(char Case1, char Case2)
{
    m_coordinates = {{Case1, Case2}};
}

Road::~Road(){}

void Road::setCoordinates(char tabCases[2])
{
    cout << "Avant avant";
    for(int coordinates = 0; coordinates<2; coordinates++)
    {
        cout << "Avant";
        m_coordinates[coordinates] = tabCases[coordinates];
        cout << "Apres";
    }
}