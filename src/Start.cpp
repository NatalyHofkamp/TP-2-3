#include "../include/Start.h"


void Generations(std::vector<City *> &allCities, int generations, double minChange, std::vector<Graph *> &graphs, bool best) 
{
    Population *p = new Population(300);
    std::vector<std::tuple<int, double>> selected;

    p->CreateRandPop(allCities); 
    p->SetRoutesRanked();
    p->SetLastBestRoute();

    while (p->CheckEvolution(generations, minChange)) {
        p->SetLastBestRoute();
        selected = p->Selection();
        p->Reproduction(selected, allCities.size()); 
        p->Mutation(0.02, allCities.size());
        p->SetRoutesRanked();
        p->ChangeBestRouteEver();

        for (auto g: graphs) {
            g->AddInfoFile(p);
        }    
    }
    if (best) {
        p->PrintBestRouteEver();
    }

    for (auto g: graphs) {
        delete g;
    }
    delete p;
}


void SetGraphs(std::string out, std::vector<Graph *> &graphs) 
{
    remove("RoutesDataMax.txt");
    remove("RoutesDataMin.txt");
    remove("RoutesDataProm.txt");
    remove("BestRouteGraph.txt");

    for (size_t i=0; i < out.size(); i++) {
        if (out[i] == '1') {
            graphs.emplace_back(new GraphMax("RoutesDataMax.txt"));
        } else if (out[i] == '2') {
            graphs.emplace_back(new GraphMin("RoutesDataMin.txt"));
        } else if (out[i] == '3') {
            graphs.emplace_back(new GraphProm("RoutesDataProm.txt"));
        } else if (out[i] == '4') {
            graphs.emplace_back(new GraphBestRoute("BestRouteGraph.txt"));
        }
    }
}


void StartAlgorithm(int argc, char *argv[]) 
{
    std::string file;
    double umbral;
    size_t gen;
    std::string out;
    bool best = false;
    bool check;

    check = Parser(argc, argv, file, umbral, gen, out, best);  
    if (check) {
        std::vector<City *> allCities = readCsv(file);
        std::vector<Graph *> graphs;
        SetGraphs(out, graphs);  
        Generations(allCities, gen, umbral, graphs, best);
        
        for (auto each: allCities) {
            delete each;
        }
    }
}
