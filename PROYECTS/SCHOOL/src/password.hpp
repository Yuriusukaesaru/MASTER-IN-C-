#include <iostream>
#include <conio.h>
#include <string>
#include "head.hpp"

//template<typename T, typename J>
bool Password(std::string &_user , std::string &_password) 
{
    int const max_data { 6 };
    std::string password;
    //std::string contra { "1234" }; 
    char ch;
    //char user[ max_data ]{ "ADMIN" };
    //char username[ max_data ];
    std::string user;
    int count { 0 };

    std::cout << "Username: ";
    //fgets( username, max_data, stdin );
    std::cin>>user;
    std::cin.ignore( );
    std::cout << "Password: ";
    
    while ( (ch = _getch() ) != '\r' )  // Read characters until Enter key is pressed
    {   
        if ( ch == '\b' ) { // Handle backspace
            if ( count > 0 ) {
                --count; // Decrease password length
                password.pop_back(); // Remove the last character
                std::cout << "\b \b"; // Clear the displayed asterisk
            }
        } else if ( count < max_data ) {
            password.push_back( ch ); // Add character to password
            std::cout << '*'; // Display asterisk
            ++count; // Increase password length
        }
    }

    if(  _user == user && _password == password )
    {
        return true;
    }
    return false;
}