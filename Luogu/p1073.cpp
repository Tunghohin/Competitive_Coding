#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int price[100010];

struct edge
{
	int to, next;
}e[2000010];
int head_go[100010], head_back[100010], tot = 0;

void add_edge(int from, int to, int h[])
{
	e[++tot].to = to;
	e[tot].next = h[from];
	h[from] = tot;
}

bool vis[100010];
int dist_go[100010], dist_back[100010];
void spfa(int dist[], int head[], int type, int n) //1go 2back
{
	queue<int> q;
	if (type == 1)
	{
		memset(dist, 0x3f, sizeof(dist_go));
		memset(vis, false, sizeof(vis));
		dist[1] = price[1];
		q.push(1);
		vis[1] = true;
	}
	else
	{
		memset(dist, -0x3f, sizeof(dist_back));
		memset(vis, false, sizeof(vis));
		dist[n] = price[n];
		q.push(n);
		vis[n] = true;
	}

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (type == 1)
			{
				if (dist[j] > min(dist[u], price[j]))
				{
					dist[j] = min(dist[u], price[j]);
					if (!vis[j])
					{
						q.push(j);
						vis[j] = true;
					}
				}
			}
			else
			{
				if (dist[j] < max(dist[u], price[j]))
				{
					dist[j] = max(dist[u], price[j]);
					if (!vis[j])
					{
						q.push(j);
						vis[j] = true;
					}
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> price[i];

	while (m--)
	{
		int f, t, type;
		cin >> f >> t >> type;

		add_edge(f, t, head_go), add_edge(t, f, head_back);
		if (type == 2)
		{
			add_edge(t, f, head_go), add_edge(f, t, head_back);
		}
	}

	spfa(dist_go, head_go, 1, n);
	spfa(dist_back, head_back, 2, n);

	int res = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++) res = max(res, dist_back[i] - dist_go[i]);

	cout << res;
}