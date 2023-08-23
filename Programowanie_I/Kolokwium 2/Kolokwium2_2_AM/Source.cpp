// skipcq: CXX-W2030
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
// skipcq: CXX-W2030
#include <stdlib.h>

// skipcq: CXX-W2066
double textToNumber(char text[100]) {
	// skipcq: CXX-C2013
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
	// skipcq: CXX-W2022
	setlocale(LC_ALL, "");
	FILE* fRef;
	// skipcq: CXX-C2013
	double tmp = 0., min = 0, max = 0, avg = 0;
	// skipcq: CXX-W2066
	char currentLine[100] = "";
	// skipcq: CXX-C2013
	int isFirst = 1, len = 0;

	fRef = fopen("dane.txt", "r");
	if (fRef == NULL)
	{
		printf("Nie mo�na otworzy� pliku!");
		return 0;
	}

	// skipcq: CXX-C1000
	while (fgets(currentLine, sizeof(currentLine), fRef) != NULL) {
		// skipcq: CXX-C1000
		tmp = textToNumber(currentLine);
		// skipcq: CXX-W2065
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
	// skipcq: CXX-W2022
	fclose(fRef);
	printf("Min: %g\n", min);
	printf("Max: %g\n", max);
	printf("Avg: %g\n", avg / len);
	_getch();
	return 0;
}