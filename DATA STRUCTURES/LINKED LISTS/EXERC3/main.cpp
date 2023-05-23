//
//
//  Created by Yuriusukaesaru on 5/21/2023
//  Copyright © 2023 Yuriusukaearu, All rights reserved.
//
//

#include <iostream>
#include <stdlib.h>

class Node
{
    private: 
        int data;
        Node *next;
        friend class Linked_list;
};

class Linked_list
{
    public:
        Linked_list();
        ~Linked_list();
        void add_front(const int &);
        void remove_front();
        int get_front()const;
        void get_all()const;
    private:
        Node *head;
};

Linked_list::Linked_list()
{
    head = nullptr;
}

void Linked_list::add_front(const int &_data)
{
    Node *pnt = new Node;
    pnt->next = head;
    pnt->data = _data;
    head = pnt;
}

void Linked_list::remove_front()
{
    Node *pnt = head->next;
    delete head;
    head = pnt;
}

int Linked_list::get_front() const
{
    return head->data;
}

Linked_list::~Linked_list()
{
    while(head != nullptr)
    {
    remove_front();
    }
}

void Linked_list::get_all()const
{
    Node *current = head;
    
    std::cout << "\nDISPLAYING DATA: " << std::endl;

    while(current!=nullptr)
    {
        std::cout << current->data << " ";
        current = current -> next;
    }
}

int main( void )
{

    Linked_list test;
    int data = 1;
    test.add_front( data  ); //adding 1
    test.get_all( ); // 1
    test.add_front( 2 ); // 2,1
    test.add_front( 3 );// 3,2,1
    test.add_front( 4 );// 4,3,2,1
    test.get_all( ); //get all
    test.remove_front( ); //delete
    test.get_all( ); // 3,2,1
    test.remove_front( ); //delete
    test.get_all( ); //2,1
    test.remove_front( ); //delete
    test.get_all( ); // 1

}
