#include <iostream>

class Storage
{
    public:
        Storage(int nValue, double dValue) : m_nvalue( nValue) , m_dvalue(dValue) {} 
    private:
    int m_nvalue{};
    double m_dvalue{};
    friend class Display;
};

class Display
{
    public:
        Display(bool displayIntFirst) : m_displayIntFirst( displayIntFirst ){}

        void DisplayIteam( const Storage &storage)
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
        
    private:
        bool m_displayIntFirst;
};

int main(void)
{

    Storage storage{1,5.7};
    Display display{ true };

    display.DisplayIteam( storage );


}


