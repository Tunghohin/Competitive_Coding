#include <iostream>
#include <queue>
#include <cstring>
#define nullptr 0

using namespace std;

struct edge
{
	int to, val, next;
}e[10010];
int head[510], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

int dist[510], cnt[510];
bool in_que[510];
bool spfa(int n)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
		in_que[i] = true;
		dist[i] = 0;
		cnt[i] = 0;
	}

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		in_que[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (dist[j] > dist[u] + e[i].val)
			{
				dist[j] = dist[u] + e[i].val;
				cnt[j] = cnt[u] + 1;

				if (cnt[j] >= n) return true;

				if (!in_que[j])
				{
					q.push(j);
					in_que[j] = true;
				}
			}
		}
	}

	return false;
}

void solve()
{
	memset(head, 0, sizeof(head));
	tot = 0;

	int n, m, w;
	cin >> n >> m >> w;

	for (int i = 1; i <= m; i++)
	{
		int f, t, v;
		cin >> f >> t >> v;
		add_edge(f, t, v);
		add_edge(t, f, v);
	}

	for (int i = 1; i <= w; i++)
	{
		int f, t, v;
		cin >> f >> t >> v;
		add_edge(f, t, -v);
	}

	if (spfa(n)) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}