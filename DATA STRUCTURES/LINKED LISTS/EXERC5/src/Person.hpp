//
//
//  Created by Yuriusukaesaru on 5/29/2023
//  Copyright © 2023 Yuriusukaearu, All rights reserved.
//
//

#ifndef _Person_
#define _Person_

#include <iostream>
#include <string>

class Person
{
    public:
        Person () {
            name = "";
            ID = "";
            major = "";
            age = 0;
            next = nullptr;
        }
    private:
        std::string name, ID, major;
        int age;
        Person *next;
        friend class Person_list;

};

class Person_list
{
public:
    Person_list();
    ~Person_list();
    void add_front(std::string, std::string, std::string, int);
    void add_end(std::string, std::string, std::string, int);
    void add_at(std::string, std::string, std::string, int, int);
    void remove_at( int );
    void remove_front();
    void remove_last();
    void get_first()const;
    void get_last()const;
    void get_all()const;

private:
    Person *head, *tail;
};


#endif