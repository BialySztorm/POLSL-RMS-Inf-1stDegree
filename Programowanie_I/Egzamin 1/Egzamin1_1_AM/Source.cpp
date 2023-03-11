#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>

void flushKeyBoard();
double CalculateConeVolume(double r, double l);
double CalculateConeSurfaceArea(double r, double l);

int main()
{
	setlocale(LC_ALL, "");
	printf("Obliczaniepola powierzchni i objêtoœci sto¿ka\n");
	printf("Podane przez ciebie l musi byæ wiêksze od r oraz obie wartoœci wiêksze od 0\n");

	double r, l;
	int i = 0;
	do {
		if (i)
			printf("\nWprowadzono b³êdne dane!\n");
		i++;
		printf("Podaj tworz¹c¹ sto¿ka: ");
		while (!scanf("%le", &l))
		{
			flushKeyBoard();
			printf("\nWprowadzono b³êdne dane!\nPodaj tworz¹c¹ sto¿ka: ");
		}
		printf("Podaj promieñ sto¿ka: ");
		while (!scanf("%le", &r))
		{
			flushKeyBoard();
			printf("\nWprowadzono b³êdne dane!\nPodaj promieñ sto¿ka: ");
		}
	} while (r >= l && l > 0 && r > 0);

	printf("Pole powierzchni tego sto¿ka wynosi: %f\n", CalculateConeSurfaceArea(r, l));
	printf("Objêtoœæ tego sto¿ka wynosi: %f\n", CalculateConeVolume(r, l));

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