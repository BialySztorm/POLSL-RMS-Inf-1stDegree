#include <stdio.h>
#include <conio.h>
#include <locale.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <malloc.h>

int polynomial(int tab[], int n, int x) {
	double tmp;
	for (int i = 0; i < n; i++) {
		tmp += tab[i] * pow(x, i);
	}

	return tmp;
}

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
		tab[i] = pow(x, i);
	}

	printf("Warto�� tego wielomianu to: %d", polynomial(tab, n, x));

	_getch();
}