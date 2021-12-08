#ifndef DEF_PIECE
#define DEF_PIECE

#include <string>
#include <vector>

class Piece
{
    protected:
        std::string m_color;
        std::vector<char> m_coordinates;
        
    public:
        Piece();
        Piece(std::string color);
        ~Piece();
        std::string getcolor();
        std::vector<char> getCoordinates();
        
        
};

#endif