#pragma once
#include "data.h"

class Translator {
public:
	Translator();
	void Check();

	char* Encrypt(char* Text);
	char* Decrypt(char* Text);

private:
	Data Obj;
	char* Elements;
};