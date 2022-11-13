#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include "colors.h"
#include "data.h"

int InputColor = 0;

void GetOptions();
void ShowGui();
int GetInput(char** Text);
void Encrypt(char* Text, int InputLen);
void Decrypt(char* Text, int InputLen);

int main() {
	GetOptions();
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
			textcolor(14);
			printf("\nEncrypting...\n");
			InputLen = GetInput(&String);

			Encrypt(String, InputLen);

			textcolor(InputColor);
			printf("\nPress something to continue.");
			GetChar = _getch();
		}
		else if (Option == '2') {
			textcolor(14);
			printf("\nDecrypting...\n");
			InputLen = GetInput(&String);

			Decrypt(String, InputLen);

			textcolor(InputColor);
			printf("\nPress something to continue.");
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

void GetOptions() {
	const char* FileName = "options.txt";
	FILE* FileToRead;
	char Znak[5];
	FileToRead = fopen(FileName, "r");
	if (FileToRead == NULL) {
		printf("The options file is empty or does not exist.\n");

		FILE* FileToWrite;
		char Option[5];

		printf("Is your editor in light(1) or dark(0) mode?\nPlease enter: ");
		fgets(Option, 2, stdin);
		FileToWrite = fopen(FileName, "w");
		fprintf(FileToWrite, "%s   - Console theme 0 - dark, 1 - light\n", Option);
		fprintf(FileToWrite, "     - Locale\n");

		fclose(FileToWrite);

		FileToRead = fopen(FileName, "r");
		fgets(Znak, 5, FileToRead);
		if ((int)Znak[0] == '0')
			InputColor = 15;
		else
			InputColor = 0;
		fgets(Znak, 5, FileToRead);
		setlocale(LC_ALL, "");

		fclose(FileToRead);
	}
	else {
		fgets(Znak, 5, FileToRead);
		if ((int)Znak[0] == '0')
			InputColor = 15;
		else
			InputColor = 0;
		fgets(Znak, 5, FileToRead);
		setlocale(LC_ALL, "");

		fclose(FileToRead);
	}
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
			if (Input[i] >= 65 && Input[i] <= 90)
				(*Text)[i] = Input[i] + 32;
			else
				(*Text)[i] = Input[i];
		}
	}
	InputLen -= 2;

	return InputLen;
}

void Encrypt(char* Text, int InputLen) {
	//printf("%s", Text);
	int TabLen = InputLen * 4;
	char* Encrypted = (char*)malloc(TabLen * 2);
	int* Code = (int*)malloc(InputLen);
	int CurrIndex = 0, CurrElement = 1, CurrCode = 0, tmp[] = { 0,0 };
	if (Encrypted) {
		for (int i = 0; i < TabLen; i++) {
			Encrypted[i] = NULL;
		}
		for (int i = 0; i <= InputLen; i++) {
			if (Text[i] == 'j' || Text[i] == 'q')
				Encrypted = "no possibility";
		}
		if (Encrypted[0] != 'n') {
			while (CurrIndex < InputLen) {
				//printf("E%d\n", CurrElement);
				if (Elements[CurrElement][0] == Text[CurrIndex]) {
					//printf("I%d\n", CurrIndex);
					CurrIndex++;
					if (ElementsLen[CurrElement] > 1) {
						if (Elements[CurrElement][1] == Text[CurrIndex]) {
							Code[CurrCode] = CurrElement;
							CurrCode++;
							CurrElement = 1;
							CurrIndex++;
						}
						else {
							CurrElement++;
							CurrIndex--;
						}
					}
					else {
						Code[CurrCode] = CurrElement;
						CurrCode++;
						CurrElement = 1;
					}
				}
				else if (Text[CurrIndex] == ' ') {
					CurrIndex++;
					Code[CurrCode] = 0;
					CurrCode++;
					CurrElement = 1;
				}
				else {
					CurrElement++;
				}
				if (CurrElement >= sizeof(ElementsLen) / 4) {
					//printf("sizeof\n");
					if (CurrIndex == 0 || Code[CurrCode - 1] >= sizeof(ElementsLen) / 4 - 1 || Code[CurrCode - 1] == 0) {
						Encrypted = "no possibility";
						break;
					}
					else {
						CurrIndex -= ElementsLen[Code[--CurrCode]];
						CurrElement = Code[CurrCode] + 1;
					}
				}
			}
		}
		if (Encrypted[0] != 'n') {
			TabLen = CurrCode;
			CurrIndex = 0;
			for (int i = 0; i < TabLen; i++) {
				//printf("C%d\n", Code[i]);
				while (Code[i] >= 1) {
					if (Code[i] >= 100) {
						tmp[0] = Code[i] / 100;
						tmp[1] = tmp[0] * 100;
						Encrypted[CurrIndex] = tmp[0] + 48;
						Code[i] -= tmp[1];
						if (Code[i] < 1) {
							Encrypted[++CurrIndex] = 48;
						}
						if (Code[i] < 10) {
							Encrypted[++CurrIndex] = 48;
						}
					}
					else if (Code[i] >= 10) {
						tmp[0] = Code[i] / 10;
						tmp[1] = tmp[0] * 10;
						Encrypted[CurrIndex] = tmp[0] + 48;
						Code[i] -= tmp[1];
						if (Code[i] < 1) {
							Encrypted[++CurrIndex] = 48;
						}
					}
					else {
						tmp[0] = Code[i];
						tmp[1] = tmp[0];
						Encrypted[CurrIndex] = tmp[0] + 48;
						Code[i] -= tmp[1];
					}

					CurrIndex++;
				}
				if (i != TabLen - 1)
					Encrypted[CurrIndex] = '*';
				CurrIndex++;
			}
		}

		textcolor(3);
		printf("Output is: ");
		textcolor(InputColor);
		printf("%s\n", Encrypted);
	}
}

void Decrypt(char* Text, int InputLen) {
	//printf("%s", Text);
	int TabLen = 1;
	char* Decrypted;
	int tmp[5] = { 0,0,0,0,0 };
	int tmp1 = 0;
	int CurrIndex = 0;
	for (int i = 0; i < InputLen; i++) {
		if (Text[i] == '*') {
			TabLen++;
		}
	}
	TabLen *= 8;
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
			else if (Text[i] >= 32 && Text[i] <= 126 && Text[i] != '*') {
				Decrypted = "no possibility";
				break;
			}
			if (Text[i] == '*' || i == InputLen - 1) {
				if (tmp[0] > 0) {
					for (int j = 1; j <= tmp[0]; j++) {
						tmp1 += (int)pow(10, tmp[0] - j) * tmp[j];
					}
					if (tmp1 > 118) {
						Decrypted = "no possibility";
						break;
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
		textcolor(3);
		printf("Output is: ");
		textcolor(InputColor);
		printf("%s\n", Decrypted);
	}
}