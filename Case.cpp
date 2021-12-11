#include "Case.hpp"
#include "Ressource.hpp"

#include <iostream>
#include <string>
using namespace std;


Case::Case(){}
Case::Case(char id)
{
    setId(id);
    for(int i = 0; i<6; i++)
    {
        m_tabPosition[i] = true;
    }
    int jetons[30] = {2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 11, 11, 12};
    int num = rand() % 30;
    m_num = jetons[num];
    // getId();
    // getNum();
    // getTabPosition();
}

Case::~Case(){}

char Case::getId()
{
    return m_id;
}

int Case::getNum()
{
    return m_num;
}

bool Case::getTabPosition()
{
    for(int position=0; position<6; position++)
    {
        if(m_tabPosition[position] == 1)
        {
            cout << "True" << " ";
        }
        else
        {
            cout << "False" << " ";
        }
    }
    cout << "\n";
    return m_tabPosition;
} 

void Case::setTabPosition(int pos)
{
    for(int position=0; position<6; position++)
    {
        if(position == pos)
        {
            m_tabPosition[position] = false;
            if(position > 0)
            {
                m_tabPosition[position - 1] = false;
            }
            if(position < 5)
            {
                m_tabPosition[position + 1] = false;
            }
            
        }
    }
}

void Case::setId(char id)
{
    m_id = id;
}
string Case::getR()
{
    return m_r.getType();
}

string Case::setRJoueur(int dice)
{
    if(m_num == dice)
    {
        return m_r.getType();
    }
    else
    {
        return "No";
    }
}

void Case::setR(string ressource)
{
    m_r.setType(ressource);
}

void Case::setNeighbours(char idCase)
{
    m_neighbours.push_back(idCase);
}

vector<char> Case::getNeighbours()
{
    return m_neighbours;
}

bool Case::getNeighbour(char idNeighbour)
{
    bool test = false;
    for(int i=0; i<m_neighbours.size(); i++)
    {
        if(m_neighbours[i] == idNeighbour)
        {
            test = true;
        }
    }
    return test;
}


void Case::getNeighbour()
{
    cout << "[";
    for(int i=0; i<m_neighbours.size(); i++)
    {
        if(i<m_neighbours.size()-1)
        {
            cout << m_neighbours[i] << ", ";
        }
        else
        {
            cout << m_neighbours[i];
        }
        
    }
    cout << "]" << endl;
}


void Case::setCoordinate(int line, int column)
{
    m_dictCoordinates.insert(make_pair("line", line));
    m_dictCoordinates.insert(make_pair("column", column));
}

void Case::getCoordinate()
{
    cout << "line: " << m_dictCoordinates["line"] << " column: " << m_dictCoordinates["column"] << endl;
}

void Case::setPositionRoadDispo(char idVoisin, bool possible)
{
    m_dictPositionDispo.insert(make_pair(idVoisin, possible));
}
void Case::getPositionRoadDispo(char idVoisin)
{
    cout << m_dictPositionDispo[idVoisin];
}

void Case::setPositionColonyDispo(string combinaison, bool possible)
{
    m_positionDispoColony.insert(make_pair(combinaison, possible));
}

void Case::getPositionColonyDispo(string combinaison)
{
    cout << m_positionDispoColony[combinaison];
}


