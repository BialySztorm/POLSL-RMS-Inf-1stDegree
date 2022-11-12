#pragma once

class Translator {
public:
	Translator();
	void Check();

	char* Encrypt(char* Text, int TabLen);
	char* Decrypt(char* Text, int TabLen);

private:
	char* Elements;
};