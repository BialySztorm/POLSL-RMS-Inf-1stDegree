#include <iostream>
#include "Circle.h"


int main() {
    double x, y, x0, y0, r;

    // wczytanie danych od u�ytkownika z zabezpieczeniem przed warto�ciami mniejszymi b�d� r�wnymi 0
    do {
        std::cout << "Podaj wspolrzedne punktu (x y): ";
        std::cin >> x >> y;
    } while (x <= 0 || y <= 0);

    do {
        std::cout << "Podaj wspolrzedne srodka kola (x0 y0) i promien r: ";
        std::cin >> x0 >> y0 >> r;
    } while (x0 <= 0 || y0 <= 0 || r <= 0);

    // utworzenie obiekt�w klas Punkt i Kolo
    Punkt punkt(x, y);
    Kolo kolo(x0, y0, r);

    // sprawdzenie, czy punkt nale�y do ko�a i wy�wietlenie odpowiedniego komunikatu
    if (kolo.punktNalezyDoKola(punkt)) {
        std::cout << "Podany punkt nalezy do kola o srodku (" << x0 << "," << y0 << ") i promieniu " << r << std::endl;
    }
    else {
        std::cout << "Podany punkt nie nalezy do kola o srodku (" << x0 << "," << y0 << ") i promieniu " << r << std::endl;
    }

    return 0;
}