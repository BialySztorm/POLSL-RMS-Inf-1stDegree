#include <stdio.h>
#include <conio.h>
#include <locale.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	setlocale(LC_ALL, "");
	const int n = 100;
	char text[n];
	int i = 0;
	printf("Wprowad� tekst do sprawdzenia(maks %i znak�w)\n", n);
	fgets(text, n, stdin);

	for (int j = 0; j < n; j++)
		if (text[j] == 'a' || text[j] == 'A')
			i++;

	printf("W tek�cie znajodwa�o si� %i znak�w 'a'", i);

	_getch();
}