//EN ESTE EJERCICIO HAREMOS USO DE UN ARRAY DINAMICO
// new: RESERVA EL NUMERO DE BYTES SOLICITADOS POR LA DECLARACION
//delate: LIBERA UN BLOQUE DE BYTES RESERVADO CON ANTERIORIDAD

//EJEMPLO PEDIR AL USUARIO n CALIFICACIONES  Y ALMACENARLO 
//EN UN ARREGLO DINAMICO

#include <iostream>
#include <stdlib.h>


int main(void)
{
    int num_calif, *calif;
    std::cout << "INGRESE EL NUMERO DE CALIFICACIONES: ";
    std::cin>>num_calif;

    //CREAMOS UN ARRAY TIPO PUNTERO *calif QUE ALMACENA n CALIFICACIONES
    //RESERVAMOS EL ESPACIO EN BYTES 
    calif = new int [num_calif]; 
    
    for (int i = 0; i < num_calif ; ++i)
    {
        std::cout << "\nINGRESE UNA NOTA: ";
        std::cin >> calif[ i ];
    }

    std::cout << "\nLAS NOTAS SON: ";

    for (int j = 0; j < num_calif ; ++j)
    {
        std::cout <<  calif[ j ] << ' ';
    }

    delete [ ]calif; //ELIMINAMOS EL ESPACIO EN BYTES RESERVADO
}