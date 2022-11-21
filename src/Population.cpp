#include "../include/Population.h"
#include <fstream>


Population::~Population() 
{
    for(auto route:routes){
        delete route;
        }
}


void Population::CreateRandPop(std::vector<City *> &allCities) 
{
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
    int counter = 0;
    routesRanked.clear();
    for(auto r: routes){
        routesRanked.emplace_back(std::make_tuple(counter, (r->TotalDist())));
        counter++;
    }

    this->SortRoutes();
}


void Population::SortRoutes()
{
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
    std::vector<std::tuple<int, double>> selected;
    size_t i = 0;
    while (i < routesRanked.size()/4) {
        selected.emplace_back(routesRanked[i]);
        i++;
    }

    selected = this->CreateParents(selected);
    return selected;
}


std::vector<std::tuple<int, double>> Population::CreateParents(std::vector<std::tuple<int, double>> &parents)
{
    std::vector<std::tuple<int, double>> newParents;
    double total = 0;
    for (size_t i=0; i < parents.size(); i++) {
        total += 1/std::get<1>(parents[i]);
    }

    for(const auto& p: parents){
        for(size_t i = 0; i < (1/(std::get<1>(p)*total))*size; i++){
            if (newParents.size() < this->size) {
                newParents.emplace_back(p);
            } else {
                break;
            }
        }
    }
    return newParents;
}


void Population::Reproduction(std::vector<std::tuple<int, double>> &parents, int routeSize) 
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
        randParent2 = rand() % parents.size(); 
        child = new Route();

        if (std::get<1>(parents[randParent1]) < std::get<1>(parents[randParent2])) {
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
                if (!(child->HasCity(elem))) {
                    if (!check) {
                        best = elem;
                        check = true;
                        continue;
                    } 
                    if (elem->DistCalc(child->GetCity(i-1)) < best->DistCalc(child->GetCity(i-1))) {
                        best = elem;
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


void Population::ChangeBestRouteEver()
{
    if(std::get<1>(routesRanked[0]) < bestRouteEver->TotalDist()){
        delete bestRouteEver;
        bestRouteEver = new Route(*routes[std::get<0>(routesRanked[0])]);
    }
}


Route* Population::GetBestRouteEver()
{
    return this->bestRouteEver;
}


void Population::PrintBestRouteEver() {
    std::cout << "<< Best route found >>" << std::endl;
    std::cout << "After " << this->counterGenerations << " generations, the best distance achieved was: " << this->bestRouteEver->TotalDist() << std::endl;
    std::cout << "The cities on this route were in the following order: " << std::endl;
    this->bestRouteEver->PrintCities();
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
