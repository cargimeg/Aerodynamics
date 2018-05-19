#ifndef NormalShock_HPP
#define NormalShock_HPP

#include "Types\Pressure.hpp"
#include "Types\Temperature.hpp"
#include "math.h"
#include "Types\Types.hpp"

class NormalShock
{
public:
    NormalShock();
    ~NormalShock();

    void setP1(Pressure p1);

    void setP2(Pressure p2);

    void setM1(double m1);

    void setM2(double m2);

    void setT1(Temperature t1);

    void setT2(Temperature t2);

    void setGamma(double gamma);

    bool getP2byP1(double* ratio);

    bool getT2byT1(double* ratio);

    bool getPt2byP1(double* ratio);


private:

    double m_m1;

    bool m_m1b;

    double m_m2;

    bool m_m2b;

    Pressure m_p1;

    Pressure m_p2;

    Pressure m_pt1;

    Pressure m_pt2;

    Temperature m_t1;

    Temperature m_t2;

    Temperature m_tt1;

    Temperature m_tt2;

    double m_gamma;

    double m_a;
};

inline void NormalShock::setP1(Pressure p1)
{
    m_p1 = p1;
}

inline void NormalShock::setP2(Pressure p2)
{
    m_p2 = p2;
}

inline void NormalShock::setM1(double m1)
{
    m_m1 = m1;
    m_m1b = true;
}

inline void NormalShock::setM2(double m2)
{
    m_m2 = m2;
    m_m2b = true;
}

inline void NormalShock::setT1(Temperature t1)
{
    m_t1 = t1;
}

inline void NormalShock::setT2(Temperature t2)
{
    m_t2 = t2;
}

inline void NormalShock::setGamma(double gamma)
{
    m_gamma = gamma;
}

#endif
