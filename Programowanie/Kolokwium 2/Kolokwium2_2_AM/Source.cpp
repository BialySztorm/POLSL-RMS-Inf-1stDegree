#include <stdio.h>
#include <conio.h>
#include <locale.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

double textToNumber(char text[100]) {
	int len = 0, tmp = 0, power = 1;
	char tmpC;
	for (int i = 0; i < 100; i++)
	{
		if (text[i] < '0' || text[i]>'9')
			break;
		len++;
	}
	for (int i = len - 1; i >= 0; i--) {
		tmp += ((int)text[i] - (int)'0') * power;
		//printf("%c", text[i]);
		power *= 10.;
	}
	return tmp;
}

int main()
{
	setlocale(LC_ALL, "");
	FILE* fRef;
	double tmp = 0., min = 0, max = 0, avg = 0;
	char currentLine[100] = "";
	int isFirst = 1, len = 0;

	fRef = fopen("dane.txt", "r");
	if (fRef == NULL)
	{
		printf("Nie mo¿na otworzyæ pliku!");
		return 0;
	}

	while (fgets(currentLine, sizeof(currentLine), fRef) != NULL) {
		tmp = textToNumber(currentLine);
		if (isFirst) {
			min = tmp;
			max = tmp;
			avg = tmp;
			isFirst = 0;
		}
		else {
			if (min > tmp)
				min = tmp;
			if (max < tmp)
				max = tmp;
			avg += tmp;
		}
		printf("Mam linie: %g\n", tmp);
		len++;
	}
	fclose(fRef);
	printf("Min: %g\n", min);
	printf("Max: %g\n", max);
	printf("Avg: %g\n", avg / len);
	_getch();
	return 0;
}