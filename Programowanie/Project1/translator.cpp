#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include "translator.h"
#include "colors.h"

void Translator::Check()
{
	textcolor(3);
	printf("Hello World!\n");
}

char* Translator::Encrypt(char* Text)
{
	for (int i = 0; i < sizeof(Text) - 1; i++) {
		printf("%c\n", *(Text + i));
	}
	return Text;
}

char* Translator::Decrypt(char* Text)
{
	return Text;
}

Translator::Translator()
{
	Elements = Obj.getElements();
}