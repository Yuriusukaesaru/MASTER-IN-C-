/*UNA LISTA  ADT (Abstract Data Type) 
se refiere al Tipo de Datos Abstracto que representa una colección
de elementos en un orden específico. Proporciona operaciones y 
comportamientos para gestionar y manipular los elementos dentro de
la lista. El List ADT permite el redimensionamiento dinámico, la inserción,
eliminación, acceso a elementos por índice, búsqueda de elementos y
otras operaciones comunes de lista. Proporciona una interfaz de nivel superior
para trabajar con listas, abstrayendo los detalles de implementación subyacentes
y permitiendo a los usuarios interactuar con listas utilizando un conjunto de
operaciones y reglas definidas.

ES UN CONJUNTO DE ELEMENTOS CON SIMILARES TIPOS DE DATOS
DONDE EL ORDEN DE LOS ELEMENTOS IMPORTAN. HAY VARIAS OPERACIONES
EN LAS LISTAS

-Get(i), que devolverá el valor del índice seleccionado, i.
Si el índice i está fuera de los límites, simplemente devolverá -1

- Insert(i, v), que insertará el valor v en la posición del índice i.

-Search(v), que devolverá el índice de la primera aparición de v 
(si el valor v no existe, el valor de retorno será -1).

-Remove(i), que eliminará el elemento en el índice i.


NECESITAMOS 2 VARIABLES PARA ALMACENAR LA LISTA DE ELEMENTOS (m_items)
Y EL NUMERO DE ELEMENTOS EN LA LISTA(m_cout). LAS HAREMOS PRIVADAS PARA
QUE NO PUEDAN SER ACCEDIDAS  DESDE FUERA DE LA CLASE. LAS CUATRO 
OPERACIONES ANTERIORES  SE IMPLEMENTARAN  EN ESTA CLASE. ADEMAS, NECESITAMOS
UN METODO QUE NOS IMPORTA CONOCER EL NUMERO
DE ELEMENTOS QUE TIENE LA CLASE List, EL CUAL SELLAMARA get_cout() */

#ifndef LIST_H
#define LIST_H

#include  <iostream>
#include  <stdlib.h>

class List
{
    public:
        int get(int index);
        void insert(int index, int val);
        int search(int val);
        void remove(int index);
        int get_count()const;
        
        
    private:
        int m_cout;
        int *m_iteams;
       
};

#endif //LIST_H


