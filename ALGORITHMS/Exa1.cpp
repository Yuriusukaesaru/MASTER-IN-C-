/*THIS CODE CONSITS IN USING A UNIDIMENSIONAL ARRAY TO SOLVE THE NEXT PROBLEM
A COMPANY PAYS ITS EMPLOYS BY COMMISION. THE SELLERS GET $200 A WEEK MORE 9%
OF THEIR TOTAL SELLS OF THAT WEEK. FOR INSTANCE A SELLER WHO ACUMULATES 
$5000 IN SELLS, WILL GET $200 PLUS 9% OF 5000 BEING IN TOTAL $650.
CODE A PROGRAM (USING A COUNTER ARRAY) TO DETERMINE HOW MANY SELLERS
GOT SALARY IN THE NEXT RANGES:

                200-299
                300-399
                400-499
                    .
                    .
                    .
            1000 - OR MORE */

#include <iostream>
#include <array>

    //     POSITION ARRAY 
        // 0  - 99 POSITION 0  - 1
        // 100 - 199 POSITION 1  - 2
        // 200 - 299 POSITION 2  - 3
        // 300 - 399 POSITION 3  - 4
        // 400 - 499 POSITION 4  - 5
        // 500 - 599 POSITION 5  - 6     //ARRAY RANGE
        // 600 - 699 POSITION 6  - 7
        // 700 - 799 POSITION 7  - 8
        // 800 - 899 POSITION 8  - 9
        // 900 - 999 POSITION 9  - 10
        // 1000 OR MORE POSITION 10 - 11

const size_t range_commissiooooooooooon { 11 };

void sells (std:: array <int, range_commission> &);
void display_employes( std::array <int, range_commission> &);

int main(void)
{
    
    std::array < int , range_commission> salaries {}; 

    sells (salaries);
    display_employes(salaries);

}

void sells ( std::array <int,range_commission> &_employ)
{

    double sales_amount { 0 },  salary { 0 };
    
    std::cout << "INPUT THE COMMISSION OR -1 TO EXIT" ; //sentinel
    std::cin >> sales_amount;
    

    while (sales_amount != -1)
    {
        salary = 200.00 + sales_amount * .09;
        std::cout << "\nTHE SALARY IS: " << salary <<'\n';
        int x = static_cast< int >(salary) / 100; 
        ++_employ [ ( x < 10 ? x : 10) ]; 
        std::cout << "INPUT THE COMMISSION OR -1 TO EXIT" ;
        std::cin >> sales_amount;
    }


}

void display_employes(std::array<int, range_commission> &_display)
{

    std::cout << "FREQUENCY" << std::endl;

    for (int i = 2 ; i < 10 ; ++i) //PRINT FROM THE THIRD ELEMENT IN THE ARRAY
    {
        std::cout << " $" << i << "00" << '-' 
                  << i << "99 :" << _display[ i ]<< std::endl;
    }
    std::cout << "MORE THAN 1000: " << _display[ 10 ] <<std::endl;
        
}