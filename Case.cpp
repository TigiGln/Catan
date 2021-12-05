#include "Case.hpp"
#include "Ressource.hpp"

#include <iostream>
#include <string>
using namespace std;


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
