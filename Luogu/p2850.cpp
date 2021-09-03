#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int cnt[550];
struct edge
{
	int t, v, next;
}e[10010];
int head[550], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].t = to;
	e[tot].v = val;
	e[tot].next = head[from];
	head[from] = tot;
}

void init()
{
	tot = 0;
	memset(head, 0, sizeof(head));
}

int dist[550];
bool vis[550];
bool spfa(int &n)
{
	queue<int> q;
	memset(dist, 0, sizeof(dist));
	memset(cnt, 0, sizeof(cnt));
	memset(vis, false, sizeof(vis));

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
		vis[i] = true;
	}

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].t;

			if (dist[j] > dist[u] + e[i].v)
			{
				dist[j] = dist[u] + e[i].v;
				cnt[j] = cnt[u] + 1;

				if (cnt[j] >= n) return true;

				if (!vis[j])
				{
					q.push(j);
					vis[j] = true;
				}
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int n, m, w;
		cin >> n >> m >> w;

		init();

		while (m--)
		{
			int f, t, v;
			cin >> f >> t >> v;
			add_edge(f, t, v);
			add_edge(t, f, v);
		}

		while (w--)
		{
			int f, t, v;
			cin >> f >> t >> v;
			add_edge(f, t, -v);
		}

		if(spfa(n)) cout << "YES\n";
		else cout << "NO\n";
	}
}