#include<iostream>

int main( void )
{
    int counter = 0;
    
    while(counter < 1000000000)
    {
        ++counter;
    } 

    std::cout << counter;
}