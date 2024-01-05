#include"Console.h"

void gotoxy(int x, int y)
{
	x *= 2;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void COLOR_PRINT(string s, int color)
{		//	0 = ��ɫ 8 = ��ɫ
		//	1 = ��ɫ 9 = ����ɫ
		//	2 = ��ɫ 10 = ����ɫ
		//	3 = ǳ��ɫ 11 = ��ǳ��ɫ
		//	4 = ��ɫ 12 = ����ɫ
		//	5 = ��ɫ 13 = ����ɫ
		//	6 = ��ɫ 14 = ����ɫ
		//	7 = ��ɫ 15 = ����ɫ
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	cout << s;
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}

void cls(int length, int width)
{
	gotoxy(0, 0);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << "  ";
		}
		gotoxy(0, i);
	}
	gotoxy(0, 0);
}

void hideCursor()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(hOut, &cci);
}

void cOutput(string str, int y)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOutput, &bInfo);
	int dwSizeX = bInfo.dwSize.X;
	int len = str.length();
	int x = (dwSizeX / 2 - len / 2) / 2;
	gotoxy(x, y);
	cout << str;
}
