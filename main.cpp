#include"Console.h"
#include"Snake.h"

using namespace std;

void initGame(Map& map, Snake& snake, char& direction)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	hideCursor();

	int length, width;
	vector<int> initPos_X, initPos_Y;

	cout << "设置: 起始蛇的长度" << endl;
	cin >> length;
	int x, y;
	for (int i = 0; i < length; i++)
	{
		cout << "输入: 蛇的第" << i + 1 << "段的 (x,y)" << endl;
		cin >> x >> y;
		initPos_X.push_back(x + 1);
		initPos_Y.push_back(y + 1);
		snake.headInset(x + 1, y + 1);
	}

	cout << "设置: 地图长宽" << endl;
	cin >> length >> width;
	map.initMap(length, width, initPos_X, initPos_Y);
	cout << "设置: 蛇的起始移动方向" << endl;
	cin >> direction;
	cls(length, width);
	map.printMap();
}

int main()
{
	Map map;
	Snake snake;
	char input = ' ';
	initGame(map, snake, input);

	while (true)
	{	
		if (GetAsyncKeyState('W') & 0x8001 && input != 's') {
			input = 'w';
		}
		else if (GetAsyncKeyState('A') & 0x8001 && input != 'd') {
			input = 'a';
		}
		else if (GetAsyncKeyState('S') & 0x8001 && input != 'w') {
			input = 's';
		}
		else if (GetAsyncKeyState('D') & 0x8001 && input != 'a') {
			input = 'd';
		}

		snake.movement(&map, input);
		map.generateFood();
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	
	return 0;
}