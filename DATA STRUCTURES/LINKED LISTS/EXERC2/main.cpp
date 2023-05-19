
#include <iostream>
#include <stdlib.h>

class Node
{
    public:
        int data;
        Node *next;
};

void print_Node(Node *node)
{
    //IMPRIMIRA EL NODO INICIAL
    //HASTA QUE SE ENCUENTRE NULL EN EL PUNTERO NEXT
    //LO CUAL INDICA EL FINAL DE LA CADENA NODOS

    while (node != NULL)
    {
        std::cout << node->data << "->" ; //SE IMPRIME EL DATO ALMACENADO EN EL NODO
        node = node -> next ; //SE ASIGNA LA DIRECCION DEL NUEVO NODO
    }

    std::cout << "NULL"; //CUANDO ENCUENTRA EL NULL SIMPLEMENTE LO IMPRIME
}                       //INDICANDO QUE ES EL FIN DE LA CADENA NODO
int main( void )
{
    // 7 /NULL
    Node *node1 = new Node;
    node1->data = 7;

    // 14/NULL
    Node *node2 = new Node;
    node2->data = 14;

    // 21/NULL
    Node *node3 = new Node;
    node3->data = 21;

    // 7 -> 14
    node1->next = node2; //ASIGNAMOS LA DIRECCION DE NODO 2 NE AL PUNTERO NEXT 1

    // 14 ->21
    node2->next = node3; //ASIGNAMOS LA DIRECCION DE NODO 3 NEXT AL PUNTERO NEXT 2

    node3->next = NULL; //AQUI CURIOSAMENTE EL PUNTERO NEXT NO SE INICIALIZA
                        //EN AUTOMATICA A NULL COMO DICE LA TEORIA
                        //AQUI ES UNA BUENA PRACTICA INICIALIZARLO EXPLICITAMENTE

    print_Node(node1); //SE IMPRIME TODOS LOS DATOS, SOLO LE PASAMOS LA DIRECCION
                        //DEL PRIMER NODO
}

/*
class Node
{
    public:
        int data;
        Node *next;
};

int main()
{
  Node *node1 = new Node;
    node1->data = 7;  
}
*/