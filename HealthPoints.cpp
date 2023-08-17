#include "HealthPoints.h"
#include <ostream>
HealthPoints::HealthPoints(int healthPoints): m_currHealthPoints(healthPoints),m_maxHealthPoints(healthPoints)
{
    if(healthPoints<=0)
    {
        throw HealthPoints::InvalidArgument();
    }
}
HealthPoints& HealthPoints::operator+=(int healthPoints)
{
    m_currHealthPoints+=healthPoints;
    if(m_maxHealthPoints<m_currHealthPoints)
    {
        m_currHealthPoints=m_maxHealthPoints;
    }
    if(m_currHealthPoints<0)//adding negative number
    {
        m_currHealthPoints=0;
    }
    return *this;
}

HealthPoints& HealthPoints::operator-=(int healthPoints)
{
    m_currHealthPoints-=healthPoints;
    if(0>m_currHealthPoints)
    {
        m_currHealthPoints=0;
    }
    if(m_maxHealthPoints<m_currHealthPoints)//subtract negative number
    {
        m_currHealthPoints=m_maxHealthPoints;
    }
    return *this;
}
HealthPoints HealthPoints::operator+(int healthPoints) const
{
    HealthPoints temp(*this);
    temp+=healthPoints;
    return temp;
}
HealthPoints HealthPoints::operator-(int healthPoints) const
{
    HealthPoints temp(*this);
    temp-=healthPoints;
    return temp;
}
HealthPoints operator+(int healthPoints,const HealthPoints& healthPointsArgument)
{
    HealthPoints temp(healthPointsArgument);
    temp+=healthPoints;
    return temp;
}

bool HealthPoints::operator!=(const HealthPoints& other) const
{
    return m_currHealthPoints!=other.m_currHealthPoints;
}
bool HealthPoints::operator==(const HealthPoints& other) const
{
    return m_currHealthPoints==other.m_currHealthPoints;
}
bool HealthPoints::operator<=(const HealthPoints& other) const
{
    return m_currHealthPoints<=other.m_currHealthPoints;
}
bool HealthPoints::operator>=(const HealthPoints& other) const
{
    return m_currHealthPoints>=other.m_currHealthPoints;
}
bool HealthPoints::operator<(const HealthPoints& other) const
{
    return m_currHealthPoints<other.m_currHealthPoints;
}
bool HealthPoints::operator>(const HealthPoints& other) const
{
    return m_currHealthPoints>other.m_currHealthPoints;
}
bool operator==(int healthPoints,const HealthPoints& healthPointsObject)
{
    return healthPointsObject==healthPoints;
}
bool operator!=(int healthPoints,const HealthPoints& healthPointsObject)
{
    return healthPointsObject!=healthPoints;
}
bool operator<=(int healthPoints,const HealthPoints& healthPointsObject)
{
    return healthPointsObject>=healthPoints;
}
bool operator>=(int healthPoints,const HealthPoints& healthPointsObject)
{
    return healthPointsObject<=healthPoints;
}
bool operator<(int healthPoints,const HealthPoints& healthPointsObject)
{
    return healthPointsObject>healthPoints;
}
bool operator>(int healthPoints,const HealthPoints& healthPointsObject)
{
    return healthPointsObject<healthPoints;
}

std::ostream& operator<<(std::ostream& os,const HealthPoints& other)
{
    os << other.m_currHealthPoints << "(" << other.m_maxHealthPoints << ")";
    return os;
}
