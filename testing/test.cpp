#include "../src/City.cpp"
#include "../src/Graph.cpp"
#include "../src/Parser.cpp"
#include "../src/Population.cpp"
#include "../src/Reader.cpp"
#include "../src/Route.cpp"
#include "../src/Start.cpp"
#include <assert.h>

void testCity(){
    City *city1= new City(0,1);
    City city2(0,1);
    City* city3= new City(0,3);
    City* city4 = new City(4,0);
    assert(city4->DistCalc(city3)==5);
    assert(city1->operator==(city2)== true);
    assert(city1==city4==false);
    assert(city3->GetX()==0);
    assert(city2.GetY()==1);    
    std::cout<<"[CITY TESTING]= OK"<<std::endl;
    delete city1;
    delete city3;
    delete city4;
    
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

    std::cout<<"[ROUTE TESTING]= OK"<<std::endl;
    delete city1;
    delete city3;
    delete city4;
    delete city2;
    delete ruta;
    
}

void testPopulation(Population* p) {
    srand(1);
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

    /*probar que empezamos bien*/
    assert((p->size==300)==true);
    p->CreateRandPop(allCities); 
    /*no se, probar que algo cambió*/
    assert((p->bestRouteEver==ruta)==false);
    p->SetRoutesRanked();
    /*solo para probar que la distancia se calculabien */
    assert(std::get<1>(p->routesRanked[0])==12);
    p->SetLastBestRoute();
    /*probar que empezó en 1?*/
    assert(p->counterGenerations==1);
    selected = p->Selection();
    /*probar que la selección funciona- el mejor (menor distancia) aparece mas de una vez*/
    assert((std::get<1>(selected[0])==std::get<1>(selected[2]))==true);
    p->Reproduction(selected, allCities.size());
    /*que aumentaron las generaciones*/ 
    assert(p->counterGenerations==2);
    p->Mutation(0.02, allCities.size());
    p->SetRoutesRanked();
    /*probar que se ordenaron bien por distancias [menor a mayor]*/
    assert(((std::get<1>(p->routesRanked[0]))<(std::get<1>(p->routesRanked[150])))==true);
    p->ChangeBestRouteEver();
    /*probar que la bestroutever se calcula bien*/
    assert(((p->bestRouteEver)->TotalDist()==(p->routes[std::get<0>(p->routesRanked[0])])->TotalDist())==true);

    std::cout<<"[POPULATION TESTING]=OK"<<std::endl;
    delete ruta;
    for(auto city: allCities){
        delete city;
    }
    delete p;
}

int main(void){
    testCity();
    testRute();
    testPopulation(new Population(300));
}