#include <stdio.h>
#include <conio.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
#include "colors.h"
#include "locale.h"

int main() {
	setlocale(LC_ALL, "");

	class Main Obj;
	return 0;
};

Main::Main()
{
	while (IsRunning) {
		ShowGui();
		// max char[] size  2 ^ 32 -1
		textcolor(InputColor);
		Option = _getch();

		if (Option == '0')
			IsRunning = 0;
		else if (Option == '1') {
			GetInput();

			textcolor(InputColor);
			printf("%s", Obj.Encrypt(String, InputLen));

			printf("Press something to continue.");
			GetChar = _getch();
		}
		else if (Option == '2') {
			GetInput();

			textcolor(InputColor);
			printf("%s", Obj.Decrypt(String, InputLen));

			printf("Press something to continue.");
			GetChar = _getch();
		}
		else {
			textcolor(4);
			printf("Wrong data!");
			GetChar = _getch();
		}
	}
}

void Main::ShowGui()
{
	system("cls");
	textcolor(5);
	printf("<--------------------------------->\n");
	textcolor(13);
	printf("Mendeleev's Cipher v1.0.1\n");
	printf("by Andrzej Manderla\n\n");
	printf("Select option:\n");
	printf("[1] - Encrypt\n");
	printf("[2] - Decrypt\n");
	printf("[0] - Exit\n");
	textcolor(5);
	printf("<--------------------------------->\n\n\n");
}

void Main::GetInput()
{
	textcolor(3);
	printf("\nSet input: ");
	textcolor(InputColor);
	fgets(Input, TabLen, stdin);
	InputLen = 0;
	for (int i = 0; i < TabLen; i++) {
		if (Input[i] == 0 || Input[i] == 10)
		{
			break;
		}
		printf("%c, ", Input[i]);
		InputLen++;
	}
	//printf("\nlen: %d\n", InputLen);

	InputLen += 2;
	String = (char*)malloc(InputLen * 8);
	for (int i = 0; i < InputLen; i++) {
		String[i] = Input[i];
	}
	InputLen -= 2;
}