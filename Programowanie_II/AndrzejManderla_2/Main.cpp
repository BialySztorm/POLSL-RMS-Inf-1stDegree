#include <iostream>
#include "Circle.h"


int main() {
    // skipcq: CXX-C2013
    double x, y, x0, y0, r;

    // wczytanie danych od u�ytkownika z zabezpieczeniem przed warto�ciami mniejszymi b�d� r�wnymi 0
    std::cout << "Podaj wspolrzedne punktu (x y): ";
    std::cin >> x >> y;

    do {
        std::cout << "Podaj wspolrzedne srodka kola (x0 y0) i promien r: ";
        std::cin >> x0 >> y0 >> r;
    } while ( r <= 0);

    // utworzenie obiekt�w klas Punkt i Kolo
    Point point(x, y);
    Circle circle(x0, y0, r);

    // sprawdzenie, czy punkt nale�y do ko�a i wy�wietlenie odpowiedniego komunikatu
    if (circle.PointInCircle(point)) {
        std::cout << "Podany punkt nalezy do kola o srodku (" << x0 << "," << y0 << ") i promieniu " << r << std::endl;
    }
    else {
        std::cout << "Podany punkt nie nalezy do kola o srodku (" << x0 << "," << y0 << ") i promieniu " << r << std::endl;
    }

    return 0;
}