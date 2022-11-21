#include "../testing/testHeader.h"

int main(void){
    testRute();
    testCity();
    srand(1);
    testPopulation(new Population(300));
}