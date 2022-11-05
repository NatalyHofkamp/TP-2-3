#include "Population.h"


std::vector<City *> read_csv(std::string name_csv);

Population::Population(int size) {
    this->size = size;
}


void Population::CreateRandPop(std::vector<City *> all_cities) {
    Rute *rute;
    std::vector<City *> aux;
    int counter = 0;
    int rand_num;

    for (size_t i = 0; i < size; i++) {
        aux = all_cities;
        for (size_t r = 0; r < all_cities.size(); r++) {
            rand_num = rand()%(r-counter);
            counter++;
            rute = new Rute();
            rute->AddCity(all_cities[rand_num]->GetX(), all_cities[rand_num]->GetY());
            aux.erase(aux.begin() + rand_num);
        }
        roads.emplace_back(rute);
    }
}

/* Arreglo de rutas en vez de vectr:
Ruta *rute = new Ruta[all_cities.size()];
rute[i] = Ruta();
*/