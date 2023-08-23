#include <iostream>
#include "Zero.h"

int main() {
    // skipcq: CXX-C2013
    double a, b;
    std::cout << "Podaj dwie liczby do dzielenia i modulo: ";
    std::cin >> a >> b;
    Zero zero(a,b);
    
    try {
        std::cout << "Wynik dzielenia: " << zero.Divide() << std::endl;
    }
    catch (const char* msg) {
        std::cerr << "Blad: " << msg << std::endl;
    }

    try {
        std::cout << "Wynik operacji modulo: " << zero.Modulo() << std::endl;
    }
    catch (const char* msg) {
        std::cerr << "Blad: " << msg << std::endl;
    }

    return 0;
}