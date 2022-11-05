#include <iostream>
#include <vector>
#include <cstdlib>
#include "City.h"
#include "Rute.h"


class Population {
        std::vector<Rute *> roads;
        int size;
    public:
        Population(int size);
        void CreateRandPop(std::vector<City *> all_cities);
        void Selection(); 
        void Reproduction();
        void Mutation();
        void Elitism();
};