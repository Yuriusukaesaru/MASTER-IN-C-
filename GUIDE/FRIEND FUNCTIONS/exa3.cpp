#include <iostream>

class Humidity; //Class prototype

class Tempeture{

    public: 
        Tempeture( int _tempeture) : tempeture ( _tempeture) {}
    private:
        int tempeture{};
        friend void print_weather( Tempeture &, Humidity &);
};

class Humidity{
    
    public:
        Humidity( int _humidity) : humidity (_humidity) {}

    private:
        int humidity{};
        friend void print_weather( Tempeture &, Humidity &);
};

void print_weather( Tempeture &_obj1, Humidity &_obj2)
{
    std::cout << "THE TEMPETURE IS : " << _obj1.tempeture << '\n' 
              << "THE HUMIDITY IS : " << _obj2.humidity ;
}

int main( void )
{
    Tempeture obj1( 10);
    Humidity obj2( 20 );

    print_weather( obj1 , obj2 );

}