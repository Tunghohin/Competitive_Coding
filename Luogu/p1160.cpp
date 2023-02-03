#include <iostream>

using namespace std;

struct node
{
	int data;
	node* prev;
	node* next;
};
node* list[100010];

int main()
{
	int n;
	cin >> n;

	int head = 1;
	list[1] = new node;
	list[1]->data = 1;
	list[1]->next = nullptr;
	list[1]->prev = nullptr;
	for (int i = 2; i <= n; i++)
	{
		int id, op;
		cin >> id >> op;
		list[i] = new node;
		list[i]->data = i;

		if (op == 0)
		{
			if (list[id]->prev != nullptr)
			{
				list[i]->prev = list[id]->prev;
				list[i]->next = list[id];
				list[id]->prev->next = list[i];
				list[id]->prev = list[i];
			}
			else
			{
				head = i;
				list[i]->next = list[id];
				list[id]->prev = list[i];
			}
		}
		else
		{
			if (list[id]->next != nullptr)
			{
				list[i]->next = list[id]->next;
				list[i]->prev = list[id];
				list[id]->next->prev = list[i];
				list[id]->next = list[i];
			}
			else
			{
				list[id]->next = list[i];
				list[i]->prev = list[id];
			}
		}
	}

	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int id;
		cin >> id;

		if (list[id] == nullptr) continue;
		if (list[id]->prev != nullptr)
		{
			list[id]->prev->next = list[id]->next;
		}
		if (list[id]->next != nullptr)
		{
			list[id]->next->prev = list[id]->prev;
		}

		list[id]->prev = nullptr;
		list[id]->next = nullptr;
		delete list[id];
		list[id] = nullptr;
	}

	node* now = list[head];
	while (now != nullptr)
	{
		cout << now->data << ' ';
		now = now->next;
	}
}