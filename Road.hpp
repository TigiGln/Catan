#ifndef DEF_ROAD
#define DEF_ROAD

#include "Piece.hpp"

class Road:public Piece
{
    private:

    public:
        Road(char, char);
        ~Road();
        void setCoordinates(char tabCases[2]);
};

#endif