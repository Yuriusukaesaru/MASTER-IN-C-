#ifndef _people_
#define _people_
#include <iostream>
#include <string>
#include <array>
#include <vector>

template<typename T>
void AddPerson( T &obj );

class Person
{
	public:
		

		void SetName( std::string _name )
		{
			name = _name;
		}

		void SetLastName( std::string _lastname )
		{
			lastname = _lastname;
		}

		void SetGender( std::string _gender )
		{
			gender = _gender;
		}

		void SetWeight( double _weight )
		{
			weight = _weight;
		}

		void SetHeight( double _height )
		{
			height = _height;
		}

		void SetAge( int _age )
		{
			age = _age;
		}

		std::string GetName( )const
		{
			return name;
		}

		std::string GetLastName( )const
		{
			return lastname;
		}

		std::string GetGender( )const
		{
			return gender;
		}

		double GetWeight( )const
		{
			return weight;
		}

		double GetHeight( )const
		{
			return height;
		}

		int GetAge( )const
		{
			return age;
		}

		void PersonInfo( );
		
	protected:
		std::string name;
		std::string lastname;
		std::string gender;
		double weight, height;
		int age;

};

class Bachelor
{
	public:
		void SetBachelor( std::string _bachelor )
		{
			bachelor = _bachelor;
		}

		std::string GetBachelor( )const
		{
			return bachelor;
		}

	private:
		std::string bachelor;
};

class Area
{
	public:
		void SetEmployeeArea( std::string _area_employee )
		{
			area_employee = _area_employee;
		}

		std::string GetEmployeeArea( )const
		{
			return area_employee;
		}

	private:
		std::string area_employee;

};

class Employees: public Person, public Area
{
	public:
		void CheckIn( int _check_in )
		{
			check_in = _check_in;
		}

		void CheckOut( int _check_out )
		{
			check_out = _check_out;
		}

		
		//friend void CalculateTotal( );
		friend void AddPerson <Employees> ( Employees & ); 
	private:
		std::string password, user;
		int check_in , check_out;
		//double wage; <----- reserved for the CalculateTotal;
};

class Students: public Person , public Bachelor
{
	public: 
		struct Subjects
		{
			std::array<std::string, 6 > _subjects;
		};

		void SetShift( std::string _shift )
		{
			shift = _shift;
		}

		void SetSemester( int _semester )
		{
			semester = _semester;
		}

		std::string GetShift( )const
		{
			return shift;
		}

		int GetSemester( )const
		{
			return semester;
		}

		friend void AddPerson <Students> ( Students & ); 

	private: 
		std::string shift;
		std::string password;
		std::string user;
		std::vector<Subjects> record;
		int semester;
}; 	


#endif