#include <stdio.h>
#include <conio.h>
#include <locale.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <malloc.h>

void BubbleSort(int tab[], int len);

int main()
{
	setlocale(LC_ALL, "");
	int* tab;
	int len;
	printf("Podaj wymiar zadania: ");
	scanf("%d", &len);
	tab = (int*)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++) {
		printf("Podaj %d element: ", i + 1);
		scanf("%d", &tab[i]);
	}

	BubbleSort(tab, len);

	for (int i = 0; i < len; i++) {
		printf("%d, ", tab[i]);
	}
	printf("\n");
	_getch();
}

void BubbleSort(int tab[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (tab[j] < tab[j + 1]) {
				int tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		}
	}
}