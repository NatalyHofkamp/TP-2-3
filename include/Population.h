#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "Graph.h"
#include "Route.h"


class Population 
{
  private:
    std::vector<Route *> routes;
    friend void testPopulation(Population* pop);
    std::vector<std::tuple<int, double>> routesRanked;
    int size;
    int counterGenerations;
    Route* bestRouteEver; 
    int counterMinChange;
    Route *lastBestRoute;


  public:
    Population(int size) 
    {
      this->size = size;
      this->counterGenerations = 1;
      this->counterMinChange = 0;
    }

    ~Population();
    void CreateRandPop(std::vector<City *> &allCities);
    void SetRoutesRanked();
    void SortRoutes();
    std::vector<std::tuple<int, double>> Selection(); 
    std::vector<std::tuple<int, double>> CreateParents(std::vector<std::tuple<int, double>> &parents);
    void Reproduction(std::vector<std::tuple<int, double>> &parents, int routeSize);
    void Mutation(float percentage, int sizeRoute);
    bool CheckEvolution(size_t generations, double minChange);

    void SetLastBestRoute();
    void ChangeBestRouteEver();
    Route* GetBestRouteEver();
    void PrintBestRouteEver();
    double GetBestDist();
    double GetWorstDist();
    double PromTotalDist();
    int GetGeneration();
};
