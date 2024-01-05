#include "Snake.h"

Snake::Snake()
{
	list = new Node;
	list->x = 0;
	list->y = 0;
	list->pre = list;
	list->next = list;
}

void Snake::headInset(int x, int y)
{
	Node* node = new Node;
	node->x = x;
	node->y = y;
	node->next = list->next;
	node->pre = list;
	list->next->pre = node;
	list->next = node;
}

void Snake::tailPop()
{
	Node* node = list->pre;
	node->pre->next = list;
	list->pre = node->pre;
	delete node;
}

void Snake::movement(Map * map, const char c)
{
	int x = list->next->x;
	int y = list->next->y;
	switch (c)
	{
	case 'w':
		y -= 1;
		break;
	case 'a':
		x -= 1;
		break;
	case 'd':
		x += 1;
		break;
	case 's':
		y += 1;
		break;
	}

	if (c != ' ')
	{
		map->isEnd(list, x, y);
		if (map->getMap()[y][x] == '*')
		{
			headInset(x, y);
			map->setElement(x, y, '1');
			map->printElement(x, y, "¡ñ", 6);
			map->food--;
		}
		else
		{
			if (map->getMap()[y][x] == '#')
			{
				if (c == 'w')
				{
					y = map->width - 2;
				}
				else if (c == 's')
				{
					y = 1;
				}
				else if (c == 'a')
				{
					x = map->length - 2;
				}
				else
				{
					x = 1;
				}
			}
			map->setElement(list->pre->x, list->pre->y, '0');
			map->printElement(list->pre->x, list->pre->y, "  ", 0);
			headInset(x, y);
			map->setElement(x, y, '1');
			map->printElement(x, y, "¡ñ", 6);
			tailPop();
		}
	}
}

void Snake::printNode(Node * list)
{
	Node* node = list->next;
	while (node != list)
	{
		cout << "(" << node->x << "," << node->y << ") -> " << endl;
		node = node->next;
	}
}
