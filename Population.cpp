#include "Population.h"
#include <fstream>


Population::~Population() 
{
    /*destructor de poblaciones*/
    for(size_t i=0;i<size;i++){
        delete routes[0];
        routes.erase(routes.begin());       
    }
    std::cout<<"~Population()"<<std::endl;
}


void Population::CreateRandPop(std::vector<City *> allCities) 
{
    /*  crea nuevas rutas y las mete en una población*/
    Route *route;
    std::vector<City *> aux;
    int rand_num;

    for (size_t i = 0; i < size; i++) {
        route = new Route();
        aux = allCities;
        for (size_t r = 0; r < allCities.size(); r++) {
            rand_num = rand()%(allCities.size()-r);
            route->AddCity(aux[rand_num]);
            aux.erase(aux.begin() + rand_num);
        }
        routes.emplace_back(route);
        
    }
    this->bestRouteEver = new Route(*routes[0]);
}


void Population::SetRoutesRanked()
{
    /* crea el ranking de rutas con su índice y valor de fitness*/
    int counter = 0;
    routesRanked.clear();
    for(auto r: routes){
        /*num de la generacion, distancia total de cada ruta*/
        routesRanked.emplace_back(std::make_tuple(counter, (r->TotalDist())));
        counter++;
    }
}


void Population::SortRoutes()
{
    /*ordena las rutas por su fitness [menor a mayor distancia]*/
    std::tuple<int, double> aux;

    for (size_t r = 0; r < routesRanked.size(); r++) {
        for (size_t i = r+1; i < (routesRanked.size()); i++) {
            if (std::get<1>(routesRanked[i]) < std::get<1>(routesRanked[r])) {
                aux = routesRanked[r];
                routesRanked[r] = routesRanked[i];
                routesRanked[i] = aux;
            }
        }
    }
}


std::vector<std::tuple<int, double>> Population::Selection()
{ 
    /*seleccionar los padres, eligiendo el primer cuarto de la poblacion [menor distancia recorrida]*/
    std::vector<std::tuple<int, double>> selected;
    size_t i = 0;
    while (i < routesRanked.size()/4) {
        selected.emplace_back(routesRanked[i]);
        i++;
    }
    return selected;
}


std::vector<std::tuple<int, double>> Population::CreateParents(std::vector<std::tuple<int, double>> parents)
{
    /*mejora lista de seleccion de padres, repitiendo mas veces a los mejores*/
    std::vector<std::tuple<int, double>> newParents;
    double total = 0;
    for (size_t i=0; i < parents.size(); i++) {
        total += 1/std::get<1>(parents[i]);
    }

    for(const auto& p: parents){
        for(size_t i = 0; i < (1/(std::get<1>(p)*total))*size; i++){
            newParents.emplace_back(p);
        }
    }
    return newParents;
}


void Population::Reproduction(std::vector<std::tuple<int, double>> parents, int routeSize) 
{
    this->counterGenerations += 1;
    Route *child; 
    std::vector<Route *> newGeneration;
    newGeneration.emplace_back(routes[std::get<0>(routesRanked[0])]);
    
    City *aux[4];
    City *best;
    bool check = false;

    int randParent1;
    int randParent2;

    for (size_t i=0; i < routes.size()-1; i++) {
        randParent1 = rand() % parents.size();
        do {
            randParent2 = rand() % parents.size(); 
        } while (randParent2 == randParent1);
        child = new Route();

        if (std::get<1>(parents[randParent1]) < std::get<1>(parents[randParent2])) { //SI CAMBIA FITNESS/TOTAL O DIST ESTO CAMBIA
            child->AddCity( routes[std::get<0>(parents[randParent1])]->GetCity(0) );
        } else {
            child->AddCity(routes[std::get<0>(parents[randParent2])]->GetCity(0) );
        }

        for (size_t i=1; i < routeSize; i++) {
            aux[0] = routes[std::get<0>(parents[randParent1])]->GetCity(i);
            aux[1] = routes[std::get<0>(parents[randParent2])]->GetCity(i);
            aux[2] = routes[std::get<0>(parents[randParent1])]->GetCity((i-2)%this->size);
            aux[3] = routes[std::get<0>(parents[randParent2])]->GetCity((i-2)%this->size);

            for (auto elem: aux) {
                if (!(child->HasCity(elem)) && (!check)) {
                    best = elem;
                    check = true;
                    continue;
                }

                if (!(child->HasCity(elem)) && (check)) {
                    if (elem->DistCalc(child->GetCity(i-1)) < best->DistCalc(child->GetCity(i-1))) { //SI CAMBIA FITNESS/TOTAL O DIST ESTO CAMBIA
                        best = elem;
                        check = true;
                    }
                }
            }

            if (!(check)) {
                for (size_t i=0; i < routeSize; i++) {
                    if (!(child->HasCity(routes[std::get<0>(parents[randParent1])]->GetCity(i)))) {
                        child->AddCity(routes[std::get<0>(parents[randParent1])]->GetCity(i));
                        break;
                    }
                }
            } else {
                child->AddCity(best);
                check = false;
            }
        }
        newGeneration.emplace_back(child);
    }
    //aca habria que eliminar/delete a las rutas en rutes para liberar su espacio
    routes.erase(routes.begin() + std::get<0>(routesRanked[0]));
    for (auto route: routes) {
        delete route;
    }
    this->routes = newGeneration;
   
}


void Population::Mutation(float percentage, int sizeRoute) 
{
    int randFirst;
    for (auto each: routes) {
        randFirst = rand() % 1;
        if (randFirst < percentage) {
            each->SwapCity(rand() % sizeRoute, rand() % sizeRoute);
        }
    }
}


bool Population::CheckEvolution(size_t generations, double minChange) 
{
    if (counterGenerations == generations) {
        return false;
    }

    if ( fabs(lastBestRoute->TotalDist() - routes[std::get<0>(routesRanked[0])]->TotalDist()) < minChange) {
        this->counterMinChange += 1;
    } else {
        this->counterMinChange = 0;
    }

    if (counterMinChange == 10) {
        return false;
    }

    return true;
}


void Population::SetLastBestRoute()
{
    if (counterGenerations != 1) {
        delete this->lastBestRoute;
    }
    this->lastBestRoute = new Route(*routes[std::get<0>(routesRanked[0])]);
}


Route* Population::GetBestRouteEver()
{
    return this->bestRouteEver;
}


void Population::ChangeBestRouteEver()
{
    if(std::get<1>(routesRanked[0]) < bestRouteEver->TotalDist()){
        delete bestRouteEver;
        bestRouteEver = new Route(*routes[std::get<0>(routesRanked[0])]);
    }
}


double Population::GetBestDist()
{
    return std::get<1>(routesRanked[0]);
}


double Population::GetWorstDist()
{
    return std::get<1>(routesRanked[routesRanked.size()-1]);
}


double Population::PromTotalDist() 
{
    /*la suma de todos los fitness*/
    double total = 0;
    for(auto r: routes){
        total += r->TotalDist();
    }
    return total/this->size;

}


int Population::GetGeneration() 
{
    return this->counterGenerations;
}



/*
void Population::PrintPopulation() {
    int counter = 1;
    std::cout << std::endl << "<<population>>" << std::endl;
    for (auto each: routes) {
        std::cout << "ruta " << counter << std::endl;
        std::cout << "Fitness = " << each->TotalDist() << ": " << std::endl;
        each->PrintCities();
        std::cout << std::endl;
        counter++;
    }

}
void Population::PrintBestRoute() 
{
    std::cout << " PrintbestRoute dist = " << routes[std::get<0>(routesRanked[0])]->TotalDist() << std::endl << std::endl;
    std::cout << "generations = " << this->counterGenerations << std::endl << std::endl;
}

void Population::PrintRutesRanked() {
    for (auto each: routesRanked) {
        std::cout << "rutesranked: " << routes[std::get<0>(each)]->TotalDist() << std::endl;
    }
}

void Population::Reproduction(std::vector<std::tuple<int, double>> parents, int ruteSize) {
    this->counterGenerations += 1;
    std::vector<City *> parent1;
    City * parent2;
    Route *newRoute; 
    std::vector<Route *> newGeneration;

    int randInt;
    int randParent1;
    int randParent2;
    srand(time(NULL));

    bool check = false;

    for (size_t i=0; i < routes.size(); i++) {
        randInt = rand() % ruteSize/2;
        randParent1 = rand() % parents.size();
        randParent2 = rand() % parents.size();
        newRoute = new Route();

        parent1 = routes[std::get<0>(parents[randParent1])]->GetRangeCities(randInt, randInt + ruteSize/2 - 1);

        for (size_t j=0; j < ruteSize; j++) {
            parent2 = routes[std::get<0>(parents[randParent2])]->GetCity(j);
            if (j == randInt) {
                for (auto elem: parent1) {
                    newRoute->AddCity(elem);
                }
            }
            //en el siguiente codigo se asume que no hay ciudades repetidas, ver de asegurarse esto cuando se lee el archivo
            for (auto each: parent1) {
                if (*each == *parent2) {
                    check = true;
                    break;
                }
            } 
            if (!check) {
                newRoute->AddCity(parent2); 
            }
            check = false;
        }
        newGeneration.emplace_back(newRoute);
    }
    //aca habria que eliminar/delete a las rutas en rutes para liberar su espacio
    //for (auto route: routes) {
    //    delete route;
    //}
    this->routes = newGeneration;
}

void Population::WriterMax()
{
    std::fstream file;
    file.open("RoutesDataMax.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    file << counterGenerations<<  ", "<<this->GetBestDist()<<"\n";
    file.close();
}
void Population::WriterMin()
{
    std::fstream file;
    file.open("RoutesDataMin.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    file << counterGenerations<<  ","<<this->GetWorstFitness()<<"\n";
    file.close();
}


void Population::WriterProm()
{
     std::fstream file;
    file.open("RoutesDataProm.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    file << counterGenerations<<  ","<<this->TotalFitness()/routes.size()<<"\n";
    file.close();
}
*/
