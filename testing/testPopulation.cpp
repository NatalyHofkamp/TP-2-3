#include "../testing/testHeader.h"


void testPopulation(Population* p) {
    std::vector<City*> allCities;
    allCities.emplace_back(new City(1,0));
    allCities.emplace_back(new City(0,0));
    allCities.emplace_back(new City(3,0));
    allCities.emplace_back(new City(0,4));
    Route* ruta= new Route();
    for( auto city:allCities){
        ruta->AddCity(city);
       
    }
    std::vector<std::tuple<int, double>> selected;
    assert((p->size==300)==true);
    p->CreateRandPop(allCities); 
    assert((p->bestRouteEver==ruta)==false);
    p->SetRoutesRanked();
    assert(std::get<1>(p->routesRanked[0])==12);
    p->SetLastBestRoute();
    assert(p->counterGenerations==0);
    selected = p->Selection();
    assert((std::get<1>(selected[0])==std::get<1>(selected[2]))==true);
    p->Reproduction(selected, allCities.size());
    assert(p->counterGenerations==2);
    p->Mutation(0.02, allCities.size());
    p->SetRoutesRanked();
    assert(((std::get<1>(p->routesRanked[0]))<(std::get<1>(p->routesRanked[150])))==true);
    p->ChangeBestRouteEver();
    assert(((p->bestRouteEver)->TotalDist()==(p->routes[std::get<0>(p->routesRanked[0])])->TotalDist())==true);

    std::cout<<"[POPULATION TESTING]=OK"<<std::endl;
    delete ruta;
    for(auto city: allCities){
        delete city;
    }
    delete p;
}