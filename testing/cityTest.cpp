#include "../testing/testHeader.h"

void testCity(void){
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
