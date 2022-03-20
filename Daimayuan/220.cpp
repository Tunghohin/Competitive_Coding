#include <iostream>

using namespace std;

const int N = 100010;

int size[N];

struct edge
{
	int to, next;
}e[100010];
int head[100010], tot;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

void dfs(int u)
{
	size[u] = 1;
	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		dfs(j);
		size[u] += size[j];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		add_edge(x, i);
	}

	dfs(1);

	for (int i = 1; i <= n; i++) cout << size[i] << ' ';
}