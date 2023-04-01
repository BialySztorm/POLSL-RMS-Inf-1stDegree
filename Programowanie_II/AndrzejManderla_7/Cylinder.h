#pragma once
//#define M_PI 3.14159265358979323846

template <typename T>
class Cylinder
{
private:
    T r, h;
public:
    Cylinder(T r, T h);

    T CalculateArea() const;
};

//? A mo¿e tak powinno byæ?

//template <typename T>
//Cylinder<T>::Cylinder(T r, T h) : r(r), h(h) {}
//
//template <typename T>
//T Cylinder<T>::CalculateArea() const
//{
//    return 2 * M_PI * r * (r + h);
//}
