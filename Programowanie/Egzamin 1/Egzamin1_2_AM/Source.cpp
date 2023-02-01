#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

struct user {
	int id;
	char name[255];
	char position[255];
};

int main()
{
	setlocale(LC_ALL, "");

	FILE* fp = fopen("dane.txt", "r");
	if (fp == NULL)
	{
		printf("Nie mo¿na otworzyæ pliku dane.txt\n");
		_getch();
		return -1;
	}

	int len = 0, isFound = 0;
	char name[255];
	user person;

	printf("Podaj nazwisko do sprawdzenia: ");
	scanf("%s", name);

	while (fscanf(fp, "%d %s %s", &person.id, person.name, person.position) == 3)
	{
		if (strcmp(person.name, name) == 0) {
			printf("Znalezniono osobê: %d %s %s", person.id, person.name, person.position);
			isFound++;
		}
	}
	if (!isFound)
		printf("Nie znaleziono osoby o nazwisko: %s", name);

	_getch();
	return 0;
}