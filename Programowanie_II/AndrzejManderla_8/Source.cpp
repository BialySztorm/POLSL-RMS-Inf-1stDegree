#include <iostream>
#include "Vector.h"


int main() {
    Vector1 v1(1.0, 2.0, 3.0);
    Vector1 v2(4.0, 5.0, 6.0);

    std::cout << "v1 = " << v1.GetVector() << "\n";
    std::cout << "v2 = " << v2.GetVector() << "\n\n";

    Vector1 v3 = --v1;
    Vector1 v4 = ++v2;
    Vector1 v5 = v3+v4;
    Vector1 v6 = v3-v4;

    std::cout << "v1 = " << v1.GetVector() << "\n";
    std::cout << "v2 = " << v2.GetVector() << "\n";
    std::cout << "v3(--v1) = " << v3.GetVector() << "\n";
    std::cout << "v4(++v2) = " << v4.GetVector() << "\n";
    std::cout << "v5(v3+v4) = " << v5.GetVector() << "\n";
    std::cout << "v6(v3-v4) = " << v6.GetVector() << "\n";

    return 0;
}