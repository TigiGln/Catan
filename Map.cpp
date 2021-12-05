#include "Map.hpp"
#include "Case.hpp"

#include <iostream>
#include <vector>
using namespace std;



Map::Map()
{
    int nb_cases;
    m_matrix = new char* [11];
    for(nb_cases = 0; nb_cases<11; nb_cases++)
    {
        m_matrix[nb_cases] = new char[7];
    }
    setmatrix();
    getmatrix();
    setCases();
    setRCases();
    getCases();
    
}

Map::~Map()
{
    if(m_matrix != NULL)
    {
        delete[] m_matrix;
        cout << "La matrice à été détruite !!" << endl;
    }
    
}

void Map::getmatrix()
{
    cout << "X " << " 0 1 2 3 4 5 6" << endl;
    for(int line=0; line<11; line++)
    {
        
        if(line == 10)
        {
            cout << "10:";
        }
        else
        {
            cout << line << ": ";
        }
        for(int column=0; column<7; column++)
        {
            cout << m_matrix[line][column] << " ";
            if(m_matrix[line][column] != ' ') 
            {
                m_listId.push_back(m_matrix[line][column]);
            } 
        }
        cout << endl;
    }
    cout << endl;
}

char Map::getElemMatrix(int line, int column)
{
   return m_matrix[line][column];
}

void Map::setCases()
{
    for(int letter=0; letter<m_listId.size(); letter++)
    {
        Case c(m_listId[letter]);
        m_listCases.push_back(c);
    }
}
void Map::setRCases()
{
    for(int nameCase=0; nameCase<m_listCases.size(); nameCase++)
    {
        if(m_listCases[nameCase].getId() == 'A' || m_listCases[nameCase].getId() == 'G' || m_listCases[nameCase].getId() == 'M' || m_listCases[nameCase].getId() == 'R' || m_listCases[nameCase].getId() == 'S')
        {
            m_listCases[nameCase].setR("argile");
        }
        else if(m_listCases[nameCase].getId() == 'B' || m_listCases[nameCase].getId() == 'I' || m_listCases[nameCase].getId() == 'U' || m_listCases[nameCase].getId() == 'V' || m_listCases[nameCase].getId() == '&')
        {
            m_listCases[nameCase].setR("minerai");
        }
        else if(m_listCases[nameCase].getId() == 'C' || m_listCases[nameCase].getId() == 'D' || m_listCases[nameCase].getId() == 'O' || m_listCases[nameCase].getId() == 'W' || m_listCases[nameCase].getId() == 'X' || m_listCases[nameCase].getId() == 'Y')
        {
            m_listCases[nameCase].setR("laine");
        }
        else if(m_listCases[nameCase].getId() == 'E' || m_listCases[nameCase].getId() == 'H' || m_listCases[nameCase].getId() == 'N' || m_listCases[nameCase].getId() == 'J' || m_listCases[nameCase].getId() == 'T'|| m_listCases[nameCase].getId() == '@')
        {
            m_listCases[nameCase].setR("blé");
        }
        else if(m_listCases[nameCase].getId() == 'F' || m_listCases[nameCase].getId() == 'L' || m_listCases[nameCase].getId() == 'K' || m_listCases[nameCase].getId() == 'Q' || m_listCases[nameCase].getId() == '#' || m_listCases[nameCase].getId() == '$')
        {
            m_listCases[nameCase].setR("bois");
        }
        else if(m_listCases[nameCase].getId() == 'P' || m_listCases[nameCase].getId() == 'Z')
        {
            m_listCases[nameCase].setR("désert");
        }
    }
} 

vector<Case> Map::getCases()
{
    cout << "getCases" << "\n";
    for(int i=0; i<m_listCases.size(); i++)
    {
        cout << "Case N° " << i << "\n";
        cout << m_listCases[i].getId() << "\n";
        cout << m_listCases[i].getNum() << "\n";
        cout << m_listCases[i].getR() << "\n";
        //cout << m_listCases[i].getTabPosition() << "\n";
    }
    return m_listCases;
}

void Map::setmatrix()
{
    for(int line=0; line<11; line++)
    {
        for(int column=0; column<7; column++)
        {
           if(line == 0 && column == 3)
            {
                m_matrix[line][column] = 'A';
            }
            else if(line == 1 && column == 2)
            {
                m_matrix[line][column] = 'B';
            }
            else if(line == 1 && column == 4)
            {
                m_matrix[line][column] = 'C';
            }
            else if(line == 2 && column == 1)
            {
                m_matrix[line][column] = 'D';
            }
            else if(line == 2 && column == 3)
            {
                m_matrix[line][column] = 'E';
            }
            else if(line == 2 && column == 5)
            {
                m_matrix[line][column] = 'F';
            }
            else if(line == 3 && column == 0)
            {
                m_matrix[line][column] = 'G';
            }
            else if(line == 3 && column == 2)
            {
                m_matrix[line][column] = 'H';
            }
            else if(line == 3 && column == 4)
            {
                m_matrix[line][column] = 'I';
            }
            else if(line == 3 && column == 6)
            {
                m_matrix[line][column] = 'J';
            }
            else if(line == 4 && column == 1)
            {
                m_matrix[line][column] = 'K';
            }
            else if(line == 4 && column == 3)
            {
                m_matrix[line][column] = 'L';
            }
            else if(line == 4 && column == 5)
            {
                m_matrix[line][column] = 'M';
            }
            else if(line == 5 && column == 0)
            {
                m_matrix[line][column] = 'N';
            }
            else if(line == 5 && column == 2)
            {
                m_matrix[line][column] = 'O';
            }
            else if(line == 5 && column == 4)
            {
                m_matrix[line][column] = 'P';
            }
            else if(line == 5 && column == 6)
            {
                m_matrix[line][column] = 'Q';
            }
            else if(line == 6 && column == 1)
            {
                m_matrix[line][column] = 'R';
            }
            else if(line == 6 && column == 3)
            {
                m_matrix[line][column] = 'S';
            }
            else if(line == 6 && column == 5)
            {
                m_matrix[line][column] = 'T';
            }
            else if(line == 7 && column == 0)
            {
                m_matrix[line][column] = 'U';
            }
            else if(line == 7 && column == 2)
            {
                m_matrix[line][column] = 'V';
            }
            else if(line == 7 && column == 4)
            {
                m_matrix[line][column] = 'W';
            }
            else if(line == 7 && column == 6)
            {
                m_matrix[line][column] = 'X';
            }
            else if(line == 8 && column == 1)
            {
                m_matrix[line][column] = 'Y';
            }
            else if(line == 8 && column == 3)
            {
                m_matrix[line][column] = 'Z';
            }
            else if(line == 8 && column == 5)
            {
                m_matrix[line][column] = '&';
            }
            else if(line == 9 && column == 2)
            {
                m_matrix[line][column] = '#';
            }
            else if(line == 9 && column == 4)
            {
                m_matrix[line][column] = '@';
            }
            else if(line == 10 && column == 3)
            {
                m_matrix[line][column] = '$';
            }
            else
            {
                m_matrix[line][column] = ' ';
            }
        }
    }
    cout << "La matrice à bien été créée !!" << endl;
}


