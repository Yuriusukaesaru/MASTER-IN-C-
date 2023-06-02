#include <iostream>
#include <array>

    //     POSICION ARRAY 
        // 0  - 99 POSICICION 0  - 1
        // 100 - 199 POSICION 1  - 2
        // 200 - 299 POSICION 2  - 3
        // 300 - 399 POSICION 3  - 4
        // 400 - 499 POSICION 4  - 5
        // 500 - 599 POSICION 5  - 6     //RANGO DEL ARRAY
        // 600 - 699 POSICION 6  - 7
        // 700 - 799 POSICION 7  - 8
        // 800 - 899 POSICION 8  - 9
        // 900 - 999 POSICION 9  - 10
        // 1000 O MAS POSICION 10 - 11

const size_t rango_comision { 11 };

void ventas (std:: array <int, rango_comision> &);
void desplegar_empleados( std::array <int, rango_comision> &);

int main(void)
{
        

    std::array < int , rango_comision > salarios {}; 

    ventas (salarios);
    desplegar_empleados(salarios);


}

void ventas ( std::array <int,rango_comision> &empleado)
{

    double monto_ventas { 0 }, comision { 0 } , salario { 0 };
    
    std::cout << "INGRESE LA CANTIDAD DE COMISION O INTRODUZCA UN -1 PARA SALIR:" ; //sentinela
    std::cin >> monto_ventas;
    

    while (monto_ventas != -1)
    {
        salario = 200.00 + monto_ventas * .09;// ES EL %9 PORCIENTO QUE RECIBAS MAS TU PAGO NORMAL
        std::cout << "\nEL SALARIO DEL EMPLEADO ES: " << salario <<'\n';
        int x = static_cast< int >(salario) / 100; // SE DIVIDE ENTRE 100 EL SALARIO Y SE CONVIERTE A INT
        ++empleado [ ( x < 10 ? x : 10) ]; // AQUI EL COMO EL ARRAY ES DE 0 - 10  (SIZE 11)
                                            //DONDE LA POSICION 10 ES MAYOR O IGUAL A 1000
        std::cout << "INGRESE LA CANTIDAD DE COMISION O INTRODUZCA UN -1 PARA SALIR:" ;
        std::cin >> monto_ventas;
    }


}

void desplegar_empleados(std::array<int, rango_comision> &desplegar)
{

    std::cout << "FRECUENCIA" << std::endl;

    for (int i = 2 ; i < 10 ; ++i) //imprimimos desde la posicion 3 del array 
    {
        std::cout << "DE $" <<i << "00" << '-' 
                  <<i << "99 :" << desplegar[i]<< std::endl;
    }
    std::cout << "DE MAS DE 1000: " << desplegar[10] <<std::endl;
        
}