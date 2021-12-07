#include "Settlement.hpp"

#include <string>
using namespace std;

void Settlement::setCoordinates(char tabCases[3])
{
    for(int coordinates = 0; coordinates<3; coordinates++)
    {
        m_coordinatesCases[coordinates] = tabCases[coordinates];
    }
}

