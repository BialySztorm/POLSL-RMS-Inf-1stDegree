#include <stdio.h>
#include <conio.h>
#include <locale.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>

void insertion_sort(int* tab, int n) {
	int tmp, j;
	for (int i = 1; i < n; i++)
	{
		tmp = tab[i];
		j = i - 1;

		while (j >= 0 && tab[j] > tmp)
		{
			tab[j + 1] = tab[j];
			--j;
		}
		tab[j + 1] = tmp;
	}
}

int main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int* tab;
	tab = new int[n];

	for (int i = 0; i < n; i++) {
		printf("podaj %i liczbê: ", i + 1);
		scanf("%i", &tab[i]);
	}

	insertion_sort(tab, n);
	for (int i = 0; i < n; i++) {
		printf("%i, ", tab[i]);
	}

	_getch();
}