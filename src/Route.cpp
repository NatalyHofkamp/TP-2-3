#include "../include/Route.h"
#include <fstream>


int Route::GetSize() 
{
    return this->size;
}


void Route::AddCity(City *newCity) {
    cities.emplace_back(newCity);
    size++;
}


bool Route::HasCity(City *city) 
{
    for (auto elem: cities) {
        if (*elem == *city) {
            return true;
        }
    }
    return false;
}


City * Route::GetCity(int position) 
{
    return cities[position];
}


void Route::SwapCity(int i, int j) 
{
    City *aux = cities[i];
    cities[i] = cities[j];
    cities[j] = aux;
}


double Route::TotalDist()
{
    double total=0;
    if (cities.size() <= 1) {
        return 0;
    }

    for(size_t i=0;i<(cities.size()-1);i++){
        total+= cities[i]->DistCalc(cities[i+1]);
    }
    total+= cities[0]->DistCalc(cities[cities.size()-1]);
    
    return total;
}


void Route::PrintCities() 
{
    for (auto elem: cities) {
        elem->Print();
    }
}
