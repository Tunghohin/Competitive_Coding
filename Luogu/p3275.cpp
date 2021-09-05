#pragma GCC optimize(2)

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct edge
{
	int to, val, next;
}e[300010];
int head[100010], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

int dist[100010];
bool vis[100010];
int cnt[100010];
int q[100010];

bool spfa(int &n)
{
	int hh = 0, tt = 1;
	memset(dist, -0x3f, sizeof dist);
	dist[0] = 0;
	q[0] = 0;
	vis[0] = true;

	while (hh != tt)
	{
		int t = q[ -- tt];
		vis[t] = false;

		for (int i = head[t]; i; i = e[i].next)
		{
			int j = e[i].to;
			if (dist[j] < dist[t] + e[i].val)
			{
				dist[j] = dist[t] + e[i].val;
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n + 1) return false;
				if (!vis[j])
				{
					q[tt ++ ] = j;
					vis[j] = true;
				}
			}
		}
	}

	return true;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	while (m--)
	{
		int x, a, b;
		scanf("%d%d%d", &x, &a, &b);
		if (x == 1) add_edge(b, a, 0), add_edge(a, b, 0);
		else if (x == 2) add_edge(a, b, 1);
		else if (x == 3) add_edge(b, a, 0);
		else if (x == 4) add_edge(b, a, 1);
		else add_edge(a, b, 0);
	}

	for (int i = 1; i <= n; i++) add_edge(0, i, 1);

	if (!spfa(n)) puts("-1");
	else
	{
		long long res = 0;
		for (int i = 1; i <= n; i++) res += dist[i];
		printf("%lld\n", res);
	}
}