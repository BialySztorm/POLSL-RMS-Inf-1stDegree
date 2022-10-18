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
	double r = 0, h = 0;
	while (!r && !h)
	{
		printf("Podaj r: ");
		scanf("%le", &r);
		printf("Podaj h: ");
		scanf("%le", &h);
		if (!r || !h)
		{
			printf("\nB³¹d! WprowadŸ dane ponownie\n");
			_getch;
		}
	}
	//printf("r: %g, h: %g", r, h);

	printf("Pole powierzchni bocznej: %g\n", (2 * M_PI * r * h));
	printf("Objêtoœæ: %g", (M_PI * pow(r, 2) * h));

	_getch();
}