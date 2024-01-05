#include"Console.h"
#include"DataStructure.h"

struct Node
{
	int x;
	int y;
	Node* pre;
	Node* next;
};

class Map
{
public:
	void initMap(int& length, int& width, vector<int>& initX, vector<int>& initY);
	void setElement(int x, int y, char data);
	void printElement(int x, int y, string data, int color);
	void printMap();
	void generateFood();
	vector<string> getMap();
	void isEnd(Node* list, int x, int y);

	int food = 0;
	int length;
	int width;

private:
	vector<string> map;
};