#pragma once
#include <iostream>

class City
{
  private:
    double x;
    double y;
  public:
    City(double x,double y)
    {
        this->x=x;
        this->y=y;
    }

    City(City &other) 
    {
        this->x = other.x;
        this->y = other.y;
    }

    ~City()
    {
      std::cout<<"~City()"<<std::endl;
    }

    bool operator==(City &other);
    double DistCalc(City* ciudad2);
    void Print() const;
    double GetX() const;
    double GetY() const;
};
