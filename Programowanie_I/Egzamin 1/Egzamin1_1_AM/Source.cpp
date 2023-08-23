#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
// skipcq: CXX-E2000
#define _CRT_SECURE_NO_WARNINGS
// skipcq: CXX-E2000
#define _USE_MATH_DEFINES
#include <math.h>

void flushKeyBoard();
double CalculateConeVolume(double r, double l);
double CalculateConeSurfaceArea(double r, double l);

int main()
{
	// skipcq: CXX-W2022
	setlocale(LC_ALL, "");
	printf("Obliczaniepola powierzchni i obj�to�ci sto�ka\n");
	printf("Podane przez ciebie l musi by� wi�ksze od r oraz obie warto�ci wi�ksze od 0\n");

	// skipcq: CXX-C2013
	double r, l;
	int i = 0;
	do {
		// skipcq: CXX-W2065
		if (i)
			printf("\nWprowadzono b��dne dane!\n");
		i++;
		printf("Podaj tworz�c� sto�ka: ");
		// skipcq: CXX-W2065
		while (!scanf("%le", &l))
		{
			flushKeyBoard();
			printf("\nWprowadzono b��dne dane!\nPodaj tworz�c� sto�ka: ");
		}
		printf("Podaj promie� sto�ka: ");
		// skipcq: CXX-W2065
		while (!scanf("%le", &r))
		{
			flushKeyBoard();
			printf("\nWprowadzono b��dne dane!\nPodaj promie� sto�ka: ");
		}
	} while (r >= l && l > 0 && r > 0);

	printf("Pole powierzchni tego sto�ka wynosi: %f\n", CalculateConeSurfaceArea(r, l));
	printf("Obj�to�� tego sto�ka wynosi: %f\n", CalculateConeVolume(r, l));

	_getch();
	return 0;
}

void flushKeyBoard()
{
	int ch;
	while ((ch = getc(stdin)) != EOF && ch != '\n');
}

double CalculateConeVolume(double r, double l)
{
	double h;
	h = sqrt((l * l) - (r * r));
	return (M_PI * (r * r) * h) / 3.0;
}

double CalculateConeSurfaceArea(double r, double l)
{
	return M_PI * r * (r + l);
}