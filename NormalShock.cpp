#include "NormalShock.hpp"

NormalShock::NormalShock() :
    m_m1(0.0),
    m_m1b(false),
    m_m2(0.0),
    m_m2b(false),
    m_p1(Types::Pressure_Type_Pascal, 0.0),
    m_p2(Types::Pressure_Type_Pascal, 0.0),
    m_pt1(Types::Pressure_Type_Pascal, 0.0),
    m_pt2(Types::Pressure_Type_Pascal, 0.0),
    m_t1(Types::Temperature_Type_Celcius, 0.0),
    m_t2(Types::Temperature_Type_Celcius, 0.0),
    m_tt1(Types::Temperature_Type_Celcius, 0.0),
    m_tt2(Types::Temperature_Type_Celcius, 0.0),
    m_gamma(1.40), //default of 1.4?
    m_a(0.0)
{
    
}

NormalShock::~NormalShock()
{
    //nothing to do
}

bool
NormalShock::getP2byP1(double* ratio)
{
    bool retVal = false;
    if ((m_m1b && m_m2b))
    {
        double top = 1 + m_gamma * m_m1 * m_m1;
        double bot = 1 + m_gamma * m_m2 * m_m2;
        *ratio = top / bot;
        retVal = true;
    }
    else if (m_m1b)
    {
        double first = (2.0 * m_gamma) / (m_gamma + 1);
        double second = m_m1 * m_m1 - 1;
        *ratio = 1 + first * second;
        retVal = true;
    }
    return retVal;
}

bool
NormalShock::getT2byT1(double* ratio)
{
    bool retVal = false;
    if ((m_m1b && m_m2b))
    {
        double top = 1 + ((m_gamma - 1) / 2) * m_m1 * m_m1;
        double bot = 1 + ((m_gamma - 1) / 2) * m_m2 * m_m2;
        *ratio = top / bot;
        retVal = true;
    }
    return retVal;
}

bool
NormalShock::getPt2byP1(double* ratio)
{
    bool retVal = false;
    if ((m_m1b && m_m2b))
    {
        double top = 1 + m_gamma * m_m1 * m_m1;
        double bot = 1 + m_gamma * m_m2 * m_m2;
        double first = (1 + ((m_gamma - 1) / 2.0) * m_m2 * m_m2);
        first = pow(first, (m_gamma / (m_gamma - 1)));
        *ratio = first * (top / bot);
        retVal = true;
    }
    return retVal;
}
