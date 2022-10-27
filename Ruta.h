#include <iostream>
#include <vector>
#include "City.h"
#ifndef RUTA_H
using namespace std;
class Ruta
{
  private:
    vector <City*> Ciudades;
  public:
  Ruta(){}
  ~Ruta(){
    cout<<"~Ruta()"<<endl;
  }
  void cargarCiudad(double x, double y);
  double DistanciaTotal();
  void vaciar();
  
};

#endif