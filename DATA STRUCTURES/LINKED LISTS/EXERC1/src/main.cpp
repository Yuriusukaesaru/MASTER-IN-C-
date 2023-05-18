#include "head.hpp"

int main ( void )
{
    //inicializamos la lista
    List list;

    //list.set_count(10); //Numero de elementos

    //Se agrega elementos a la lista
    list.insert( 0, 21);
    list.insert( 1, 2);
    list.insert( 2, 34);
    list.insert( 3, 91);
    list.insert( 4, 11);
    list.insert( 5, 71);

    //obetener elementos
    std::cout << "LISTA DE ELEMENTOS" <<'\n';
    for ( int i = 0 ; i < list.get_count() ; i++ )
    {
        std::cout << list.get(i) << ' ';
    }
    std::cout << std::endl;

    //insertar varios elementos en la mitad de la lista
    list.insert(3, 25);
    list.insert(2, 71);

    //imprimir la lista de nuevo
    std::cout << "NUEVOS ELEMENTOS" << '\n';
    for (int i = 0; i < list.get_count() ; ++i)
    {
        std::cout << list.get(i) << ' ';
    }
    std::cout << std::endl;

    //buscar el elemento 71
    std::cout << "BUSCANDO EL ELEMENTO 71 " << '\n';

    int result = list.search(71);

    if ( result == -1)
        std::cout << "EL ELEMENTO 71 NO FUE ENCONTRADO :( " << '\n';
    else 
        std::cout << "EL ELEMENTO 71 FUE ENECONTRADO EN INDICE: " << result;
    std::cout << std::endl;

    //quitar un elemento en el indice 2
    std::cout << "QUITANDO EL ELEMENTO EN EL INDICE 2";
    list.remove(2);
    std::cout << std::endl;

    std::cout << "NUEVOS ELEMENTOS" << '\n';
    for (int i = 0; i < list.get_count(); ++i)
    {
        std::cout << list.get(i) << ' ';
    }
    std::cout << std::endl;

    std::cout << "BUSCAR EL ELMENTO 71 DE NUEVO" << '\n';
    result = list.search(71);
    if ( result == -1)
        std::cout << "EL ELEMENTO 71 NO FUE ENCONTRADO :( " << '\n';
    else 
        std::cout << "EL ELEMENTO 71 FUE ENECONTRADO EN INDICE: " << result;
    std::cout << std::endl;

}
