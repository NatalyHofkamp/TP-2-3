#include "Graph.h"


void GraphMax::AddInfoFile(Population * pop) const
{
    std::fstream file;
    file.open(this->nameFile, std::fstream::in | std::fstream::out | std::fstream::app);
    file << pop->GetGeneration() <<  ", " << pop->GetBestDist() << "\n";
    file.close();
}


void GraphMin::AddInfoFile(Population * pop) const
{
    std::fstream file;
    file.open(this->nameFile, std::fstream::in | std::fstream::out | std::fstream::app);
    file << pop->GetGeneration() <<  ", " << pop->GetWorstDist() << "\n";
    file.close();
}


void GraphProm::AddInfoFile(Population * pop) const
{
    std::fstream file;
    file.open(this->nameFile, std::fstream::in | std::fstream::out | std::fstream::app);
    file << pop->GetGeneration() <<  ", " << pop->PromTotalDist() << "\n";
    file.close();
}


void GraphBestRoute::AddInfoFile(Population * pop) const
{
    remove("BestRouteGraph.txt");
    std::fstream file;
    file.open(this->nameFile, std::fstream::in | std::fstream::out | std::fstream::app);
    Route * bestRoute = pop->GetBestRouteEver();
    for (size_t i = 0; i < bestRoute->GetSize(); i++) {
        file << bestRoute->GetCity(i)->GetX() << "," << bestRoute->GetCity(i)->GetY() << "\n";
    }
    file.close();
}
