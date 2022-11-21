#pragma once

#include <iostream>
#include <vector>
#include "City.h"

class Route
{
  private:
    std::vector <City*> cities;
    int size;

  public:
    Route()
    {
      size = 0;
    }

    Route(Route &other)
    {
      this->cities = other.cities;
      this->size = other.size;
    }

    ~Route(){};

    int GetSize();
    void AddCity(City *newCity);
    bool HasCity(City *city);
    City *GetCity(int position);
    void SwapCity(int i, int j);
    double TotalDist();
    void PrintCities();
};
