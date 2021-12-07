#ifndef DEF_PIECE
#define DEF_PIECE

#include <string>
#include <vector>

class Piece
{
    protected:
        std::string m_color;
        std::vector<std::string> m_coordinatesCases;
        
    public:
        Piece(std::string color);
        ~Piece();
        std::string getcolor();
        std::vector<std::string> getCoordinates();
        
        
};

#endif