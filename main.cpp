<<<<<<< Updated upstream
#include "Ruta.h"
int main(void){
    Rute* ruta= new Rute();
    ruta->AddCity(0,1);
    ruta->AddCity(1,0);
    ruta->AddCity(2,1);
    ruta->AddCity(13,0);
    ruta->AddCity(0,1);
    cout<<ruta->TotalDist()<<endl;
    ruta->empty();
    delete ruta;
}
=======
#include <iostream>

#include "City.h"
#include "Route.h"
#include "Population.h"
#include "Graph.h"
#include "reader.h"


void generations(std::vector<City *> allCities, int generations, double minChange) 
{
    remove("RoutesDataMax.txt");
    remove("RoutesDataMin.txt");
    remove("RoutesDataProm.txt");
    remove("BestRouteGraph.txt");

    std::vector<Graph *> graphs;
    graphs.emplace_back(new GraphMax("RoutesDataMax.txt"));
    graphs.emplace_back(new GraphMin("RoutesDataMin.txt"));
    graphs.emplace_back(new GraphProm("RoutesDataProm.txt"));
    
    GraphBestRoute *bestRoute = new GraphBestRoute("BestRouteGraph.txt");

    Population *p = new Population(300);
    std::vector<std::tuple<int, double>> selected;

    p->CreateRandPop(allCities); 
    p->SetRoutesRanked();
    p->SortRoutes();
    p->SetLastBestRoute();

    while (p->CheckEvolution(generations, minChange)) {
        p->SetLastBestRoute();
        selected = p->Selection();
        p->Reproduction(p->CreateParents(selected), allCities.size()); 
        p->Mutation(0.02, allCities.size());
        p->SetRoutesRanked();
        p->SortRoutes();
        p->ChangeBestRouteEver();

        for (auto g: graphs) {
            g->AddInfoFile(p);
        }    
    }

    p->GetBestRouteEver()->PrintCities();
    bestRoute->AddInfoFile(p);

    for (auto g: graphs) {
        delete g;
    }
    delete bestRoute;
    delete p;
}


int main() 
{
    srand(time(NULL));
    /*comands();*/
    std::vector<City *> allCities = reader::readCsv("cities.txt");
    generations(allCities, 300, 200);

    for (auto each: allCities) {
        delete each;
    }

    return 0;
}
>>>>>>> Stashed changes
