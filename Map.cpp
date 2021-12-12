#include "Map.hpp"
#include "Case.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
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
    setlistId();
    setCases();
    setRCases();
    setNeighbours();
    setCoordinateCase();
    setDictPositionVoisionDispo();
    setMapPositionColonyDispo();
    getmatrix();
    
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
        }
        cout << endl;
    }
    cout << endl;
}

void Map::setlistId()
{
    for(int line=0; line<11; line++)
    {
        for(int column=0; column<7; column++)
        {
            if(m_matrix[line][column] != ' ') 
            {
                m_listId.push_back(m_matrix[line][column]);
            } 
        }
    }
}

vector<char> Map::getlistId()
{
    return m_listId;
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
    return m_listCases;
}

Case Map::getCase(char id)
{
    Case *c;
    for(int index=0; index<m_listCases.size(); index++)
    {
        if(m_listCases[index].getId() == id)
        {
            c = &m_listCases[index];
        }
    }
    return *c;
}

vector<int> Map::getCoordinateCase(char id)
{
    vector<int> listcoordinate;
    for(int line=0; line<11; line++)
    {
        for(int column=0; column<7; column++)
        {
            if(m_matrix[line][column] == id)
            {
                listcoordinate.push_back(line);
                listcoordinate.push_back(column);
            }
        }
    }
    return listcoordinate;
}

void Map::setCoordinateCase()
{
    for(int index=0; index<m_listCases.size(); index++)
    {
       vector<int> listcoordinate = getCoordinateCase(m_listCases[index].getId());
       m_listCases[index].setCoordinate(listcoordinate[0], listcoordinate[1]);
    }
}

char Map::intersectNeighbours(char namecase1, char namecase2)
{
    char idCase;
    vector<char> vectornamecase1 = getCase(namecase1).getNeighbours();
    vector<char> vectornamecase2 = getCase(namecase2).getNeighbours();
    vector<char> intersectvector;
    sort(vectornamecase1.begin(), vectornamecase1.end());
    sort(vectornamecase2.begin(), vectornamecase2.end());

    set_intersection(vectornamecase1.begin(), vectornamecase1.end(),\
    vectornamecase2.begin(), vectornamecase2.end(), back_inserter(intersectvector));
    cout << "[";
    for(int i=0; i< intersectvector.size(); i++)
    {
        if(i < intersectvector.size()-1)
        {
            cout << intersectvector[i] << ", ";
        }
        else
        {
            cout << intersectvector[i];
        }
        
        idCase = intersectvector[i];
    }

    cout << "]";

    return idCase;
}

void Map::setDictPositionVoisionDispo()
{
    for(int indexCase=0; indexCase < m_listCases.size(); indexCase++)
    {
        vector<char> neighbours = m_listCases[indexCase].getNeighbours();
        for(int index=0; index<neighbours.size(); index++)
        {
            m_listCases[indexCase].setPositionRoadDispo(neighbours[index], true);
        }
    }
}
// void Map::setMapPositionColonyDispo()
// {
//     for(int i=0; i<m_listCases.size(); i++)
//     {
//         for(int position=0; position<6; ++position)
//         {
//             m_listCases[i].setPositionColonyDispo(m_listCases[i].getId() + to_string(position), true, "add");
//         }
//     }
// }

void Map::updateMapPositionColonyDispo(char nameCase, string positionCase, bool possible)
{
    for(int i=0; i<m_listCases.size(); i++)
    {
        if(m_listCases[i].getId() == nameCase)
        {
            m_listCases[i].setPositionColonyDispo(positionCase, possible, "update");
        }
    }
}

void Map::getMapPositionColonyDispo(char nameCase, string positionCase)
{
    for(int i=0; i<m_listCases.size(); i++)
    {
        if(m_listCases[i].getId() == nameCase)
        {
            m_listCases[i].getPositionColonyDispo(positionCase);
        }
    }
}

void Map::setMapPositionColonyDispo()
{
    for(int i=0; i<m_listCases.size(); i++)
    {
        if(m_listCases[i].getId() == 'A')
        {
            m_listCases[i].setPositionColonyDispo("A1", true, "add");
            m_listCases[i].setPositionColonyDispo("A2", true, "add");
            m_listCases[i].setPositionColonyDispo("AC", true, "add");
            m_listCases[i].setPositionColonyDispo("ACE", true, "add");
            m_listCases[i].setPositionColonyDispo("ABE", true, "add");
            m_listCases[i].setPositionColonyDispo("AB", true, "add");
        }
        else if(m_listCases[i].getId() == 'B')
        {
            m_listCases[i].setPositionColonyDispo("B", true, "add");
            m_listCases[i].setPositionColonyDispo("BA", true, "add");
            m_listCases[i].setPositionColonyDispo("BAE", true, "add");
            m_listCases[i].setPositionColonyDispo("BEH", true, "add");
            m_listCases[i].setPositionColonyDispo("BDH", true, "add");
            m_listCases[i].setPositionColonyDispo("BD", true, "add");
        }
        else if(m_listCases[i].getId() == 'C')
        {
            m_listCases[i].setPositionColonyDispo("CA", true, "add");
            m_listCases[i].setPositionColonyDispo("C", true, "add");
            m_listCases[i].setPositionColonyDispo("CF", true, "add");
            m_listCases[i].setPositionColonyDispo("CFI", true, "add");
            m_listCases[i].setPositionColonyDispo("CEI", true, "add");
            m_listCases[i].setPositionColonyDispo("CEA", true, "add");
        }
        else if(m_listCases[i].getId() == 'D')
        {
            m_listCases[i].setPositionColonyDispo("D", true, "add");
            m_listCases[i].setPositionColonyDispo("DB", true, "add");
            m_listCases[i].setPositionColonyDispo("DBH", true, "add");
            m_listCases[i].setPositionColonyDispo("DHK", true, "add");
            m_listCases[i].setPositionColonyDispo("DGK", true, "add");
            m_listCases[i].setPositionColonyDispo("DG", true, "add");
        }
        else if(m_listCases[i].getId() == 'E')
        {
            m_listCases[i].setPositionColonyDispo("EAB", true, "add");
            m_listCases[i].setPositionColonyDispo("EAC", true, "add");
            m_listCases[i].setPositionColonyDispo("ECI", true, "add");
            m_listCases[i].setPositionColonyDispo("EIL", true, "add");
            m_listCases[i].setPositionColonyDispo("EHL", true, "add");
            m_listCases[i].setPositionColonyDispo("EBH", true, "add");
        }
        else if(m_listCases[i].getId() == 'F')
        {
            m_listCases[i].setPositionColonyDispo("FC", true, "add");
            m_listCases[i].setPositionColonyDispo("F", true, "add");
            m_listCases[i].setPositionColonyDispo("FJ", true, "add");
            m_listCases[i].setPositionColonyDispo("FJM", true, "add");
            m_listCases[i].setPositionColonyDispo("FIM", true, "add");
            m_listCases[i].setPositionColonyDispo("FCI", true, "add");
        }
        else if(m_listCases[i].getId() == 'G')
        {
            m_listCases[i].setPositionColonyDispo("G1", true, "add");
            m_listCases[i].setPositionColonyDispo("GD", true, "add");
            m_listCases[i].setPositionColonyDispo("GDK", true, "add");
            m_listCases[i].setPositionColonyDispo("GKN", true, "add");
            m_listCases[i].setPositionColonyDispo("GN", true, "add");
            m_listCases[i].setPositionColonyDispo("G2", true, "add");
        }
        else if(m_listCases[i].getId() == 'H')
        {
            m_listCases[i].setPositionColonyDispo("HBD", true, "add");
            m_listCases[i].setPositionColonyDispo("HBE", true, "add");
            m_listCases[i].setPositionColonyDispo("HEL", true, "add");
            m_listCases[i].setPositionColonyDispo("HLO", true, "add");
            m_listCases[i].setPositionColonyDispo("HKO", true, "add");
            m_listCases[i].setPositionColonyDispo("HDK", true, "add");
        }
        else if(m_listCases[i].getId() == 'I')
        {
            m_listCases[i].setPositionColonyDispo("ICE", true, "add");
            m_listCases[i].setPositionColonyDispo("ICF", true, "add");
            m_listCases[i].setPositionColonyDispo("IFM", true, "add");
            m_listCases[i].setPositionColonyDispo("IMP", true, "add");
            m_listCases[i].setPositionColonyDispo("ILP", true, "add");
            m_listCases[i].setPositionColonyDispo("IEL", true, "add");
        }
        else if(m_listCases[i].getId() == 'J')
        {
            m_listCases[i].setPositionColonyDispo("JF", true, "add");
            m_listCases[i].setPositionColonyDispo("J1", true, "add");
            m_listCases[i].setPositionColonyDispo("J2", true, "add");
            m_listCases[i].setPositionColonyDispo("JQ", true, "add");
            m_listCases[i].setPositionColonyDispo("JQM", true, "add");
            m_listCases[i].setPositionColonyDispo("JFM", true, "add");
        }
        else if(m_listCases[i].getId() == 'K')
        {
            m_listCases[i].setPositionColonyDispo("KDG", true, "add");
            m_listCases[i].setPositionColonyDispo("KDH", true, "add");
            m_listCases[i].setPositionColonyDispo("KHO", true, "add");
            m_listCases[i].setPositionColonyDispo("KOR", true, "add");
            m_listCases[i].setPositionColonyDispo("KNR", true, "add");
            m_listCases[i].setPositionColonyDispo("KNG", true, "add");
        }
        else if(m_listCases[i].getId() == 'L')
        {
            m_listCases[i].setPositionColonyDispo("LEH", true, "add");
            m_listCases[i].setPositionColonyDispo("LEI", true, "add");
            m_listCases[i].setPositionColonyDispo("LIP", true, "add");
            m_listCases[i].setPositionColonyDispo("LPS", true, "add");
            m_listCases[i].setPositionColonyDispo("LOS", true, "add");
            m_listCases[i].setPositionColonyDispo("LHO", true, "add");
        }
        else if(m_listCases[i].getId() == 'M')
        {
            m_listCases[i].setPositionColonyDispo("MFI", true, "add");
            m_listCases[i].setPositionColonyDispo("MFJ", true, "add");
            m_listCases[i].setPositionColonyDispo("MJQ", true, "add");
            m_listCases[i].setPositionColonyDispo("MQT", true, "add");
            m_listCases[i].setPositionColonyDispo("MPT", true, "add");
            m_listCases[i].setPositionColonyDispo("MIP", true, "add");
        }
        else if(m_listCases[i].getId() == 'N')
        {
            m_listCases[i].setPositionColonyDispo("NG", true, "add");
            m_listCases[i].setPositionColonyDispo("NGK", true, "add");
            m_listCases[i].setPositionColonyDispo("NKR", true, "add");
            m_listCases[i].setPositionColonyDispo("NRU", true, "add");
            m_listCases[i].setPositionColonyDispo("NU", true, "add");
            m_listCases[i].setPositionColonyDispo("N", true, "add");
        }
        else if(m_listCases[i].getId() == 'O')
        {
            m_listCases[i].setPositionColonyDispo("OHK", true, "add");
            m_listCases[i].setPositionColonyDispo("OHL", true, "add");
            m_listCases[i].setPositionColonyDispo("OLS", true, "add");
            m_listCases[i].setPositionColonyDispo("OSV", true, "add");
            m_listCases[i].setPositionColonyDispo("ORV", true, "add");
            m_listCases[i].setPositionColonyDispo("OKR", true, "add");
        }
        else if(m_listCases[i].getId() == 'P')
        {
            m_listCases[i].setPositionColonyDispo("PIL", true, "add");
            m_listCases[i].setPositionColonyDispo("PIM", true, "add");
            m_listCases[i].setPositionColonyDispo("PMT", true, "add");
            m_listCases[i].setPositionColonyDispo("PTW", true, "add");
            m_listCases[i].setPositionColonyDispo("PSW", true, "add");
            m_listCases[i].setPositionColonyDispo("PLS", true, "add");
        }
        else if(m_listCases[i].getId() == 'Q')
        {
            m_listCases[i].setPositionColonyDispo("QJM", true, "add");
            m_listCases[i].setPositionColonyDispo("QJ", true, "add");
            m_listCases[i].setPositionColonyDispo("Q", true, "add");
            m_listCases[i].setPositionColonyDispo("QX", true, "add");
            m_listCases[i].setPositionColonyDispo("QTX", true, "add");
            m_listCases[i].setPositionColonyDispo("QMT", true, "add");
        }
        else if(m_listCases[i].getId() == 'R')
        {
            m_listCases[i].setPositionColonyDispo("RKN", true, "add");
            m_listCases[i].setPositionColonyDispo("RKO", true, "add");
            m_listCases[i].setPositionColonyDispo("ROV", true, "add");
            m_listCases[i].setPositionColonyDispo("RVY", true, "add");
            m_listCases[i].setPositionColonyDispo("RUY", true, "add");
            m_listCases[i].setPositionColonyDispo("RNU", true, "add");
        }
        else if(m_listCases[i].getId() == 'S')
        {
            m_listCases[i].setPositionColonyDispo("SLO", true, "add");
            m_listCases[i].setPositionColonyDispo("SLP", true, "add");
            m_listCases[i].setPositionColonyDispo("SPW", true, "add");
            m_listCases[i].setPositionColonyDispo("SWZ", true, "add");
            m_listCases[i].setPositionColonyDispo("SVZ", true, "add");
            m_listCases[i].setPositionColonyDispo("SOV", true, "add");
        }
        else if(m_listCases[i].getId() == 'T')
        {
            m_listCases[i].setPositionColonyDispo("TMP", true, "add");
            m_listCases[i].setPositionColonyDispo("TMQ", true, "add");
            m_listCases[i].setPositionColonyDispo("TQX", true, "add");
            m_listCases[i].setPositionColonyDispo("TX&", true, "add");
            m_listCases[i].setPositionColonyDispo("TW&", true, "add");
            m_listCases[i].setPositionColonyDispo("TPW", true, "add");
        }
        else if(m_listCases[i].getId() == 'U')
        {
            m_listCases[i].setPositionColonyDispo("UN", true, "add");
            m_listCases[i].setPositionColonyDispo("UNR", true, "add");
            m_listCases[i].setPositionColonyDispo("URY", true, "add");
            m_listCases[i].setPositionColonyDispo("UY", true, "add");
            m_listCases[i].setPositionColonyDispo("U1", true, "add");
            m_listCases[i].setPositionColonyDispo("U2", true, "add");
        }
        else if(m_listCases[i].getId() == 'V')
        {
            m_listCases[i].setPositionColonyDispo("VOR", true, "add");
            m_listCases[i].setPositionColonyDispo("VOS", true, "add");
            m_listCases[i].setPositionColonyDispo("VSZ", true, "add");
            m_listCases[i].setPositionColonyDispo("VZ#", true, "add");
            m_listCases[i].setPositionColonyDispo("VY#", true, "add");
            m_listCases[i].setPositionColonyDispo("VRY", true, "add");
        }
        else if(m_listCases[i].getId() == 'W')
        {
            m_listCases[i].setPositionColonyDispo("WPS", true, "add");
            m_listCases[i].setPositionColonyDispo("WPT", true, "add");
            m_listCases[i].setPositionColonyDispo("WT&", true, "add");
            m_listCases[i].setPositionColonyDispo("W&@", true, "add");
            m_listCases[i].setPositionColonyDispo("WZ@", true, "add");
            m_listCases[i].setPositionColonyDispo("WSZ", true, "add");
        }
        else if(m_listCases[i].getId() == 'X')
        {
            m_listCases[i].setPositionColonyDispo("XQT", true, "add");
            m_listCases[i].setPositionColonyDispo("XQ", true, "add");
            m_listCases[i].setPositionColonyDispo("X1", true, "add");
            m_listCases[i].setPositionColonyDispo("X2", true, "add");
            m_listCases[i].setPositionColonyDispo("X&", true, "add");
            m_listCases[i].setPositionColonyDispo("XT&", true, "add");
        }
        else if(m_listCases[i].getId() == 'Y')
        {
            m_listCases[i].setPositionColonyDispo("YRU", true, "add");
            m_listCases[i].setPositionColonyDispo("YRV", true, "add");
            m_listCases[i].setPositionColonyDispo("YV#", true, "add");
            m_listCases[i].setPositionColonyDispo("Y#", true, "add");
            m_listCases[i].setPositionColonyDispo("Y", true, "add");
            m_listCases[i].setPositionColonyDispo("YU", true, "add");
        }
        else if(m_listCases[i].getId() == 'Z')
        {
            m_listCases[i].setPositionColonyDispo("ZSV", true, "add");
            m_listCases[i].setPositionColonyDispo("ZSW", true, "add");
            m_listCases[i].setPositionColonyDispo("ZW@", true, "add");
            m_listCases[i].setPositionColonyDispo("Z@$", true, "add");
            m_listCases[i].setPositionColonyDispo("Z#$", true, "add");
            m_listCases[i].setPositionColonyDispo("ZV#", true, "add");
        }
        else if(m_listCases[i].getId() == '&')
        {
            m_listCases[i].setPositionColonyDispo("&TW", true, "add");
            m_listCases[i].setPositionColonyDispo("&TX", true, "add");
            m_listCases[i].setPositionColonyDispo("&X", true, "add");
            m_listCases[i].setPositionColonyDispo("&", true, "add");
            m_listCases[i].setPositionColonyDispo("&@", true, "add");
            m_listCases[i].setPositionColonyDispo("&W@", true, "add");
        }
        else if(m_listCases[i].getId() == '#')
        {
            m_listCases[i].setPositionColonyDispo("#VY", true, "add");
            m_listCases[i].setPositionColonyDispo("#VZ", true, "add");
            m_listCases[i].setPositionColonyDispo("#Z$", true, "add");
            m_listCases[i].setPositionColonyDispo("#$", true, "add");
            m_listCases[i].setPositionColonyDispo("#", true, "add");
            m_listCases[i].setPositionColonyDispo("#Y", true, "add");
        }
        else if(m_listCases[i].getId() == '@')
        {
            m_listCases[i].setPositionColonyDispo("@WZ", true, "add");
            m_listCases[i].setPositionColonyDispo("@W&", true, "add");
            m_listCases[i].setPositionColonyDispo("@&", true, "add");
            m_listCases[i].setPositionColonyDispo("@", true, "add");
            m_listCases[i].setPositionColonyDispo("@$", true, "add");
            m_listCases[i].setPositionColonyDispo("@Z$", true, "add");
        }
        else if(m_listCases[i].getId() == '$')
        {
            m_listCases[i].setPositionColonyDispo("$Z#", true, "add");
            m_listCases[i].setPositionColonyDispo("$Z@", true, "add");
            m_listCases[i].setPositionColonyDispo("$@", true, "add");
            m_listCases[i].setPositionColonyDispo("$1", true, "add");
            m_listCases[i].setPositionColonyDispo("$2", true, "add");
            m_listCases[i].setPositionColonyDispo("$#", true, "add");
        }
    }
}

void Map::setNeighbours()
{
    for(int indexCase=0; indexCase < m_listCases.size(); indexCase++)
    {
        if(m_listCases[indexCase].getId() == 'A')
        {
            m_listCases[indexCase].setNeighbours('B');
            m_listCases[indexCase].setNeighbours('C');
            m_listCases[indexCase].setNeighbours('E');
        }
        else if(m_listCases[indexCase].getId() == 'B')
        {
            m_listCases[indexCase].setNeighbours('A');
            m_listCases[indexCase].setNeighbours('D');
            m_listCases[indexCase].setNeighbours('E');
            m_listCases[indexCase].setNeighbours('H');
        }
        else if(m_listCases[indexCase].getId() == 'C')
        {
            m_listCases[indexCase].setNeighbours('A');
            m_listCases[indexCase].setNeighbours('E');
            m_listCases[indexCase].setNeighbours('F');
            m_listCases[indexCase].setNeighbours('I');
        }
        else if(m_listCases[indexCase].getId() == 'D')
        {
            m_listCases[indexCase].setNeighbours('B');
            m_listCases[indexCase].setNeighbours('G');
            m_listCases[indexCase].setNeighbours('H');
            m_listCases[indexCase].setNeighbours('K');
        }
        else if(m_listCases[indexCase].getId() == 'E')
        {
            m_listCases[indexCase].setNeighbours('A');
            m_listCases[indexCase].setNeighbours('B');
            m_listCases[indexCase].setNeighbours('C');
            m_listCases[indexCase].setNeighbours('H');
            m_listCases[indexCase].setNeighbours('I');
            m_listCases[indexCase].setNeighbours('L');
        }
        else if(m_listCases[indexCase].getId() == 'F')
        {
            m_listCases[indexCase].setNeighbours('C');
            m_listCases[indexCase].setNeighbours('I');
            m_listCases[indexCase].setNeighbours('J');
            m_listCases[indexCase].setNeighbours('M');
            
        }
        else if(m_listCases[indexCase].getId() == 'G')
        {
            m_listCases[indexCase].setNeighbours('D');
            m_listCases[indexCase].setNeighbours('K');
            m_listCases[indexCase].setNeighbours('N');
        }
        else if(m_listCases[indexCase].getId() == 'H')
        {
            m_listCases[indexCase].setNeighbours('B');
            m_listCases[indexCase].setNeighbours('D');
            m_listCases[indexCase].setNeighbours('E');
            m_listCases[indexCase].setNeighbours('K');
            m_listCases[indexCase].setNeighbours('L');
            m_listCases[indexCase].setNeighbours('O');
        }
        else if(m_listCases[indexCase].getId() == 'I')
        {
            m_listCases[indexCase].setNeighbours('C');
            m_listCases[indexCase].setNeighbours('E');
            m_listCases[indexCase].setNeighbours('F');
            m_listCases[indexCase].setNeighbours('L');
            m_listCases[indexCase].setNeighbours('M');
            m_listCases[indexCase].setNeighbours('P');
        }
        else if(m_listCases[indexCase].getId() == 'J')
        {
            m_listCases[indexCase].setNeighbours('F');
            m_listCases[indexCase].setNeighbours('M');
            m_listCases[indexCase].setNeighbours('Q');
        }
        else if(m_listCases[indexCase].getId() == 'K')
        {
            m_listCases[indexCase].setNeighbours('D');
            m_listCases[indexCase].setNeighbours('G');
            m_listCases[indexCase].setNeighbours('H');
            m_listCases[indexCase].setNeighbours('N');
            m_listCases[indexCase].setNeighbours('O');
            m_listCases[indexCase].setNeighbours('R');
        }
        else if(m_listCases[indexCase].getId() == 'L')
        {
            m_listCases[indexCase].setNeighbours('E');
            m_listCases[indexCase].setNeighbours('H');
            m_listCases[indexCase].setNeighbours('I');
            m_listCases[indexCase].setNeighbours('O');
            m_listCases[indexCase].setNeighbours('P');
            m_listCases[indexCase].setNeighbours('S');
        }
        else if(m_listCases[indexCase].getId() == 'M')
        {
            m_listCases[indexCase].setNeighbours('F');
            m_listCases[indexCase].setNeighbours('I');
            m_listCases[indexCase].setNeighbours('J');
            m_listCases[indexCase].setNeighbours('P');
            m_listCases[indexCase].setNeighbours('Q');
            m_listCases[indexCase].setNeighbours('T');
        }
        else if(m_listCases[indexCase].getId() == 'N')
        {
            m_listCases[indexCase].setNeighbours('G');
            m_listCases[indexCase].setNeighbours('K');
            m_listCases[indexCase].setNeighbours('R');
            m_listCases[indexCase].setNeighbours('U');
        }
        else if(m_listCases[indexCase].getId() == 'O')
        {
            m_listCases[indexCase].setNeighbours('H');
            m_listCases[indexCase].setNeighbours('K');
            m_listCases[indexCase].setNeighbours('L');
            m_listCases[indexCase].setNeighbours('R');
            m_listCases[indexCase].setNeighbours('S');
            m_listCases[indexCase].setNeighbours('V');
        }
        else if(m_listCases[indexCase].getId() == 'P')
        {
            m_listCases[indexCase].setNeighbours('I');
            m_listCases[indexCase].setNeighbours('L');
            m_listCases[indexCase].setNeighbours('M');
            m_listCases[indexCase].setNeighbours('S');
            m_listCases[indexCase].setNeighbours('T');
            m_listCases[indexCase].setNeighbours('W');
        }
        else if(m_listCases[indexCase].getId() == 'Q')
        {
            m_listCases[indexCase].setNeighbours('J');
            m_listCases[indexCase].setNeighbours('M');
            m_listCases[indexCase].setNeighbours('T');
            m_listCases[indexCase].setNeighbours('X');
        }
        else if(m_listCases[indexCase].getId() == 'R')
        {
            m_listCases[indexCase].setNeighbours('K');
            m_listCases[indexCase].setNeighbours('N');
            m_listCases[indexCase].setNeighbours('O');
            m_listCases[indexCase].setNeighbours('U');
            m_listCases[indexCase].setNeighbours('V');
            m_listCases[indexCase].setNeighbours('Y');
        }
        else if(m_listCases[indexCase].getId() == 'S')
        {
            m_listCases[indexCase].setNeighbours('L');
            m_listCases[indexCase].setNeighbours('O');
            m_listCases[indexCase].setNeighbours('P');
            m_listCases[indexCase].setNeighbours('V');
            m_listCases[indexCase].setNeighbours('W');
            m_listCases[indexCase].setNeighbours('Z');
        }
        else if(m_listCases[indexCase].getId() == 'T')
        {
            m_listCases[indexCase].setNeighbours('M');
            m_listCases[indexCase].setNeighbours('P');
            m_listCases[indexCase].setNeighbours('Q');
            m_listCases[indexCase].setNeighbours('W');
            m_listCases[indexCase].setNeighbours('X');
            m_listCases[indexCase].setNeighbours('&');
        }
        else if(m_listCases[indexCase].getId() == 'U')
        {
            m_listCases[indexCase].setNeighbours('N');
            m_listCases[indexCase].setNeighbours('R');
            m_listCases[indexCase].setNeighbours('Y');
        }
        else if(m_listCases[indexCase].getId() == 'V')
        {
            m_listCases[indexCase].setNeighbours('O');
            m_listCases[indexCase].setNeighbours('R');
            m_listCases[indexCase].setNeighbours('S');
            m_listCases[indexCase].setNeighbours('Y');
            m_listCases[indexCase].setNeighbours('Z');
            m_listCases[indexCase].setNeighbours('#');
        }
        else if(m_listCases[indexCase].getId() == 'W')
        {
            m_listCases[indexCase].setNeighbours('P');
            m_listCases[indexCase].setNeighbours('S');
            m_listCases[indexCase].setNeighbours('T');
            m_listCases[indexCase].setNeighbours('Z');
            m_listCases[indexCase].setNeighbours('&');
            m_listCases[indexCase].setNeighbours('@');
        }
        else if(m_listCases[indexCase].getId() == 'X')
        {
            m_listCases[indexCase].setNeighbours('Q');
            m_listCases[indexCase].setNeighbours('T');
            m_listCases[indexCase].setNeighbours('&');
        }
        else if(m_listCases[indexCase].getId() == 'Y')
        {
            m_listCases[indexCase].setNeighbours('R');
            m_listCases[indexCase].setNeighbours('U');
            m_listCases[indexCase].setNeighbours('V');
            m_listCases[indexCase].setNeighbours('#');
        }
        else if(m_listCases[indexCase].getId() == 'Z')
        {
            m_listCases[indexCase].setNeighbours('S');
            m_listCases[indexCase].setNeighbours('V');
            m_listCases[indexCase].setNeighbours('W');
            m_listCases[indexCase].setNeighbours('#');
            m_listCases[indexCase].setNeighbours('@');
            m_listCases[indexCase].setNeighbours('$');
        }
        else if(m_listCases[indexCase].getId() == '&')
        {
            m_listCases[indexCase].setNeighbours('T');
            m_listCases[indexCase].setNeighbours('W');
            m_listCases[indexCase].setNeighbours('X');
            m_listCases[indexCase].setNeighbours('@');
        }
        else if(m_listCases[indexCase].getId() == '#')
        {
            m_listCases[indexCase].setNeighbours('V');
            m_listCases[indexCase].setNeighbours('Y');
            m_listCases[indexCase].setNeighbours('Z');
            m_listCases[indexCase].setNeighbours('$');
        }
        else if(m_listCases[indexCase].getId() == '@')
        {
            m_listCases[indexCase].setNeighbours('W');
            m_listCases[indexCase].setNeighbours('Z');
            m_listCases[indexCase].setNeighbours('&');
            m_listCases[indexCase].setNeighbours('$');
        }
        else if(m_listCases[indexCase].getId() == '$')
        {
            m_listCases[indexCase].setNeighbours('Z');
            m_listCases[indexCase].setNeighbours('#');
            m_listCases[indexCase].setNeighbours('@');
        }
    }
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


