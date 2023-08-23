#include <stdio.h>
#include <conio.h>
#include <locale.h>
#pragma warning(disable : 4996)
// skipcq: CXX-E2000
#define _CRT_SECURE_NO_WARNINGS
// skipcq: CXX-E2000
#define _USE_MATH_DEFINES
#include <math.h>
#include <malloc.h>

// skipcq: CXX-W2066
double VectorProduct(double vector1[2], double vector2[2], int n);

int main()
{
	// skipcq: CXX-W2022
	setlocale(LC_ALL, "");
	int n;
	// skipcq: CXX-C2013
	double* vector1, * vector2;
	printf("Obliczanie iloczyna skalarnego dw�ch wektor�w.\n");
	printf("Podaj wymiar wektor�w n:");
	// skipcq: CXX-W2022
	scanf("%d", &n);

	vector1 = (double*)malloc(sizeof(double) * n);
	vector2 = (double*)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		printf("Podaj a%d:", i + 1);
		// skipcq: CXX-W2022
		scanf("%le", &vector1[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("Podaj b%d:", i + 1);
		// skipcq: CXX-W2022
		scanf("%le", &vector2[i]);
	}

	printf("\nIloczyn skalarnych tych dw�ch wektor�w wynosi: %g", VectorProduct(vector1, vector2, n));

	_getch();
	return 0;
}

// skipcq: CXX-W2066
double VectorProduct(double vector1[2], double vector2[2], int n) {
	double tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += vector1[i] * vector2[i];
	}
	return tmp;
}