#ifndef DEF_SETTLEMENT
#define DEF_SETTLEMENT

#include "Piece.hpp"
#include <vector>



class Settlement: public Piece
{
    public:
        Settlement(std::vector<char>);
        
};

#endif