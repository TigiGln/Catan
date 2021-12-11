#include "Settlement.hpp"
#include "Piece.hpp"

#include <string>
#include <vector>
#include <stdarg.h>
#include <iostream>
using namespace std;

Settlement::Settlement(vector<char> casesCoordinate):Piece(casesCoordinate)
{
    cout << "Voici les coordonnées de votre colonie: ";
    getCoordinates();
}




