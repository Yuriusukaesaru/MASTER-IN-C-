#include <iostream>
#include "head.hpp"

// Define the friend function specialization for Employees
template <>
void AddPerson<Employees>(Employees& obj)
{
    std::cout << "INPUT THE USER: ";
    std::cin >> obj.user;
    std::cout << "INPUT PASSWORD: ";
    std::cin >> obj.password;
}

// Define the friend function specialization for Students
template <>
void AddPerson<Students>(Students& obj)
{
    std::cout << "INPUT THE USER: ";
    std::cin >> obj.user;
    std::cout << "INPUT PASSWORD: ";
    std::cin >> obj.password;
}
