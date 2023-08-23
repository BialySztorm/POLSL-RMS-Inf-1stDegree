#include <stdio.h>
#include <conio.h>
// skipcq: CXX-W2030
#include <locale.h>
#pragma warning(disable : 4996)
// skipcq: CXX-E2000
#define _CRT_SECURE_NO_WARNINGS
// skipcq: CXX-E2000
#define _USE_MATH_DEFINES
// skipcq: CXX-W2030
#include <math.h>
#include <malloc.h>

// skipcq: CXX-W2066
int polynomial(int tab[], int n, int x);

int main()
{
	// skipcq: CXX-W2022
	setlocale(LC_ALL, "");

	int* tab;
	// skipcq: CXX-C2013
	int n, x;
	printf("Podaj n: ");
	// skipcq: CXX-W2022
	// skipcq: CXX-W2022
	scanf("%d", &n);
	printf("Podaj x: ");
	// skipcq: CXX-W2022
	scanf("%d", &x);

	tab = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		int tmp;
		printf("Podaj %d wsp�czynnik: ", i + 1);
		// skipcq: CXX-W2022
		scanf("%i", &tmp);
		tab[i] = tmp;
	}

	printf("Warto�� tego wielomianu to: %d", polynomial(tab, n, x));

	_getch();
}

// skipcq: CXX-W2066
int polynomial(const int tab[], const int n, const int x) {
	double tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += tab[i] * pow(x, i);
	}

	return tmp;
}