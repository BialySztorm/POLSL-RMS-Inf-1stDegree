// skipcq: CXX-W2030
#include <stdio.h>
#include <conio.h>
// skipcq: CXX-W2030
#include <stdlib.h>
// skipcq: CXX-W2030
#include <locale.h>
#pragma warning(disable : 4996)
// skipcq: CXX-E2000
#define _CRT_SECURE_NO_WARNINGS
// skipcq: CXX-E2000
#define _USE_MATH_DEFINES

int main(int argc, char* argv[])
{
	// skipcq: CXX-W2022
	setlocale(LC_ALL, "");

	if (argc < 2)
	{
		printf("Nie podano �cie�ki do pliku\n");
		_getch();
		return -1;
	}

	FILE* fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("Nie uda�o si� otworzy� pliku: %s\n", argv[1]);
		_getch();
		return -1;
	}

	char tmp;
	while ((tmp = fgetc(fp)) != EOF)
	{
		printf("%c", tmp);
	}

	// skipcq: CXX-W2022
	fclose(fp);

	_getch();
}