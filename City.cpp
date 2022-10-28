#include "City.h"
#include <math.h>

double City:: DistCalc(City* ciudad)
{
    return sqrt(pow(fabs(this->x - ciudad ->x), 2) + pow(fabs(this->y - ciudad->y), 2));
}

void City::print()
{
    cout<<"Ciudad -> ("<<this->x<<","<<this->y<<")"<<endl;
}