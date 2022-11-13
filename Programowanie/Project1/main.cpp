#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include "colors.h"
#include "data.h"

#define InputColor 15
;
void ShowGui();
int GetInput(char** Text);
void Encrypt(char* Text, int InputLen);
void Decrypt(char* Text, int InputLen);

int main() {
	setlocale(LC_ALL, "");
	bool IsRunning = 1;
	char Option = 0;
	int InputLen;
	char* String = nullptr;
	char GetChar;

	while (IsRunning) {
		ShowGui();
		// max char[] size  2 ^ 32 -1
		textcolor(InputColor);
		Option = _getch();

		if (Option == '0')
			IsRunning = 0;
		else if (Option == '1') {
			InputLen = GetInput(&String);

			Encrypt(String, InputLen);

			textcolor(InputColor);
			printf("Press something to continue.");
			GetChar = _getch();
		}
		else if (Option == '2') {
			InputLen = GetInput(&String);

			Decrypt(String, InputLen);

			textcolor(InputColor);
			printf("Press something to continue.");
			GetChar = _getch();
		}
		else {
			textcolor(4);
			printf("Wrong data!");
			GetChar = _getch();
		}
	}

	return 0;
}

void ShowGui()
{
	system("cls");
	textcolor(5);
	printf("<--------------------------------->\n");
	textcolor(13);
	printf("Mendeleev's Cipher v1.0.2\n");
	printf("by Andrzej Manderla\n\n");
	printf("Select option:\n");
	printf("[1] - Encrypt\n");
	printf("[2] - Decrypt\n");
	printf("[0] - Exit\n");
	textcolor(5);
	printf("<--------------------------------->\n\n\n");
}

int GetInput(char** Text)
{
	const int TabLen = 10000;
	char Input[TabLen];
	textcolor(3);
	printf("\nSet input: ");
	textcolor(InputColor);
	fgets(Input, TabLen, stdin);
	int InputLen = 0;
	for (int i = 0; i < TabLen; i++) {
		if (Input[i] == 0 || Input[i] == 10)
		{
			break;
		}
		//printf("%c, ", Input[i]);
		InputLen++;
	}
	//printf("\nlen: %d\n", InputLen);

	InputLen += 2;
	*Text = (char*)malloc(InputLen);
	if (*Text) {
		for (int i = 0; i < InputLen; i++) {
			(*Text)[i] = Input[i];
		}
	}
	InputLen -= 2;

	return InputLen;
}

void Encrypt(char* Text, int InputLen) {
	printf("%s", Text);
}

void Decrypt(char* Text, int InputLen) {
	int TabLen = 1;
	char* Decrypted;
	int tmp[4] = { 0,0,0,0 };
	int tmp1 = 0;
	int CurrIndex = 0;
	for (int i = 0; i < InputLen; i++) {
		if (Text[i] == '*') {
			TabLen++;
		}
	}
	TabLen *= 2;
	//printf("%d", TabLen);
	Decrypted = (char*)malloc(TabLen);
	if (Decrypted) {
		for (int i = 0; i < TabLen; i++) {
			Decrypted[i] = NULL;
		}
		for (int i = 0; i <= InputLen; i++) {
			if (Text[i] >= '0' && Text[i] <= '9') {
				tmp[0]++;
				tmp[tmp[0]] = (int)Text[i] - 48;
			}
			if (Text[i] == '*' || i == InputLen - 1) {
				if (tmp[0] > 0) {
					for (int j = 1; j <= tmp[0]; j++) {
						tmp1 += (int)pow(10, tmp[0] - j) * tmp[j];
					}
					//printf("%d\n", tmp1);
					for (int j = 0; j < ElementsLen[tmp1]; j++) {
						Decrypted[CurrIndex] = Elements[tmp1][j];
						CurrIndex++;
					}
				}
				tmp[0] = 0;
				tmp1 = 0;
				if (Text[i - 1] == '*') {
					Decrypted[CurrIndex] = ' ';
					CurrIndex++;
				}
			}
		}

		printf("%s\n", Decrypted);
	}
}