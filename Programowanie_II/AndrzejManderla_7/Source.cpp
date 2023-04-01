#include <iostream>
#include <locale.h>
#include "Cylinder.h"
#include "Max.h"


int main() {
    std::setlocale(LC_ALL, "");

    std::cout<<"1) wywo³aj szablon funkcji max().\n";
    {
        int a = 5, b = 10;
        double c = 7.5, d = 9.2;

        std::cout << std::max(a, b) << std::endl; // wywo³anie szablonu dla int
        std::cout << std::max(c, d) << std::endl; // wywo³anie szablonu dla double
    }

    std::cout << "\n2) Na jego podstawie zbuduj szablon zwracaj¹cy wartoœæ najwiêksz¹ z trzech podanych argumentów.\n";
    {
        int x = 5, y = 10, z = 3;
        double a = 7.5, b = 9.2, c = 4.6;

        std::cout << max3(x, y, z) << std::endl; // wywo³anie szablonu dla int
        std::cout << max3(a, b, c) << std::endl; // wywo³anie szablonu dla double
    }

    std::cout << "\n3) Zbuduj szablon klasy walec i utwórz w nim szablon metody obliczaj¹cej pole powierzchni dla ró¿nych typów danych.Cia³o metody powinno znaleŸæ siê poza klas¹.\n";
    {
        Cylinder<int> cylinder1(3, 5);
        std::cout << "Pole powierzchni walca (typ int): " << cylinder1.CalculateArea() << std::endl;

        Cylinder<double> cylinder2(2.5, 7.2);
        std::cout << "Pole powierzchni walca (typ double): " << cylinder2.CalculateArea() << std::endl;
    }


    return 0;
}
