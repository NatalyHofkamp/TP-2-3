#include "Rute.h"


#include <iostream>

void testCity(){
    City *city = new City(0,1);
    City *city2 = new City(0,1);
    assert(city->DistCalc(city2) == 0);
    
}

void testRute() {
    Rute* ruta= new Rute();
    ruta->AddCity(0,1);
    ruta->AddCity(1,0);
    ruta->AddCity(2,1);
    ruta->AddCity(13,0);
    ruta->AddCity(0,4);
    cout<<ruta->TotalDist()<<endl;
    ruta->Empty();
    assert(ruta->TotalDist() == 0);

    ruta->PrintCities();

    delete ruta;
}

int main(void){
    testCity();
    testRute();

    return 0;
}