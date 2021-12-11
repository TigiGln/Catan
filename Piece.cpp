#include "Piece.hpp"

#include <iostream>
#include <string>
#include <stdarg.h>
using namespace std;

Piece::Piece(vector<char> casesCoordinate)
{
    
    for(int Case=0; Case<casesCoordinate.size(); Case++)
    {
        m_coordinates.push_back(casesCoordinate[Case]);
    }
}

Piece::~Piece(){}


void Piece::getCoordinates()
{
    cout << "[";
    for(int index=0; index<m_coordinates.size(); index++)
    {
        if(index < m_coordinates.size()-1)
        {
            cout << m_coordinates[index] << ", ";
        }
        else
        {
            cout << m_coordinates[index];
        }
        
    }
    cout << "]" << endl;
}


