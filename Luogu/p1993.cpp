#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct edge
{
	int to, val, next;
}e[10010];
int head[5010], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

long long dist[5010];
bool vis[5010];
int cnt[5010];

bool spfa(int n)
{
	memset(dist, 0, sizeof(dist));
	memset(vis, false, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	queue<int> q;

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

	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int op;
		int f, t, v;
		cin >> op;

		if (op == 1)
		{
			cin >> f >> t >> v;
			add_edge(f, t, -v);
		}
		else if (op == 2)
		{
			cin >> f >> t >> v;
			add_edge(t, f, v);
		}
		else if (op == 3)
		{
			cin >> f >> t;
			add_edge(f, t, 0);
			add_edge(t, f, 0);
		}
	}

	bool res = spfa(n);
	if (res) cout << "Yes\n";
	else cout << "No\n";
}