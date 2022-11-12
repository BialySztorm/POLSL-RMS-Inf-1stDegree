#pragma once
#include "translator.h"

class Main {
public:
	Main();
private:
	bool IsRunning = true;
	char Option = 0;
	int InputColor = 15;
	Translator Obj;
	const int TabLen = 10000;
	char Input[10000];
	int InputLen;
	char* String = nullptr;
	char GetChar;

	void ShowGui();
	void GetInput();
};