// skipcq: CXX-W2030
#include <stdio.h>
#include <conio.h>
// skipcq: CXX-W2030
#include <stdlib.h>
// skipcq: CXX-W2030
#include <locale.h>
#pragma warning(disable : 4996)
// skipcq: CXX-E2000
#define _CRT_SECURE_NO_WARNINGS
// skipcq: CXX-E2000
#define _USE_MATH_DEFINES

// skipcq: CXX-W2066
void calculate(double a[3][3], double b[3]);

int main()
{
	// skipcq: CXX-W2022
	setlocale(LC_ALL, "");

	// skipcq: CXX-C2013
	double a[3][3], b[3];
	printf("Podaj wartosci wspolczynnikow dla ukladu rownan:\n");
	printf("a11*x1 + a12*x2 = b1\n");
	printf("a21*x1 + a22*x2 = b2\n");

	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 3; j++) {
			printf("a%d%d = ", i, j);
			// skipcq: CXX-W2065
			if (!scanf("%lf", &a[i][j])) {
				printf("B��d, nie poda�e� liczby!");
				_getch();
				return -1;
			}
		}
		printf("b%d = ", i);
		// skipcq: CXX-W2065
		if (!scanf("%lf", &b[i])) {
			printf("B��d, nie poda�e� liczby!");
			_getch();
			return -1;
		}
	}

	// skipcq: CXX-C1000
	calculate(a, b);
	_getch();
	return 0;
}

// skipcq: CXX-W2066
void calculate(double a[3][3], double b[3]) {
	// skipcq: CXX-W2066
	double x[3];
	double wyznacznik = a[1][1] * a[2][2] - a[1][2] * a[2][1];
	if (wyznacznik != 0) {
		x[1] = (b[1] * a[2][2] - b[2] * a[1][2]) / wyznacznik;
		x[2] = (b[2] * a[1][1] - b[1] * a[2][1]) / wyznacznik;
		printf("Rozwiazanie ukladu rownan: x1 = %lf, x2 = %lf\n", x[1], x[2]);
	}
	else {
		printf("Uklad sprzeczny/nieoznaczony \n");
	}
}