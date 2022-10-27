#include "City.h"
#include <math.h>

double City:: calcularDistancia(City* ciudad)
{
    return sqrt(pow(fabs(this->x - ciudad ->x), 2) + pow(fabs(this->y - ciudad->y), 2));
}

void City::imprimirCiudad()
{
    cout<<"Ciudad -> ("<<this->x<<","<<this->y<<")"<<endl;
}