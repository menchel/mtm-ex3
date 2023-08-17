#ifndef HEALTH_POINTS_H
#define HEALTH_POINTS_H
#include <ostream>
class HealthPoints
{
    int m_currHealthPoints;
    int m_maxHealthPoints;
    static const int MAX_HEALTH_POINTS=100;
public:

    //constructor
    //throws Invalid argument if hp is not positive
    HealthPoints(int healthPoints=MAX_HEALTH_POINTS);

    //copy constructor
    HealthPoints(const HealthPoints& other)=default;

    //destructor
    ~HealthPoints()=default;

    //assignment operation
    HealthPoints& operator=(const HealthPoints& other)=default;

    //adding operator
    HealthPoints& operator+=(int healthPoints);

    //subtracting operator
    HealthPoints& operator-=(int healthPoints);

    //plus operator for object+int
    HealthPoints operator+(int healthPoints) const;

    //minus operator for object-int
    HealthPoints operator-(int healthPoints) const;

    //not equal operator for object!=object
    bool operator!=(const HealthPoints& other) const;

    //equal operator for object==object
    bool operator==(const HealthPoints& other) const;

    //less or equal operator for object<=object
    bool operator<=(const HealthPoints& other) const;

    //nore or equal operator for object>=object
    bool operator>=(const HealthPoints& other) const;

    //less than operator for object<object
    bool operator>(const HealthPoints& other) const;

    //more than operator for object>object
    bool operator<(const HealthPoints& other) const;

    //<< operator for printing
    //is a friend function since we need the m_hp and m_max_hp
    friend std::ostream& operator<<(std::ostream&,const HealthPoints& other);

    //exception class when max hp is not positive
    class InvalidArgument{};
};

//plus operator for int+object
HealthPoints operator+(int healthPoints,const HealthPoints& healthPointsArgument);

//not equal operator for int!=object
bool operator==(int healthPoints,const HealthPoints& healthPointsObject);

//equal operator for int==object
bool operator!=(int healthPoints,const HealthPoints& healthPointsObject);

//less or equal operator for int<=object
bool operator<=(int healthPoints,const HealthPoints& healthPointsObject);

//more or equal operator for int>=object
bool operator>=(int healthPoints,const HealthPoints& healthPointsObject);

//less than operator for int<object
bool operator<(int healthPoints,const HealthPoints& healthPointsObject);

//more than operator for int>object
bool operator>(int healthPoints,const HealthPoints& healthPointsObject);

#endif // HEALTH_POINTS_H
