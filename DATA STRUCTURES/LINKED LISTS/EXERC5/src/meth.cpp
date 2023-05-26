#include <iostream>
#include <string>
#include <stdlib.h>
#include "Person.hpp"


Person_list::Person_list()
{
    head = nullptr;
}

Person_list::~Person_list()
{
    while(head != nullptr)
    {
        remove_front();
    }
}

void Person_list::add_front (std::string _name, std::string _ID, std::string _major, int _age)
{
    Person *pnt = new Person;
    pnt->next= head;
    pnt->name = _name;
    pnt->ID = _ID;
    pnt->major = _major;
    pnt->age = _age;
    head = pnt;
}

void Person_list::remove_front()
{
     if (head == nullptr)
    {
        std::cout << "THE LIST IS EMPTY, WE CANNOT DELETE ANY INFORMATION";
    }
    else 
    {
        Person *pnt = head->next;
        delete head;
        head = pnt;
    }
}

void Person_list::add_end( std::string _name, std::string _ID, std::string _major, int _age )
{
    Person *pnt = new Person;
    pnt->next = nullptr;
    Person *current = head;
    pnt->name = _name;
    pnt->ID = _ID;
    pnt->major = _major;
    pnt->age = _age;
    if (head == nullptr)
    {
        head = pnt;
    }else
    {

         while ( current->next != nullptr)
        {
            current = current->next;
        }

    current->next = pnt;
   
    }
}

void Person_list::remove_last()
{
    Person *previous = nullptr;
    Person *current = head;

    if (head == nullptr) //IF THERE'S NO INFORMATION 
    {
        std::cout << "\nTHE LIST IS EMPTY, WE CANNOT DELETE ANY INFORMATION :(";
    }   
    if (head->next == nullptr)   //IF THERE'S ONLY ONE DATA
    {
        delete head;
        head = nullptr;
        return;
    }

    while (current->next != nullptr) //IF WE HAVE MULTIPLE DATA
    {
        previous = current;
        current = current->next;
    }

    previous->next = nullptr;
    delete current;
}

void Person_list::get_all()
{
    Person *current = head;
    if (current == nullptr){
        std::cout << "THE LIST IS EMPTY WE CANNOT DISPLAY ANYTHING" << std::endl;
    }else{
        while (current != nullptr)
        {
        std::cout << "NAME:  " << current->name << '\n'
                  <<"MAJOR:  " << current->major << '\n'
                  <<"ID: " << current->ID <<'\n'
                  <<"AGE:  " << current->age << '\n';
        current = current->next;
        }
        std::cout << '\n' << '\n';
    }
}

