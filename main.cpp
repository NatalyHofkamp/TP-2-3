#include "Ruta.h"
int main(void){
    Rute* ruta= new Rute();
    ruta->AddCity(0,1);
    ruta->AddCity(1,0);
    ruta->AddCity(2,1);
    ruta->AddCity(13,0);
    ruta->AddCity(0,1);
    cout<<ruta->TotalDist()<<endl;
    ruta->empty();
    delete ruta;
}