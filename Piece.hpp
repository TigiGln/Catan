#ifndef DEF_PIECE
#define DEF_PIECE

#include <string>
#include <vector>

class Piece
{
    protected:
        std::vector<char> m_coordinates;
        
    public:
        Piece(std::vector<char> casesCoordinate);
        ~Piece();
        void getCoordinates();

        
        
};

#endif