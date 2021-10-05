#include <iostream>
#include <cstring>
#define nullptr 0

using namespace std;

int G[110][110];
int level[110];

int dist[110];
bool vis[110];
int dijkstra(int down, int up, int n)
{
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, false, sizeof(vis));

	dist[0] = 0;

	for (int i = 0; i <= n; i++)
	{
		int t = -1;
		for (int j = 0; j <= n; j++)
		{
			if (!vis[j] && (t == -1 || dist[j] < dist[t])) t = j;
		}

		vis[t] = true;
		for (int j = 1; j <= n; j++)
		{
			if (level[j] >= down && level[j] <= up)
			{
				dist[j] = min(dist[j], dist[t] + G[t][j]);
			}
		}
	}

	return dist[1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int m, n;
	cin >> m >> n;

	memset(G, 0x3f, sizeof(G));
	for (int i = 1; i <= n; i++) G[i][i] = 0;

	for (int i = 1; i <= n; i++)
	{
		int price, cnt;
		cin >> price >> level[i] >> cnt;

		G[0][i] = min(G[0][i], price);
		while (cnt--)
		{
			int id, cost;
			cin >> id >> cost;
			G[id][i] = min(G[id][i], cost);
		}
	}

	int res = 0x3f3f3f3f;
	for (int i = level[1] - m; i <= level[1]; i++) res = min(res, dijkstra(i, i + m, n));

	cout << res << '\n';

	return 0;
}