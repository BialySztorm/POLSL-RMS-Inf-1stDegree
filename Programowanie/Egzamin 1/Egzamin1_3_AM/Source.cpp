#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

int maxIndex(double* x, int len);

int main()
{
	setlocale(LC_ALL, "");

	double* tab = (double*)malloc(sizeof(double) * 10000);
	double tmp;
	int len = 0;
	do {
		printf("Podaj %d liczbê ci¹gu (zero koñczy): ", len + 1);
		scanf("%le", &tmp);
		tab[len++] = tmp;
	} while (tmp != 0.0);

	printf("Najwiêksza jest %d liczba", maxIndex(tab, len));

	_getch();
	return 0;
}

int maxIndex(double* x, int len)
{
	int index = 0;
	double max = 0.0;

	for (int i = 0; i < len; i++) {
		if (x[i] > max) {
			max = x[i];
			index = i + 1;
		}
	}

	return index;
}