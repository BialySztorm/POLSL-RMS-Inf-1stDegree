#pragma once
template <typename T>
T max3(T a, T b, T c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

