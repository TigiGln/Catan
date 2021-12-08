#include "Piece.hpp"

#include <string>
using namespace std;

Piece::Piece(){}

Piece::Piece(string color):m_color(color)
{}

Piece::~Piece(){}

string Piece::getcolor()
{
    return m_color;
}

vector<char> Piece::getCoordinates()
{
    return m_coordinates;
}

