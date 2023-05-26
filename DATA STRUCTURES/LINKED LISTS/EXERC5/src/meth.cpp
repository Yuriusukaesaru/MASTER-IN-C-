#include <iostream>
#include <string>
#include <stdlib.h>
#include "Person.hpp"


Person_list::Person_list()
{
    head = nullptr;
    head->name = "";
    head->ID = "";
    head->major = "";
    head->age = 0;
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
    if (head == nullptr)
    {
        pnt = head;
        pnt->name = _name;
        pnt->ID = _ID;
        pnt->major = _major;
        pnt->age = _age;
    }

    while ( current->next != nullptr)
    {
        current = current->next;
    }

    current->next = pnt;
    pnt->name = _name;
    pnt->ID = _ID;
    pnt->major = _major;
    pnt->age = _age;
    
}

void Person_list::remove_last()
{
    Person *previous;
    Person *current = head;

    if (head == nullptr) //IF THERE'S NO INFOMATION 
    {
        std::cout << "\nTHE LIST IS EMPTY, WE CANNOT DELETE ANY INFORMATION";
    }   
    else if(head->next == nullptr)   //IF THERE'S ONLY ONE DATA
    {
        delete head;
        head = nullptr;

    }
    else {
    while(current->next != nullptr) //IF WE GOT MULTIPLE DATAS
    {
        previous = current;
        current = current->next;
    }
    }
    previous->next = nullptr;
    delete current;

}

void Person_list::get_all()
{
    Person *current = head;
    while(current->next != nullptr)
    {
        std::cout << current->next << std::endl;
        current = current->next;
    }
}