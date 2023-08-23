// skipcq: CXX-W2030
#include <stdio.h>
#include <conio.h>
// skipcq: CXX-W2030
#include <locale.h>
#include <math.h>
#include <string.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
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

//void GetOptions();
int GetPadding(int TotalWidth, char* s);
void ShowGui();
int GetInput(char** Text);
void Encrypt(char* Text, int InputLen);
void Decrypt(char* Text, int InputLen);

int main() {
	//GetOptions();
	// skipcq: CXX-W2022
	setlocale(LC_ALL, "");
	int IsRunning = 1;
	char Option = 0;
	int InputLen;
	char* String = nullptr;
	char GetChar;
	int TotalWidth;

	// skipcq: CXX-W2065
	while (IsRunning) {
		TotalWidth = GetColumnWidth();
		ShowGui();
		// max char[] size  2 ^ 32 -1
		printf("\033[0m");
		Option = _getch();

		if (Option == '0')
			IsRunning = 0;
		else if (Option == '1') {
			printf("\033[0;33m");
			printf("\n%*s", TotalWidth / 2 + 7, "Szyfrowanie...\n");
			InputLen = GetInput(&String);
			if (InputLen > 0)
				Encrypt(String, InputLen);

			printf("\033[0m");
			printf("\n%*s", TotalWidth / 2 + 15, "Naci�nij cokolwiek aby kontynuowa�.");
			GetChar = _getch();
		}
		else if (Option == '2') {
			printf("\033[0;33m");
			printf("\n%*s", TotalWidth / 2 + 7, "Deszyfrowanie...\n");
			InputLen = GetInput(&String);
			if (InputLen > 0)
				Decrypt(String, InputLen);

			printf("\033[0m");
			printf("\n%*s", TotalWidth / 2 + 15, "Naci�nij cokolwiek aby kontynuowa�.");
			GetChar = _getch();
		}
		else {
			printf("\033[0;31m");
			printf("%*s", TotalWidth / 2 + 6, "B��dne dane!");
			GetChar = _getch();
		}
	}

	return 0;
}

//void GetOptions() {
//	setlocale(LC_ALL, "");
//	const char* FileName = "options.txt";
//	FILE* FileToRead;
//	char Znak[5];
//	FileToRead = fopen(FileName, "r");
//	if (FileToRead == NULL) {
//		printf("The options file is empty or does not exist.\n");
//
//		FILE* FileToWrite;
//		char Option[5];
//
//		FileToWrite = fopen(FileName, "w");
//		fprintf(FileToWrite, "");
//
//		fclose(FileToWrite);
//
//		FileToRead = fopen(FileName, "r");
//		fgets(Znak, 5, FileToRead);
//
//		fclose(FileToRead);
//	}
//	else {
//		fgets(Znak, 5, FileToRead);
//
//		fclose(FileToRead);
//	}
//}

int GetPadding(int TotalWidth, char* s) {
	int sWidth = strlen(s);
	int FieldWidth = (TotalWidth - sWidth) / 2 + sWidth;
	return FieldWidth;
}

void ShowGui()
{
	const int TotalWidth = GetColumnWidth();
	char* s;

	// skipcq: CXX-A1001
	system("cls");
	printf("\033[0;35m");
	printf("\n\n\n");
	s = "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	s = "|S|z|y|f|r|a|t|o|r| |M|e|n|d|e|l|e|j|e|w|a|   |v|1|.|0|.|2|\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	s = "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	s = "Stworzony przez Andrzej Manderla\n\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	s = "Wybierz opcj�:\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	s = "[1] - Szyfruj  \n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	s = "[2] - Deszyfruj\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	s = "[0] - Zako�cz  \n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
	s = "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	printf("%*s\n", GetPadding(TotalWidth, s), s);
}

int GetInput(char** Text)
{
	const int TotalWidth = GetColumnWidth();
	const int TabLen = 10000;
	// skipcq: CXX-W2066
	char Input[TabLen];
	printf("\033[0;34m");
	printf("\n%*s", TotalWidth / 2, "Dane wej�ciowe: ");
	printf("\033[0m");
	// skipcq: CXX-W2022
	fgets(Input, TabLen, stdin);
	// skipcq: CXX-C2013
	int InputLen = 0, error = 0;
	for (int i = 0; i < TabLen; i++) {
		if (Input[i] == 0 || Input[i] == 10)
		{
			break;
		}
		//printf("%c, ", Input[i]);
		InputLen++;
	}
	if (InputLen <= 0)
		error = 2;
	//printf("\nlen: %d\n", InputLen);
	*Text = (char*)malloc(InputLen * sizeof(char));
	for (int i = 0; i < InputLen * sizeof(char); i++) {
		(*Text)[i] = NULL;
	}
	// skipcq: CXX-W2065
	if (*Text) {
		for (int i = 0; i < InputLen; i++) {
			if (Input[i] >= 65 && Input[i] <= 90)
				(*Text)[i] = Input[i] + 32;
			else if (Input[i] != ' ' && Input[i] != '*' && Input[i] <= '/' || Input[i] >= ':' && Input[i] <= '`' || Input[i] >= '{') {
				error = 1;
				break;
			}
			else
				(*Text)[i] = Input[i];
		}
	}
	// skipcq: CXX-W2065
	if (error) {
		printf("\033[0;31m");
		if (error == 1) {
			printf("\n%*s", TotalWidth / 2 + 6, "B��dne dane!");
			InputLen = 0;
		}
		else if (error == 2) {
			printf("\n%*s", TotalWidth / 2 + 7, "Puste wej�cie!");
		}
	}

	return InputLen;
}

// skipcq: CXX-C2014
void Encrypt(char* Text, int InputLen) {
	const int TotalWidth = GetColumnWidth();
	//printf("%s", Text);
	int TabLen = InputLen * 4;
	char* Encrypted = (char*)malloc(TabLen * sizeof(char));
	int* Code = (int*)malloc(InputLen * sizeof(int));
	// skipcq: CXX-C2013
	int CurrIndex = 0, CurrElement = 1, CurrCode = 0, tmp[] = { 0,0 };
	// skipcq: CXX-W2065
	if (Encrypted) {
		for (int i = 0; i < TabLen; i++) {
			Encrypted[i] = NULL;
		}
		for (int i = 0; i <= InputLen; i++) {
			if (Text[i] == 'j' || Text[i] == 'q') {
				Encrypted = "Nie ma mo�liwo�ci";
			}
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
						Encrypted = "Nie ma mo�liwo�ci";
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

		printf("\033[0;34m");
		printf("%*s", TotalWidth / 2, "Dane wyj�ciowe: ");
		printf("\033[0m");
		printf("%s\n", Encrypted);

		if (Encrypted[0] != 'N') {
			free(Encrypted);
		}
		free(Code);
	}
}

// skipcq: CXX-C2014
void Decrypt(char* Text, int InputLen) {
	const int TotalWidth = GetColumnWidth();
	//printf("%s", Text);
	int TabLen = 1;
	char* Decrypted;
	// skipcq: CXX-W2066
	int tmp[5] = { 0,0,0,0,0 };
	int tmp1 = 0;
	int CurrIndex = 0;
	for (int i = 0; i < InputLen; i++) {
		if (Text[i] == '*') {
			TabLen++;
		}
	}
	TabLen *= 4;
	//printf("%d", TabLen);
	Decrypted = (char*)malloc(TabLen * sizeof(char));
	// skipcq: CXX-W2065
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
				Decrypted = "Nie ma mo�liwo�ci";
				break;
			}
			if (Text[i] == '*' || i == InputLen - 1) {
				if (tmp[0] > 0) {
					for (int j = 1; j <= tmp[0]; j++) {
						tmp1 += (int)pow(10, tmp[0] - j) * tmp[j];
					}
					if (tmp1 > 118) {
						Decrypted = "Nie ma mo�liwo�ci";
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
		printf("\033[0;34m");
		printf("%*s", TotalWidth / 2, "Dane wyj�ciowe: ");
		printf("\033[0m");
		printf("%s\n", Decrypted);
	}
	if (Decrypted[0] != 'N')
		free(Decrypted);
}