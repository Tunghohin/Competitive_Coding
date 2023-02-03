#include <iostream>

using namespace std;

struct node
{
	int data;
	node* prev;
	node* next;
} list[110];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		list[i].data = i;
		list[i].prev = &list[(i - 1 + n) % n];
		list[i].next = &list[(i + 1) % n];
	}
	list[0].data = n;

	int cnt = 0;
	node* now = &list[1];
	int delected = 0;
	while (delected < n)
	{
		cnt++;
		if (cnt == m)
		{
			cnt = 0;
			cout << now->data << ' ';
			now->next->prev = now->prev;
			now->prev->next = now->next;
			delected++;
		}

		now = now->next;
	}
}