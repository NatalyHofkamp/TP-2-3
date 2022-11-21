#include "../include/City.h"
#include <math.h>

bool City::operator==(City &other)
{
    return (this->x == other.x) && (this->y == other.y);
}


double City::DistCalc(City* other)
{
    return sqrt(pow(fabs(this->x - other->x), 2) + pow(fabs(this->y - other->y), 2));
}


double City::GetX()
{
    return x;
}


double City::GetY()
{
    return y;
}


void City::Print()
{
    std::cout<<"(" << this->x << "," << this->y << ")" <<std::endl;
}