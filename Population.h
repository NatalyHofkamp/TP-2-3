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
    void CreateRandPop(std::vector<City *> &);
    void SetRoutesRanked();
    void SortRoutes();
    std::vector<std::tuple<int, double>> Selection(); 
    std::vector<std::tuple<int, double>> CreateParents(std::vector<std::tuple<int, double>> &);
    void Reproduction(std::vector<std::tuple<int, double>> &, int);
    void Mutation(float, int);
    bool CheckEvolution(size_t, double);

    void SetLastBestRoute();
    void ChangeBestRouteEver();
    Route* GetBestRouteEver();
    double GetBestDist();
    double GetWorstDist();
    double PromTotalDist();
    int GetGeneration();
};
