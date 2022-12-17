#include <stdio.h>
#include <conio.h>
#include <locale.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

struct Complex {
    double real, img;
};

int main()
{
    setlocale(LC_ALL, "");
    Complex x,y;

    printf("Enter the real and imaginary parts of the first complex number: ");
    scanf("%lf %lf", &x.real, &x.img);

    printf("Enter the real and imaginary parts of the second complex number: ");
    scanf("%lf %lf", &y.real, &y.img);

    printf("(x*x + y*y) = %lf + %lfi\n", x.real * x.real + y.real * y.real - x.img * x.img - y.img * y.img, 2 * x.real * x.img + 2 * y.real * y.img);
    _getch();
    return 0;
}