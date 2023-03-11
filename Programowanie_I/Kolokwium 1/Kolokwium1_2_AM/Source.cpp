#include <stdio.h>
#include <conio.h>
#include <locale.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <malloc.h>

int polynomial(int tab[], int n, int x);

int main()
{
	setlocale(LC_ALL, "");

	int* tab;
	int n, x;
	printf("Podaj n: ");
	scanf("%d", &n);
	printf("Podaj x: ");
	scanf("%d", &x);

	tab = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		int tmp;
		printf("Podaj %d wspó³czynnik: ", i + 1);
		scanf("%i", &tmp);
		tab[i] = tmp;
	}

	printf("Wartoœæ tego wielomianu to: %d", polynomial(tab, n, x));

	_getch();
}

int polynomial(int tab[], int n, int x) {
	double tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += tab[i] * pow(x, i);
	}

	return tmp;
}