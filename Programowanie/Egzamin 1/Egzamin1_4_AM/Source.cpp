#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");

	if (argc < 2)
	{
		printf("Nie podano œcie¿ki do pliku\n");
		_getch();
		return -1;
	}

	FILE* fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("Nie uda³o siê otworzyæ pliku: %s\n", argv[1]);
		_getch();
		return -1;
	}

	char tmp;
	while ((tmp = fgetc(fp)) != EOF)
	{
		printf("%c", tmp);
	}

	fclose(fp);

	_getch();
}