#include "Ruta.h"
int main(void){
    Ruta* ruta= new Ruta();
    ruta->cargarCiudad(0,1);
    ruta->cargarCiudad(1,0);
    ruta->cargarCiudad(2,1);
    ruta->cargarCiudad(13,0);
    ruta->cargarCiudad(0,1);
    cout<<ruta->DistanciaTotal()<<endl;
    ruta->vaciar();
    delete ruta;
}