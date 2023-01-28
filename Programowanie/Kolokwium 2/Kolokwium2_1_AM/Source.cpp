#include <stdio.h>
#include <conio.h>
#include <locale.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <malloc.h>

double VectorProduct(double vector1[2], double vector2[2], int n);

int main()
{
	setlocale(LC_ALL, "");
	int n;
	double* vector1, * vector2;
	printf("Obliczanie iloczyna skalarnego dwóch wektorów.\n");
	printf("Podaj wymiar wektorów n:");
	scanf("%d", &n);

	vector1 = (double*)malloc(sizeof(double) * n);
	vector2 = (double*)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		printf("Podaj a%d:", i + 1);
		scanf("%le", &vector1[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("Podaj b%d:", i + 1);
		scanf("%le", &vector2[i]);
	}

	printf("\nIloczyn skalarnych tych dwóch wektorów wynosi: %g", VectorProduct(vector1, vector2, n));

	_getch();
	return 0;
}

double VectorProduct(double vector1[2], double vector2[2], int n) {
	double tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += vector1[i] * vector2[i];
	}
	return tmp;
}