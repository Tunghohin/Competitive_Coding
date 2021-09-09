#include <iostream>
#include <cstring>

using namespace std;

struct edge
{
	int to, val, next;
}e[20010];
int head[10010], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0 ; i < m; i++)
	{
		int f, t, v;
		cin >> f >> t >> v;
		add_edge(f, t, v), add_edge(t, f, v);
	}
}