#include <iostream>
// skipcq: CXX-W2030
#include <locale.h>
#include "Cylinder.h"
#include "Max.h"


int main() {
    // skipcq: CXX-W2022
    std::setlocale(LC_ALL, "");

    std::cout<<"1) wywo�aj szablon funkcji max().\n";
    {
        // skipcq: CXX-C2013
        int a = 5, b = 10;
        // skipcq: CXX-C2013
        double c = 7.5, d = 9.2;

        std::cout << std::max(a, b) << std::endl; // wywo�anie szablonu dla int
        std::cout << std::max(c, d) << std::endl; // wywo�anie szablonu dla double
    }

    std::cout << "\n2) Na jego podstawie zbuduj szablon zwracaj�cy warto�� najwi�ksz� z trzech podanych argument�w.\n";
    {
        // skipcq: CXX-C2013
        int x = 5, y = 10, z = 3;
        // skipcq: CXX-C2013
        double a = 7.5, b = 9.2, c = 4.6;

        std::cout << max3(x, y, z) << std::endl; // wywo�anie szablonu dla int
        std::cout << max3(a, b, c) << std::endl; // wywo�anie szablonu dla double
    }

    std::cout << "\n3) Zbuduj szablon klasy walec i utw�rz w nim szablon metody obliczaj�cej pole powierzchni dla r�nych typ�w danych.Cia�o metody powinno znale�� si� poza klas�.\n";
    {
        Cylinder<int> cylinder1(3, 5);
        std::cout << "Pole powierzchni walca (typ int): " << cylinder1.CalculateArea() << std::endl;

        Cylinder<double> cylinder2(2.5, 7.2);
        std::cout << "Pole powierzchni walca (typ double): " << cylinder2.CalculateArea() << std::endl;
    }


    return 0;
}
