#include <iostream>
#include <vector>
#include <array>
#include <iomanip>
/*
typedef struct 
{
    std::array<int, 7> Dias;
}Dias;


void Agregar_Valores()
{

} 

/*void Desplegar_Valores( std::vector< Dias > &_semana)
{
   
    std::cout << "VENTAS DE 4 SEMANAS " << '\n';
    std::cout << "-------------------------------" << '\n';

    for( auto &_Dias : _semana )
    {
        for( int valor : _Dias.Dias)
        {
            std::cout << valor << '\n';
        }

        std::cout << '\n';
    }
        
}

void Desplegar_Valores(const std::vector<Dias>& _semana)
{
    std::cout << "VENTAS DE 4 SEMANAS" << '\n';
    std::cout << "-------------------------------" << '\n';

    for (int i = 0; i < _semana.size(); ++i)
    {
        for (int j = 0; j < _semana[i].Dias.size(); ++j)
        {
            std::cout << std::setw(4) << _semana[j].Dias[i];
        }

        std::cout << '\n';
    }
}

int main( void )
{
    std::vector < Dias > Semana;

    Semana.push_back({1,2,3,4,5,6,7});
    Semana.push_back({8,9,10,11,12,13,14});
    Semana.push_back({15,16,17,18,19,20,21});

    Desplegar_Valores( Semana );
}*/

#include <iostream>
#include <iomanip>
#include <vector>

const int NUM_WEEKS = 4;
const int NUM_DAYS = 7;

void calculateSales(const std::vector<std::vector<double>>& sales, std::vector<double>& weeklyTotal, double& monthlyTotal)
{
    for (int week = 0; week < NUM_WEEKS; ++week)
    {
        double weekTotal = 0.0;

        for (int day = 0; day < NUM_DAYS; ++day)
        {
            weekTotal += sales[day][week];
        }

        weeklyTotal[week] = weekTotal;
        monthlyTotal += weekTotal;
    }
}

void displaySales(const std::vector<std::vector<double>>& sales, const std::vector<double>& weeklyTotal, double monthlyTotal)
{
    std::cout << "Sales:" << '\n';

    std::cout << std::setw(6) << "WEEK1" << std::setw(8) << "WEEK2" << std::setw(8) << "WEEK3" << std::setw(8) << "WEEK4" << '\n';

    for (int day = 0; day < NUM_DAYS; ++day)
    {
        const char* dayOfWeek = "";

        switch (day)
        {
            case 0:
                dayOfWeek = "(M)";
                break;
            case 1:
                dayOfWeek = "(T)";
                break;
            case 2:
                dayOfWeek = "(W)";
                break;
            case 3:
                dayOfWeek = "(TH)";
                break;
            case 4:
                dayOfWeek = "(F)";
                break;
            case 5:
                dayOfWeek = "(SA)";
                break;
            case 6:
                dayOfWeek = "(S)";
                break;
        }

        std::cout << std::setw(4) << dayOfWeek;

        for (int week = 0; week < NUM_WEEKS; ++week)
        {
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) << sales[day][week];
        }

        std::cout << '\n';
    }

    std::cout << "----------------------------------------" << '\n';
    std::cout << std::setw(4) << "TOTAL";

    for (int week = 0; week < NUM_WEEKS; ++week)
    {
        std::cout << std::setw(8) << std::fixed << std::setprecision(2) << weeklyTotal[week];
    }

    std::cout << '\n';
    std::cout << std::setw(10) << "TOTAL SALE MONTH: " << std::fixed << std::setprecision(2) << monthlyTotal << '\n';
}

int main()
{
    std::vector<std::vector<double>> sales = {
        {123.50, 234.60, 345.45, 321.40},
        {345.00, 334.56, 642.55, 231.43},
        {234.65, 543.21, 643.45, 456.90},
        {344.47, 464.52, 848.58, 273.53},
        {442.53, 664.55, 466.52, 334.61},
        {345.67, 534.62, 424.63, 256.67},
        {643.71, 667.62, 424.66, 535.77}
    };

    std::vector<double> weeklyTotal(NUM_WEEKS, 0.0);
    double monthlyTotal = 0.0;

    calculateSales(sales, weeklyTotal, monthlyTotal);
    displaySales(sales, weeklyTotal, monthlyTotal);

    return 0;
}
