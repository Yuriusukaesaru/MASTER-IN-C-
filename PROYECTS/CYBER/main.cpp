//
//
//  Created by Yuriusukaesaru on 6/09/2023
//  Copyright © 2023 Yuriusukaearu, All rights reserved.
//
//

#include <iostream>
#include <string>
#include <array>
#include <conio.h> //to use _getch()
#include <cstring> //to use strcmp

const int column{ 2 };
const int rows{ 2 };

typedef struct{
    std::string user_name = "";
    std::string message = "AVAILABLE";
    int available = 0;
}data;

bool change(std::array<std::array<data,column>,rows> &_array );
void change_user(std::array<std::array<data,column>,rows> &_array );
void print(std::array<std::array<data, column>,rows> &_array);
bool password(); 


int main( void )
{
   std::array<std::array<data,column>,rows>_info;
   std::string user;
  
   int x;
   do{
    std::cout << "CYBER PRIME " << '\n';
    std::cout << "INPUT 1 TO HABILITY A PC" << '\n'
             << "INPUT 2 TO DISPONIBILITY OF PC" << '\n'
             << "INPUT 3 CHANGE USERS" << '\n'
             << "DECISION OR ANY KEY TO LEAVE: ";
    std::cin >> x;
    std::cin.ignore();
    switch ( x )
        {
            case 1:
                if (password( ))
                {
                    if( change(_info) ) 
                    std::cout << '\n' << "CHANGED :)"; 
                }else
                {
                    std::cout << '\n' <<" INCORRECT PASSWORD:(";
                }
                std::cin.clear();
                std::cin.sync();
                std::cout << '\n';
            break;
            case 2:
               print(_info);
            break;
            case 3:
                change_user(_info);
            break;
        }
    } while( x > 0 && x < 4);
}

bool change(std::array<std::array<data,column>,rows> &_array )
{
    int x;
    std::string user;
    std::cout << '\n' << "ENTER THE NUMBER OF PC TO HABILITY: ";
    std::cin >> x;
    
    std::cin.ignore();
    int targetRow = (x - 1) / column;  // Calculate the row index based on user input
    int targetCol = (x - 1) % column;  // Calculate the column index based on user input

    if (_array[targetRow][targetCol].available == 0) {
        std::cout << '\n' << "INPUT THE USER'S NAME: ";
        std::getline(std::cin, user);
        _array[targetRow][targetCol].user_name = user;
        _array[targetRow][targetCol].message = "OCCUPIED";
        _array[targetRow][targetCol].available = 1;
        std::cout << "Position [" << targetRow << "][" << targetCol << "] has been assigned to " << user << std::endl;
        return true;
    } else
    {
        std::cout << "Position [" << targetRow << "][" << targetCol << "] is not available." << std::endl;
        return false;
    }
}

void change_user(std::array<std::array<data,column>,rows> &_array )
{
    int x;
    std::string user = "";
    std::cout << '\n' << "ENTER THE NUMBER OF PC TO CHANGE: ";
    std::cin >> x;   
    std::cin.ignore();

    int targetRow = (x - 1) / column;  // Calculate the row index based on user input
    int targetCol = (x - 1) % column;  // Calculate the column index based on user input

    if (_array[targetRow][targetCol].available == 1) {
        _array[targetRow][targetCol].user_name = user;
        _array[targetRow][targetCol].message = "AVAILABLE";
        _array[targetRow][targetCol].available = 0;
        std::cout << "Position [" << targetRow << "][" << targetCol << "] is now available " << user << std::endl;
    } else
    {
        std::cout << "Position [" << targetRow << "][" << targetCol << "] is already available." << std::endl;
    }
}

void print(std::array<std::array<data, column>,rows> &_array)
{
    int k = 0;
    for(int i = 0; i < _array.size(); ++i)
    {
        for( int j = 0; j < column; ++j)
        {
            std::cout << '\t'<< "PC" << k + 1 << ':' << _array[ i ][ j ].message << '\t';
            ++k;
        }
        std::cout << '\n';
    }
    
    k = 0;
    std::cout << "\nUSERS:";
    for(int i = 0; i < rows; ++i)
    {
        for( int j = 0; j < column; ++j)
        {
            std::cout << '\n' << "PC" << k+1 << ':' <<_array[ i ][ j ].user_name;
            ++k;
        }
    }
    std::cout << '\n';
}

bool password() {
    int const max_data{6};
    std::string password;
    std::string contra = "1234"; 
    char ch;
    char user[max_data]{"ADMIN"};
    char username[ max_data ];
    int count = 0;


    std::cout << "Username: ";
    fgets(username, max_data, stdin);
    std::cin.ignore();
    std::cout << "Password: ";
    
    while ((ch = _getch()) != '\r')  // Read characters until Enter key is pressed
    {   
        if (ch == '\b') { // Handle backspace
            if (count > 0) {
                --count; // Decrease password length
                password.pop_back(); // Remove the last character
                std::cout << "\b \b"; // Clear the displayed asterisk
            }
        } else if (count < max_data) {
            password.push_back(ch); // Add character to password
            std::cout << '*'; // Display asterisk
            ++count; // Increase password length
        }
    }
    if(strcmp(user,username)==0 && password == contra)
    {
        return true;
    }
    return false;
}