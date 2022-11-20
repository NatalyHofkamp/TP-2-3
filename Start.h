#pragma once

#include <iostream>

#include "City.h"
#include "Route.h"
#include "Population.h"
#include "Graph.h"
#include "Reader.h"
#include "Parser.h"


void Generations(std::vector<City *> &allCities, int generations, double minChange, std::vector<Graph *> &graphs);
void SetGraphs(std::string out, std::vector<Graph *> &graphs);
void StartAlgorithm(int argc, char *argv[]);
