#include <stdio.h>
#include <conio.h>
#include <locale.h>
#pragma warning(disable : 4996)
// skipcq: CXX-E2000
#define _CRT_SECURE_NO_WARNINGS
// skipcq: CXX-E2000
#define _USE_MATH_DEFINES

struct complex {
	double real;
	double imag;
};

struct complex add(struct complex a, struct complex b) {
	struct complex result;
	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return result;
}
struct complex multiply(struct complex a, struct complex b) {
	struct complex result;
	result.real = a.real * b.real - a.imag * b.imag;
	result.imag = a.real * b.imag + a.imag * b.real;
	return result;
}

int main()
{
	// skipcq: CXX-W2022
	setlocale(LC_ALL, "");
	// skipcq: CXX-C2013
	complex x, y;

	printf("Enter the real and imaginary parts of the first complex number: ");
	// skipcq: CXX-W2022
	scanf("%lf %lf", &x.real, &x.imag);

	printf("Enter the real and imaginary parts of the second complex number: ");
	// skipcq: CXX-W2022
	scanf("%lf %lf", &y.real, &y.imag);

	complex result = add(multiply(x, x), multiply(y, y));

	printf("(x*x + y*y) = %lf + %lfi\n", result.real, result.imag);
	_getch();
	return 0;
}