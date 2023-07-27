#include <iostream>

class Storage;

class Display
{
    public:
        Display(bool displayIntFirst) : m_displayIntFirst( displayIntFirst ){}
        void DisplayIteam( const Storage &storage );
    private:
        bool m_displayIntFirst;
};

class Storage
{
    public:
        Storage(int nValue, double dValue) : m_nvalue( nValue) , m_dvalue(dValue) {} 
        friend void Display::DisplayIteam( const Storage &storage);
    private:
    int m_nvalue{};
    double m_dvalue{};
    
};

void Display::DisplayIteam(const Storage &storage)
{
    if ( m_displayIntFirst )
    {
        std::cout << storage.m_nvalue << ' ' << storage.m_dvalue << '\n';
    }
    else
    {
        std::cout << storage.m_dvalue << ' ' << storage.m_nvalue << '\n';
    }
}

int main(void)
{

    Storage storage{1,5.7};
    Display display{ true };

    display.DisplayIteam( storage );


}


