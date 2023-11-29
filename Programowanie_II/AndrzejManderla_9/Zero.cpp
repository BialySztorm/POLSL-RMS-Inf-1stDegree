#include "Zero.h"

Zero::Zero(double a, double b): a(a), b(b) {}

double Zero::Divide()
{
    if (b == 0) {
        throw "(Divide) Nie mozna dzielic przez zero";
    }
    return a / b;
}

int Zero::Modulo()
{
    if ((int)b == 0)
        throw "(Modulo) Nie mozna dzielic przez zero";
    else if((int)a == (int)b)
        throw "(Modulo) Nieprawidlowe dane, liczby sa takie same";
    else if (a!=0 && ((int)a % (int)b == 0 || (int)b % (int)a == 0 ))
        throw "(Modulo) Nieprawidlowe dane, jedna z liczb jest wielokrotnoscia drugiej";
    return (int)a % (int)b;
}
