#pragma once

#include "Population.h"
#include "Route.h"
#include "City.h"
#include <iostream>


class Population;

class Graph 
{
  protected:
    std::string nameFile;
    
  public:
    Graph(std::string nameFile) 
    {
      this->nameFile = nameFile;
    }

    virtual ~Graph() {};
    virtual void AddInfoFile(Population *) const = 0;
};


class GraphMax: public Graph 
{
  public:
    GraphMax(std::string nameFile): Graph(nameFile) {}

    void AddInfoFile(Population *) const override;
};


class GraphMin: public Graph 
{
  public:
    GraphMin(std::string nameFile): Graph(nameFile) {}

    void AddInfoFile(Population *) const override;
};


class GraphProm: public Graph 
{
  public:
    GraphProm(std::string nameFile): Graph(nameFile) {}

    void AddInfoFile(Population *) const override;
};


class GraphBestRoute: public Graph 
{
  public:
    GraphBestRoute(std::string nameFile): Graph(nameFile) {}

    void AddInfoFile(Population *) const override;
};
