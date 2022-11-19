#include "Route.h"
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
    std::cout << "Total dist[best]: " << TotalDist() << std::endl;
    for (auto elem: cities) {
        elem->Print();
    }
}


/*
void Route::Graph()
{
    std::fstream file;
    file.open("routegraph.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    for(const auto& city:this->cities){
        file<<city->GetX()<<","<<city->GetY()<<"\n";
    }
    file.close();
}



double Route::CalcFitness()
{
    this->fitness = 1/this->TotalDist();
    return this->fitness;
}


int Route::GetSize() 
{
    return size;
}


void Route::AddCity(double x,double y)
{
    cities.emplace_back(new City(x,y));
    size++;
}

void Route::Empty() 
{
    for(size_t i=0;i<size;i++){
        delete cities[0];
        cities.erase(cities.begin());       
    }
}

std::vector<City *> GetRangeCities(int start, int end);
std::vector<City *> Route::GetRangeCities(int start, int end) 
{
    std::vector<City *> rangeCities;
    for (size_t i=start; i < end+1; i++) {
        rangeCities.emplace_back(new City(*cities[i]));
    }

    return rangeCities;
}
*/