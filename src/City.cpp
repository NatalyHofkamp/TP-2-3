#include "../include/City.h"
#include <math.h>

bool City::operator==(City &other)
{
    return (this->x == other.x) && (this->y == other.y);
}


double City::DistCalc(City* ciudad)
{
    return sqrt(pow(fabs(this->x - ciudad ->x), 2) + pow(fabs(this->y - ciudad->y), 2));
}


double City::GetX()
{
    return x;
}


double City::GetY()
{
    return y;
}