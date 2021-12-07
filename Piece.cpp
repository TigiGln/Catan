#include "Piece.hpp"

#include <string>
using namespace std;

Piece::Piece(string color):m_color(color)
{}

Piece::~Piece(){}

string Piece::getcolor()
{
    return m_color;
}

vector<string> Piece::getCoordinates()
{
    return m_coordinatesCases;
}

