#include "../src/City.cpp"
#include "../src/Graph.cpp"
#include "../src/Parser.cpp"
#include "../src/Population.cpp"
#include "../src/Reader.cpp"
#include "../src/Route.cpp"
#include "../src/Start.cpp"
#include <assert.h>

void testCity(){
    City *city = new City(0,1);
    City *city2 = new City(0,1);
    assert(city->DistCalc(city2) == 0);
    
}

void testRute() {
    Route* ruta= new Route();
    City* city1= new City(0,3);
    City* city2 = new City(4,0);
    ruta->AddCity(city1);
    ruta->AddCity(city2);
    assert(ruta->TotalDist() == 10);
    assert(ruta->GetSize() == 2);
    assert(ruta->HasCity(new City(45,6)) == false);
    assert(ruta->HasCity(city1) == true);
    City* city3= new City(1,0);
    City* city4 = new City(0,0);
    ruta->AddCity(city3);
    ruta->AddCity(city4);
    assert(ruta->TotalDist() == 12);
    assert(ruta->GetSize() == 4);
    assert(ruta->HasCity(new City(25,6)) == false);
    assert(ruta->HasCity(city4) == true);
}
int main(void){
    testCity();
    testRute();
}