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
	char text[n] = "";
	int i = 0;
	bool isNewLine = 1;
	printf("WprowadŸ tekst do sprawdzenia(maks %i znaków)\n", n);
	fgets(text, n, stdin);

	for (int j = 0; j < n; j++)
	{
		if (isNewLine && (text[j] == '	' || text[j] == ' '))
			continue;
		else if (text[j] == '\n')
			isNewLine = 1;
		else {
			isNewLine = 0;
			printf("%c", text[j]);
		}
	}

	_getch();
}