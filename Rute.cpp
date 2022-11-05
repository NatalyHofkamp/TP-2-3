#include "Rute.h"

void Rute::Empty()
{
    int sizeCities = Cities.size();
    for(size_t i=0;i<sizeCities;i++){
        delete Cities[0];
        Cities.erase(Cities.begin());       
    }
}

void Rute::AddCity(double x,double y)
{
    Cities.emplace_back(new City(x,y));
}

double Rute::TotalDist()
{
    double total=0;
    if (Cities.size() <= 1) {
        return 0;
    }

    for(size_t i=0;i<(Cities.size()-1);i++){
        total+= Cities[i]->DistCalc(Cities[i+1]);
    }
    total+= Cities[0]->DistCalc(Cities[Cities.size()-1]);
    
    return total;
}

void Rute:: CalcFitness(void)
{
    this->Fitness = 1/this->TotalDist();
}

void Rute::PrintCities() 
{
    for (auto elem: Cities) {
        elem->Print();
    }
}