#include"Console.h"
#include"DataStructure.h"
#include"Map.h"

class Snake
{
public:
	Snake();
	void headInset(int x, int y);
	void tailPop();
	void movement(Map* map, const char c);
	void printNode(Node* list);

private:
	Node* list;
};