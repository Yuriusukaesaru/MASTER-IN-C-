#include <iostream>
#include <conio.h>
#include <string>
#include "head.hpp"
#include "password.hpp"

const int limit{ 2 };

int main( )
{
	int cont_student{ 0 } , cont_employee{ 0 };
	std::string admin{"ADMIN"};
	std::string password{"1234"}; 
	std::string newuser, newpassword; 
	Students student[ limit ];
	Employees employee[ limit ];

	int choice;

	do{
		std::cout << "THIS IS THE MENU: " << '\n'
				  << "PRESS 1 FOR STUDENTS " << '\n'
				  << "PRESS 2 FOR WORKERS " << '\n'
				  << "PRESS 3 FOR ADMIN"  << '\n'
				  << "PRESS 4 TO EXIT " << '\n';
		std::cin >>choice;
		std::cin.ignore();

		switch(choice)
		{
		case 1: 
			//Student( );
			break;
		case 2:
			//Employee( );
			break;
		case 3:
			if ( Password( admin, password ) )
			{
				std::cout << " \n 1 -> STUDENT 2 -> WORKERS ";
				std::cin >> choice;
				if ( choice == 1)
				{
					if( cont_student < limit )
					{
						AddPerson( student[ cont_student ] );
					++cont_student;
					}
					else
						std::cout << "LIMIT REACHED " << '\n';
				}else
				{
					if( cont_employee < limit )
					{
					AddPerson( employee[ cont_employee ] );
					++cont_employee;
					}
					else
						std::cout << "LIMIT REACHED " << '\n';

				}
			
			}
			else 
				std::cout << "USER OR PASSWORD INCORRECT" << '\n';
			break;
		default:
			break;
		}

	}while( choice != 4 );
		
	
	
	return 0;
}


