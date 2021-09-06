#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

struct edge
{
	int to, val, next;
}e[10010];
int head[10010], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

int dist[10010];
bool vis[10010];
bool spfa(int n, int size)
{
	stack<int> q;
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, false, sizeof(vis));

	int in_cnt = 0;

	for (int i = 1; i <= size; i++)
	{
		q.push(i);
		vis[i] = true;
		in_cnt++;
	}

	while (!q.empty())
	{
		int u = q.top();
		q.pop();
		vis[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (dist[j] > dist[u] + e[i].val)
			{
				dist[j] = dist[u] + e[i].val;

				if (!vis[j])
				{
					q.push(j);
					vis[j] = true;
					in_cnt++;
					if (in_cnt >= 4 * n) return false;
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
		int a, b, v;
		cin >> a >> b >> v;
		add_edge(b, a, v);
	}

	if (!spfa(n, n)) cout << "NO" << '\n';
	else
	{
		spfa(n, n);
		for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
	}

}