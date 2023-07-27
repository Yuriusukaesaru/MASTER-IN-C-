//
//
//  Created by Yuriusukaesaru on 5/29/2023
//  Copyright © 2023 Yuriusukaearu, All rights reserved.
//
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Person.hpp"

int main(void)
{
    Person_list test;

    std::cout << "DISPLAYING ALL ELEMENTS IN THE LIST" <<'\n';
    test.add_end("GUILLERMO PEREZ MERCADO", "12355421231", "ELECTRONICA", 17);
    test.add_front("ROSA LEONOR HERNANDEZ HUERTA", "144664448944", "SISTEMAS", 18);
    test.add_end("SANTA CATARINA GOMEZ LINDO" , "u38177etD6", "CONTADURIA PUBLICA", 19);
    test.add_end("ANUBIZ CHILANGO CINEPOLIS VILLAGRAN", "84ubAAAS2", "QUIMICA", 20);
    test.add_front("GINEBRIZ LOPEZ MATRINEZ ","T2636SZSAD7D7", "COMERCIO", 21);
    test.add_front("ENRIQUE SEGOVIANO CHAVO " , "17765FDD4SS", "GASTRONOMIA", 20);
    test.add_front("GUADALUPE MALDONADO DE LOS ALCAZAR" , "1234FFDGYSS", "ARQUITECTURA", 21);
    test.add_front("NORMA ANGELICA MALDONADO" , "1654HFD67S", "ARTE", 22);
    test.add_front("LUPITA DOLORES PADERNA DEL RIOS" , "123444DDASS", "GASTRONOMIA", 20);
    test.add_at("TOMAS HOWLETTE BONES JONES", "BHHJB8873HD", "DERECHO", 19 , 1);
    test.get_all();
    test.remove_at(3);
    std::cout << "\nREMOVING\n"
              << "DISPLAYING ALL ELEMENTS IN THE CURRENT LIST" <<'\n';
    test.get_all();
    std::cout << "\nGETTING THE FIRST ELEMENT (HEAD)" << '\n';
    test.get_first();
    std::cout << "\nGETTING THE LAST ELEMENT OF THE LIST (TAIL)" << '\n';
    test.get_last(); 

}