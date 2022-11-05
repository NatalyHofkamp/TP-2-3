#include <iostream>
#include <vector>
#include "City.h"
#ifndef RUTA_H
using namespace std;


class Rute
{
  private:
    vector <City*> Cities;
    double Fitness;
  public:
  Rute(){}
  ~Rute(){
    cout<<"~Ruta()"<<endl;
  }
  void AddCity(double x, double y);
  void CalcFitness();
  double TotalDist();
  void Empty();
  void PrintCities();
  
};

#endif