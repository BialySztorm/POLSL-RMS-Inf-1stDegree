#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<math.h>

double** createTab(int m, int n);
double* createTab_b(int m);

int main()
{
	setlocale(LC_ALL, "");

	double** tab_a, * tab_b;
	tab_a = createTab(2, 2);

	tab_b = createTab_b(2);
	Wypisz(tab_a, tab_b, 2, 2);

	Obliczenia(tab_a, tab_b, 2, 2);

	_getch();
}

double** createTab(int m, int n)
{
	double** tab;

	tab = (double**)malloc(sizeof(double*) * m);

	for (int i = 0; i < m; i++)
		tab[i] = (double*)malloc(sizeof(double) * n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Podaj a[%d][%d]: ", i, j);
			scanf("%le", &tab[i][j]);
		}
	}

	return tab;
}
double* createTab_b(int m)
{
	double* tab_1 = (double*)malloc(sizeof(double) * m);
	for (int i = 0; i < m; i++)
	{
		printf("Podaj b[%d]: ", i);
		scanf("%le", &tab_1[i]);
	}
	return tab_1;
}
void Wypisz(double** tab, double* tab_1, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%3g ", tab[i][j]);
		}
		printf("%3g", tab_1[i]);
		printf("\n");
	}
}
void Obliczenia(double** tab, double* tab_1, int m, int n)
{
	double W, Wx, Wy;
	W = tab[0][0] * tab[1][1] - tab[0][1] * tab[1][0];
	Wx = tab_1[0] * tab[1][1] - tab_1[1] * tab[0][1];
	Wy = tab_1[1] * tab[0][0] - tab_1[0] * tab[1][0];

	if (W != 0)
	{
		printf("x[0]=%g\n", Wx / W);
		printf("x[1]=%g\n", Wy / W);
	}
	else
	{
		if (Wx != 0) {
			printf("Uk³ad równañ jest sprzeczny\n");
		}
		else {
			printf("Uk³ad równañ jest nieoznaczony\n");
		}
	}
}