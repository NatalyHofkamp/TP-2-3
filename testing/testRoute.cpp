#include "../testing/testHeader.h"

void testRute(void) {
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

    std::cout<<"[ROUTE TESTING]=OK"<<std::endl;
    delete city1;
    delete city3;
    delete city4;
    delete city2;
    delete ruta;
    
}