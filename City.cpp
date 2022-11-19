#include "City.h"
#include <math.h>

bool City::operator==(City &other)
{
    return (this->x == other.x) && (this->y == other.y);
}


double City::DistCalc(City* ciudad)
{
    return sqrt(pow(fabs(this->x - ciudad ->x), 2) + pow(fabs(this->y - ciudad->y), 2));
}


void City::Print() const
{
    std::cout<<"City -> ("<<this->x<<","<<this->y<<")"<<std::endl;
}


double City::GetX() const 
{
    return x;
}


double City::GetY() const 
{
    return y;
}