#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include "colors.h"
#include "data.h"

#ifdef _WIN32
#include <Windows.h>
int GetColumnWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	HANDLE out;

	if (!(out = GetStdHandle(STD_OUTPUT_HANDLE)) ||
		!GetConsoleScreenBufferInfo(out, &info))
		return 80;
	return info.dwSize.X;
}//GetColumnWidth
#else
int GetColumnWidth() { return 80; }
#endif

int InputColor = 0;

void GetOptions();
int GetPadding(int TotalWidth, char* s);
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
	int TotalWidth;

	while (IsRunning) {
		TotalWidth = GetColumnWidth();
		ShowGui();
		// max char[] size  2 ^ 32 -1
		textcolor(InputColor);
		Option = _getch();

		if (Option == '0')
			IsRunning = 0;
		else if (Option == '1') {
			textcolor(14);
			printf("\n%*s", TotalWidth / 2 + 7, "Szyfrowanie...\n");
			InputLen = GetInput(&String);

			Encrypt(String, InputLen);

			textcolor(InputColor);
			printf("\n%*s", TotalWidth / 2 + 15, "Naciœnij cokolwiek aby kontynuowaæ.");
			GetChar = _getch();
		}
		else if (Option == '2') {
			textcolor(14);
			printf("\n%*s", TotalWidth / 2 + 7, "Deszyfrowanie...\n");
			InputLen = GetInput(&String);

			Decrypt(String, InputLen);

			textcolor(InputColor);
			printf("\n%*s", TotalWidth / 2 + 15, "Naciœnij cokolwiek aby kontynuowaæ.");
			GetChar = _getch();
		}
		else {
			textcolor(4);
			printf("%*s", TotalWidth / 2 + 6, "B³êdne dane!");
			GetChar = _getch();
		}
	}

	return 0;
}

void GetOptions() {
	setlocale(LC_ALL, "");
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

		fclose(FileToWrite);

		FileToRead = fopen(FileName, "r");
		fgets(Znak, 5, FileToRead);
		if ((int)Znak[0] == '0')
			InputColor = 15;
		else
			InputColor = 0;

		fclose(FileToRead);
	}
	else {
		fgets(Znak, 5, FileToRead);
		if ((int)Znak[0] == '0')
			InputColor = 15;
		else
			InputColor = 0;

		fclose(FileToRead);
	}
}

int GetPadding(int TotalWidth, char* s) {
	int sWidth = strlen(s);
	int FieldWidth = (TotalWidth - sWidth) / 2 + sWidth;
	return FieldWidth;
}

void ShowGui()
{
	const int TotalWidth = GetColumnWidth();
	char* s;

	system("cls");
	textcolor(5);
	printf("\n\n\n");
	s = "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	textcolor(13);
	s = "|S|z|y|f|r|a|t|o|r| |M|e|n|d|e|l|e|j|e|w|a|   |v|1|.|0|.|2|\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	textcolor(5);
	s = "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	textcolor(13);

	s = "Stworzony przez Andrzej Manderla\n\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	s = "Wybierz opcjê:\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	s = "[1] - Szyfruj  \n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	s = "[2] - Deszyfruj\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	s = "[0] - Zakoñcz  \n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	textcolor(5);
	s = "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
}

int GetInput(char** Text)
{
	const int TotalWidth = GetColumnWidth();
	const int TabLen = 10000;
	char Input[TabLen];
	textcolor(3);
	printf("\n%*s", TotalWidth / 2, "Dane wejœciowe: ");
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
	const int TotalWidth = GetColumnWidth();
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
				Encrypted = "Nie ma mo¿liwoœci";
		}
		if (Encrypted[0] != 'N') {
			while (CurrIndex < InputLen) {
				//printf("E%d\n", CurrElement);
				if (Elements[CurrElement][0] == Text[CurrIndex]) {
					//printf("I%d\n", CurrIndex);
					CurrIndex++;
					if (ElementsLen[CurrElement] > 1) {
						if (Elements[CurrElement][1] == Text[CurrIndex] && CurrIndex != InputLen) {
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
						Encrypted = "Nie ma mo¿liwoœci";
						break;
					}
					else {
						CurrIndex -= ElementsLen[Code[--CurrCode]];
						CurrElement = Code[CurrCode] + 1;
					}
				}
			}
		}
		if (Encrypted[0] != 'N') {
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
		printf("%*s", TotalWidth / 2, "Dane wyjœciowe: ");
		textcolor(InputColor);
		printf("%s\n", Encrypted);
	}
}

void Decrypt(char* Text, int InputLen) {
	const int TotalWidth = GetColumnWidth();
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
				Decrypted = "Nie ma mo¿liwoœci";
				break;
			}
			if (Text[i] == '*' || i == InputLen - 1) {
				if (tmp[0] > 0) {
					for (int j = 1; j <= tmp[0]; j++) {
						tmp1 += (int)pow(10, tmp[0] - j) * tmp[j];
					}
					if (tmp1 > 118) {
						Decrypted = "Nie ma mo¿liwoœci";
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
		printf("%*s", TotalWidth / 2, "Dane wyjœciowe: ");
		textcolor(InputColor);
		printf("%s\n", Decrypted);
	}
}