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
{		//	0 = 黑色 8 = 灰色
		//	1 = 蓝色 9 = 淡蓝色
		//	2 = 绿色 10 = 淡绿色
		//	3 = 浅绿色 11 = 淡浅绿色
		//	4 = 红色 12 = 淡红色
		//	5 = 紫色 13 = 淡紫色
		//	6 = 黄色 14 = 淡黄色
		//	7 = 白色 15 = 亮白色
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
