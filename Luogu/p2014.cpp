#include <iostream>

using namespace std;

struct edge
{
	int to, next;
}e[330];
int head[330], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int t, v;
		cin >> t >> v;
		add_edge(i, t);
	}


}