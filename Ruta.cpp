#include "Ruta.h"
void Ruta::vaciar(){
    for(size_t i=0;i<(Ciudades.size());i++){
        delete Ciudades[i];
    }
}

void Ruta::cargarCiudad(double x,double y)
{
    Ciudades.emplace_back(new City(x,y));
}

double Ruta::DistanciaTotal()
{
    double total=0;
    for(size_t i=0;i<(Ciudades.size()-1);i++){
        total+= Ciudades[i]->calcularDistancia(Ciudades[i+1]);
    }
    total+= Ciudades[0]->calcularDistancia(Ciudades[Ciudades.size()-1]);
    
    return total;
}