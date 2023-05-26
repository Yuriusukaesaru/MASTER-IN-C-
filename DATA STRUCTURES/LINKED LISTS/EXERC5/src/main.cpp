#include <iostream>
#include <string>
#include <stdlib.h>
#include "Person.hpp"

int main(void)
{
    Person_list test;

    test.get_all();
    test.add_end("GUILLERMO PEREZ MERCADO", "12355421231", "ELECTRONICA", 17);
    test.get_all();
    test.add_front("ROSA MELCOCHO HERNANDEZ HUERTA", "144664448944", "SISTEMAS", 18);
    test.get_all();
    test.add_end("SANTA CATARINA REBOZO LINDO" , "u38177etD6", "CONTADURIA PUBLICA", 19);
    test.add_end("ANUBIZ CHILANGO CINEPOLIS VILLAGRAN", "84ubAAAS2", "QUIMICA", 20);
    test.add_front("GINEBRIZ CULONA MAMACITA ","T2636SZSAD7D7", "COMERCIO", 21);
    test.get_all();
    test.add_front("ENRIQUE SEGOVIANO CHAVO " , "17765FDD4SS", "GASTRONOMIA", 20);
    test.add_front("GUADALUPE MALDONADO DE LOS ALCAZAR" , "1234FFDGYSS", "ARQUITECTURA", 21);
    test.add_front("NORMA ANGELICA MALDONADO" , "1654HFD67S", "ARTE", 22);
    test.add_front("LUPITA DOLORES PADERNA DEL RIOS" , "123444DDASS", "GASTRONOMIA", 20);
    

}