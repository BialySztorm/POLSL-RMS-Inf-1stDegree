#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include "translator.h"
#include "data.h"

#include "stdio.h"

void Translator::Check()
{
	Elements = new char[sizeof(elements)];
	Elements = elements;
	printf("%s", Elements[1]);
}

char* Translator::Encrypt(char* Text, int TabLen)
{
	/*for (int i = 0; i < TabLen; i++) {
		printf("%c\n", *(Text + i));
	}*/
	return Text;
}

char* Translator::Decrypt(char* Text, int TabLen)
{
	return Text;
}

Translator::Translator()
{
	Elements = Obj.getElements();
}