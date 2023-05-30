//
//
//  Created by Yuriusukaesaru on 5/29/2023
//  Copyright © 2023 Yuriusukaearu, All rights reserved.
//
//

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

void Person_list::add_front(std::string _name, std::string _ID, std::string _major, int _age)
{
    Person *pnt = new Person;
    pnt->next = head;
    pnt->name = _name;
    pnt->ID = _ID;
    pnt->major = _major;
    pnt->age = _age;

    if (head == nullptr)
    {
        tail = pnt; // Update tail if the list was empty
    }

    head = pnt;
}

void Person_list::remove_front()
{
    if (head == nullptr)
    {
        std::cout << "THE LIST IS EMPTY, WE CANNOT DELETE ANY INFORMATION\n";
        return;
    }

    Person *pnt = head->next;
    delete head;
    head = pnt;

    if (head == nullptr)
    {
        tail = nullptr; // Update tail if the list is now empty
    }
}

void Person_list::add_end(std::string _name, std::string _ID, std::string _major, int _age)
{
    Person *pnt = new Person;
    pnt->next = nullptr;
    pnt->name = _name;
    pnt->ID = _ID;
    pnt->major = _major;
    pnt->age = _age;

    if (head == nullptr)
    {
        head = pnt;
        tail = pnt; // Update tail if the list was empty
    }
    else
    {
        tail->next = pnt;
        tail = pnt; // Update tail to the new last element
    }
}

void Person_list::remove_last()
{
    if (head == nullptr)
    {
        std::cout << "THE LIST IS EMPTY, WE CANNOT DELETE ANY INFORMATION\n";
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr; // Update tail if the list becomes empty
        return;
    }

    Person *current = head;
    while (current->next != tail)
    {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;
}

void Person_list::add_at(std::string _name, std::string _ID, std::string _major, int _age, int _pos)
{
    Person *pnt = new Person;
    Person *current = head;

    pnt->name = _name;
    pnt->ID = _ID;
    pnt->major = _major;
    pnt->age = _age;
    pnt->next = nullptr;

    if (_pos < 0)
    {
        std::cout << "\nINVALID POSITION";
        delete pnt;
        return;
    }

    switch (_pos)
    {
        case 0:
            add_front(_name, _ID, _major, _age);
            break;
        default:
            int i = 0;
            while (current != nullptr && i < _pos - 1)
            {
                current = current->next;
                ++i;
            }
            if (current == nullptr)   //this means the position is not in the list
            {
                std::cout << "INVALID POSITION, ELEMENT NOT FOUND" << '\n';
                delete pnt;
                return;
            }
            pnt->next = current->next;
            current->next = pnt;
            if (pnt->next == nullptr)
            {
                tail = pnt; // Update tail if the element is inserted at the end
            }
            break;
    }
}

void Person_list::remove_at(int _position)
{
    if (_position < 0)
    {
        std::cout << "INVALID POSITION" << '\n';
        return;
    }

    switch (_position)
    {
        case 0:
            remove_front();
            break;
        default:
            Person *current = head;
            Person *previous = nullptr;
            int i = 0;
            while (current != nullptr && i < _position)
            {
                previous = current;
                current = current->next;
                ++i;
            }
            if (current == nullptr) //this means the position is not in the list
            {                       //the list has fewer elemets 
                std::cout << "INVALID POSITION, ELEMENT NOT FOUND" << '\n';
                return;
            }
            previous->next = current->next;
            if (current == tail)
            {
                tail = previous; // Update tail if the last element is removed
            }
            delete current;
            break;
    }
}
  
void Person_list::get_first()const
{
    if (head != nullptr)
    {
        std::cout << "NAME:  " << head->name << '\n'
                  << "MAJOR:  " << head->major << '\n'
                  << "ID: " << head->ID << '\n'
                  << "AGE:  " << head->age << '\n';
    }
    else
    {
        std::cout << "THE LIST IS EMPTY\n";
    }
}

void Person_list::get_last()const
{
    if (tail != nullptr)
    {
        std::cout << "NAME:  " << tail->name << '\n'
                  << "MAJOR:  " << tail->major << '\n'
                  << "ID: " << tail->ID << '\n'
                  << "AGE:  " << tail->age << '\n';
    }
    else
    {
        std::cout << "THE LIST IS EMPTY\n";
    }
}

void Person_list::get_all()const
{
    Person *current = head;
    if (current == nullptr){
        std::cout << "THE LIST IS EMPTY WE CANNOT DISPLAY ANYTHING" << '\n';
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

