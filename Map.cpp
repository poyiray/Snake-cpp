#include"Map.h"

void Map::initMap(int& length, int& width, vector<int>& initX, vector<int>& initY)
{
	map.resize(width);
	this->length = length;
	this->width = width;
	int index = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i == 0 || i == width - 1 || j == 0 || j == length - 1)
			{
				map[i] += "#";
			}
			else if (i == initY[index] && j == initX[index])
			{
				map[i] += "1";
				if (initY.size() - 1 != index)
				{
					index++;
				}
			}
			else
			{
				map[i] += "0";
			}
		}
	}
}

void Map::setElement(int x, int y, char data)
{
	map[y][x] = data;
}

void Map::printElement(int x, int y, string data, int color)
{

	gotoxy(x, y);
	COLOR_PRINT(data, color);
}

void Map::printMap()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (map[i][j] == '#')
			{
				COLOR_PRINT("■", 2);
			}
			else if (map[i][j] == '1')
			{
				COLOR_PRINT("●", 6);
			}
			else if (map[i][j] == '*')
			{
				COLOR_PRINT("◆", 4);
			}
			else if (map[i][j] == '0')
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}

void Map::generateFood()
{
	if (food < 1)
		for (int i = 0; i < 4; i++)
		{
			int min = 1, max = length - 2;
			random_device seed;//硬件生成随机数种子
			ranlux48 engine(seed());//利用种子生成随机数引擎
			uniform_int_distribution<> distrib(min, max);//设置随机数范围，并为均匀分布
			int random_x = distrib(engine);//随机数

			min = 1, max = width - 2;
			random_device seed1;//硬件生成随机数种子
			ranlux48 engine1(seed1());//利用种子生成随机数引擎
			uniform_int_distribution<> distrib1(min, max);//设置随机数范围，并为均匀分布
			int random_y = distrib1(engine);//随机数

			if (map[random_y][random_x] != '1')
			{
				map[random_y][random_x] = '*';
				gotoxy(random_x, random_y);
				COLOR_PRINT("◆", 4);
				food++;
			}
		}
}

vector<string> Map::getMap()
{
	return map;
}

void Map::isEnd(Node * list, int x, int y)
{
	if (map[y][x] == '1')
	{
		exit(0);
	}
}
