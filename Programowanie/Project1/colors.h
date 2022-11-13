#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void textcolor(int Color)
{
	static int __BACKGROUND;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		Color + (__BACKGROUND << 4));
}

/*
Colors:
0 - Black
1 - Blue
2 - Green
3 - Cyan
4 - Red
5 - Magenta
6 - Brown
7 - Light gray
8 - Dark gray
9 - Light blue
10 - Light green
11 - Light cyan
12 - Light red
13 - Light magenta
14 - Yellow
15 - White
*/