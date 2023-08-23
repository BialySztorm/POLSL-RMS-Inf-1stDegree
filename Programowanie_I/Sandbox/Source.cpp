// skipcq: CXX-W2030
#include <stdio.h>
// skipcq: CXX-W2030
#include <stdlib.h>
#include <conio.h>
#pragma warning(disable : 4996)
// skipcq: CXX-E2000
#define _CRT_SECURE_NO_WARNINGS
// skipcq: CXX-E2000
#define _USE_MATH_DEFINES
#define N 10

int main(void) {
	// skipcq: CXX-W2066
	int a[N][N];
	// skipcq: CXX-C2013
	int i, j, k = 1;
	int row_start = 0;
	int row_end = N - 1;
	int col_start = 0;
	int col_end = N - 1;

	while (k <= N * N) {
		// Wpisywanie liczb do g�rnej kolumny
		for (i = row_start; i <= row_end; i++) {
			a[i][col_start] = k++;
		}
		col_start++;

		// Wpisywanie liczb do prawej kolumny
		for (i = col_start; i <= col_end; i++) {
			a[row_end][i] = k++;
		}
		row_end--;

		// Wpisywanie liczb do dolnej kolumny
		for (i = row_end; i >= row_start; i--) {
			a[i][col_end] = k++;
		}
		col_end--;

		// Wpisywanie liczb do lewej kolumny
		for (i = col_end; i >= col_start; i--) {
			a[row_start][i] = k++;
		}
		row_start++;
	}

	// Wypisywanie tablicy
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d\t", a[j][i]);
		}
		printf("\n");
	}
	_getch();
	return 0;
}