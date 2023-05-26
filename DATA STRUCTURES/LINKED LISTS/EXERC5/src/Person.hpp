#ifndef _Person_
#define _Person_

#include <iostream>
#include <string>

class Person
{
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
        void add_front( std::string, std::string, std::string, int  );
        void add_end( std::string, std::string, std::string, int );
        void remove_front();
        void remove_last();
        void get_all();
    private:
       Person *head;
};


#endif