#include "head.hpp"

int List::get( int index )
{
    //verifica si el indice esta fuera de rango
    if (index < 0 || index > m_cout)
        return -1;
    return m_iteams[ index ];    
}

void List::insert( int index, int val)
{
    //verifica si el indice esta fuera de rango
   // if (index < 0 || index > m_cout)
    //return;
    //copia el actual array
    int *old_array = m_iteams;

    //incrementa el tamaño del array
    ++m_cout;

    //inicializa el nuevo array
    m_iteams = new int [ m_cout ];

    for ( int i = 0 , j = 0; i < m_cout ; ++i)
    {
        if (index  == i)
        {
            m_iteams[ i ] = val;
        }
        else 
        {
            m_iteams[ i ] = old_array[ j ];
            ++j;
        }
    }
    // ELIMITAMOS LA COPIA DEL ARRAY
    delete [] old_array;
}

int List::search( int val )
{
    for ( int i = 0; i < m_cout ; ++i)
    {
        if ( m_iteams[ i ] == val)
        {
            return i;
        }
    }
    return -1;
}

void List::remove( int index)
{
    //verifica si el indice esta fuera de rango
    if (index < 0 || index > m_cout)
    return;

    int *old_array = m_iteams;

    //disminuye el rango del array
    --m_cout;

    //inicializa un nuevo array
    m_iteams = new int [ m_cout ];

    //rellena el nuevo array
    for( int i = 0, j = 0; i < m_cout; ++i, ++j)
    {
        if (index == j)
        {
            ++j;
        }

        m_iteams[ i ] = old_array[ j ];
    }

        //elimina la viaja copia
    delete [] old_array;

}

int List::get_count()const
{
    return m_cout;
}

