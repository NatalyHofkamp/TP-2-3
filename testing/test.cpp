#include "../testing/testHeader.h"
#include "cityTest.cpp"
#include "testPopulation.cpp"
#include "testRoute.cpp"

int main(void){
    testRute();
    testCity();
    srand(1);
    testPopulation(new Population(300));
}