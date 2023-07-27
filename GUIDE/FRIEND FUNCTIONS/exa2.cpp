#include<iostream>

class Value
{
    public:
        Value( int _value) : value ( _value ) {}
    private:
        int value{};
    friend bool condition_value(Value &, Value &);
};

bool condition_value(Value &_obj1, Value &_obj2)
{
    return (_obj1.value == _obj2.value);
}

int main( void )
{
    Value obj1{5};
    Value obj2{5};

    std::cout << std::boolalpha << condition_value( obj1 , obj2);
}