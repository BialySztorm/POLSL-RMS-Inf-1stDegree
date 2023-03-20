#include <iostream>
#include "Vector.h"


int main() {
    Vector v1(1.0, 2.0, 3.0);
    Vector v2(4.0, 5.0, 6.0);

    std::cout << "v1 = " << v1.GetVector() << "\n";
    std::cout << "v2 = " << v2.GetVector() << "\n\n";

    Vector v3 = --v1;
    Vector v4 = ++v2;
    Vector v5 = v3+v4;
    Vector v6 = v3-v4;

    std::cout << "v1 = " << v1.GetVector() << "\n";
    std::cout << "v2 = " << v2.GetVector() << "\n";
    std::cout << "v3(--v1) = " << v3.GetVector() << "\n";
    std::cout << "v4(++v2) = " << v4.GetVector() << "\n";
    std::cout << "v5(v3+v4) = " << v5.GetVector() << "\n";
    std::cout << "v6(v3-v4) = " << v6.GetVector() << "\n";

    return 0;
}