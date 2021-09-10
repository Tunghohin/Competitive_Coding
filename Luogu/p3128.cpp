#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct edge
{
	int to, next;
}e[100010];
int head[50010], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int depth[50010];
int f[50010][15];
void bfs(int root)
{
	queue<int> q;
	memset(depth, 0x3f, sizeof(depth));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b), add_edge(b, a);
	}
}