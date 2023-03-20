#include <iostream>

class Vector {
public:
    double x, y, z;

    Vector(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    // Przeci¹¿enie operatora dwuargumentowego (-)
    Vector operator-(const Vector& v) const {
        return Vector(x - v.x, y - v.y, z - v.z);
    }

    // Przeci¹¿enie operatora dwuargumentowego (+)
    Vector operator+(const Vector& v) const {
        return Vector(x + v.x, y + v.y, z + v.z);
    }

    // Przeci¹¿enie operatora jednoargumentowego (--)
    Vector operator--() {
        return Vector(x--, y--, z--);
    }

    // Przeci¹¿enie operatora jednoargumentowego (++)
    Vector operator++() {
        return Vector(x++,y++,z++);
    }

    // Przeci¹¿enie operatora dwuargumentowego (*)
    Vector operator*(const Vector& v) const {
        return Vector(x * v.x, y * v.y, z * v.z);
    }

};



int main() {
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);

    std::cout << "v1 = (" << v1.x << ", " << v1.y << ", " << v1.z << ")\n";
    std::cout << "v2 = (" << v2.x << ", " << v2.y << ", " << v2.z << ")\n\n";

    Vector v3 = --v1;
    Vector v4 = ++v2;
    Vector v5 = v3+v4;
    Vector v6 = v3-v4;

    std::cout << "v1 = (" << v1.x << ", " << v1.y << ", " << v1.z << ")\n";
    std::cout << "v2 = (" << v2.x << ", " << v2.y << ", " << v2.z << ")\n";
    std::cout << "v3(--v1) = (" << v3.x << ", " << v3.y << ", " << v3.z << ")\n";
    std::cout << "v4(++v2) = (" << v4.x << ", " << v4.y << ", " << v4.z << ")\n";
    std::cout << "v5(v3+v4) = (" << v5.x << ", " << v5.y << ", " << v5.z << ")\n";
    std::cout << "v6(v3-v4) = (" << v6.x << ", " << v6.y << ", " << v6.z << ")\n";

    return 0;
}