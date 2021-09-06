#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct edge
{
	int to, val, next;
}e[20010];
int head[1010], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

int dist[1010];
bool vis[1010];
int cnt[1010];
bool spfa(int n, int size)
{
	queue<int> q;
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, false, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));

	for (int i = 1; i <= size; i++)
	{
		q.push(i);
		dist[i] = 0;
		vis[i] = true;
	}

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (dist[j] > dist[u] + e[i].val)
			{
				dist[j] = dist[u] + e[i].val;
				cnt[j] = cnt[u] + 1;

				if (cnt[j] >= n) return false;
				if (!vis[j])
				{
					q.push(j);
					vis[j] = true;
				}
			}
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, L, D;
	cin >> n >> L >> D;

	for (int i = 2; i <= n; i++) add_edge(i, i - 1, -1);

	while (L--)
	{
		int f, t, v;
		cin >> f >> t >> v;
		add_edge(f, t, v);
	}

	while (D--)
	{
		int f, t, v;
		cin >> f >> t >> v;
		add_edge(t, f, -v);
	}

	if (!spfa(n, n)) cout << -1 << '\n';
	else
	{
		spfa(n, 1);
		if (dist[n] == 0x3f3f3f3f) cout << -2 << '\n';
		else cout << dist[n] << '\n';
	}
}