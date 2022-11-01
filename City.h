#include <iostream>
#ifndef CITY_H

using namespace std;

class City
{
  private:
    double x;
    double y;
  public:
    City(double x,double y){
        this->x=x;
        this->y=y;
    }
    ~City(){
      cout<<"~City()"<<endl;
    }
    double DistCalc(City* ciudad2);
    void Print() const;
    double GetX() const;
    double GetY() const;
};

#endif 