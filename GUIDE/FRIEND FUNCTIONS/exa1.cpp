//Note that we have to pass an Accumulator object to reset(). 
//This is because reset() is not a member function. 
//It does not have a *this pointer, nor does it have an Accumulator object to work with,
// unless given one.

#include<iostream>
 
class Accumulator
{

    public: 
        void add_value(int _value){ value += _value;};
        int get_value()const{ return value;}

    private:
        int value = 0;
        friend void reset_function(Accumulator &);
};

void reset_function(Accumulator &_obj)
{
    _obj.value = 0;
}

int main()
{
    Accumulator obj;

    obj.add_value( 5 );
    std::cout << obj.get_value();
    reset_function( obj );
    std::cout << obj.get_value();

    return 0;
}