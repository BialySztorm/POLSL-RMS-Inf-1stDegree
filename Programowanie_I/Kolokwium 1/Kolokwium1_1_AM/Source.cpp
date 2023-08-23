#include <stdio.h>
#include <conio.h>
#include <locale.h>
#pragma warning(disable : 4996)
// skipcq: CXX-E2000
#define _CRT_SECURE_NO_WARNINGS
// skipcq: CXX-E2000
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	// skipcq: CXX-W2022
	setlocale(LC_ALL, "");
	// skipcq: CXX-C2013
	double h = 0, r = 0, l;

	printf("Podaj promie� sto�ka: ");
	// skipcq: CXX-W2022
	scanf("%le", &r);
	printf("Podaj wysoko�� sto�ka: ");
	// skipcq: CXX-W2022
	scanf("%le", &h);

	if (h > 0 && r > 0) {
		l = sqrt(pow(h, 2) + pow(r, 2));
		printf("Pole powierzchni bocznej sto�ka wynosi: %g\n", (M_PI * r * l));
		printf("Obj�to�� sto�ka wynosi: %g\n", (M_PI * pow(r, 2) * h) / 3);
	}
	else {
		printf("\nB��dne dane!\n");
	}

	_getch();
}