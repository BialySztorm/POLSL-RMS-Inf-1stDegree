#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
// skipcq: CXX-E2000
#define _CRT_SECURE_NO_WARNINGS

struct user {
	int id;
	// skipcq: CXX-W2066
	char name[255];
	// skipcq: CXX-W2066
	char position[255];
};

int main()
{
	// skipcq: CXX-W2022
	setlocale(LC_ALL, "");

	FILE* fp = fopen("dane.txt", "r");
	if (fp == NULL)
	{
		printf("Nie mo�na otworzy� pliku dane.txt\n");
		_getch();
		return -1;
	}

	// skipcq: CXX-C2013
	int len = 0, isFound = 0;
	// skipcq: CXX-W2066
	char name[255];
	user person;

	printf("Podaj nazwisko do sprawdzenia: ");
	// skipcq: CXX-W2022
	scanf("%s", name);

	// skipcq: CXX-W2023
	while (fscanf(fp, "%d %s %s", &person.id, person.name, person.position) == 3)
	{
		// skipcq: CXX-C1000
		if (strcmp(person.name, name) == 0) {
			// skipcq: CXX-C1000
			printf("Znalezniono osob�: %d %s %s", person.id, person.name, person.position);
			isFound++;
		}
	}
	// skipcq: CXX-W2065
	if (!isFound)
		// skipcq: CXX-C1000
		printf("Nie znaleziono osoby o nazwisko: %s", name);

	_getch();
	return 0;
}