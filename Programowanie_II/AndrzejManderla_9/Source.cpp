#include <iostream>

double divide(double a, double b) {
    if (b == 0) {
        throw "Nie mozna dzielic przez zero";
    }
    return a / b;
}

int modulo(int a, int b) {
    if (b == 0) {
        throw "Nie mozna dzielic przez zero";
    }
    else if (a == b || a % b == 0 || b % a == 0) {
        throw "Nieprawidlowe dane";
    }
    return a % b;
}

int main() {
    try {
        double a, b;
        std::cout << "Podaj dwie liczby do podzielenia: ";
        std::cin >> a >> b;
        double result = divide(a, b);
        std::cout << "Wynik dzielenia: " << result << std::endl;
    }
    catch (const char* msg) {
        std::cerr << "Blad: " << msg << std::endl;
    }

    try {
        int a, b;
        std::cout << "Podaj dwie liczby do operacji modulo: ";
        std::cin >> a >> b;
        int result = modulo(a, b);
        std::cout << "Wynik operacji modulo: " << result << std::endl;
    }
    catch (const char* msg) {
        std::cerr << "Blad: " << msg << std::endl;
    }

    return 0;
}