#include <iostream>
#include <cstring>
#define nullptr 0

using namespace std;

int sw[110];

bool G[110][110];

bool vis[110];
int dist[110];
int dijkstra(int st, int ed, int n)
{
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, false, sizeof(vis));
	dist[st] = 0;

	for (int i = 1; i < n; i++)
	{
		int t = -1;

		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && (t == -1 || dist[j] < dist[t])) t = j;
		}

		for (int j = 1; j <= n; j++)
		{
			if (G[t][j] == true)
			{
				dist[j] = min(dist[j], dist[t] + !(sw[t] == j));
			}
		}

		vis[t] = true;
	}

	return dist[ed];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++)
	{
		int cnt, fst;
		cin >> cnt;
		cin >> fst;
		G[i][fst] = G[fst][i] = true;
		sw[i] = fst;

		for (int j = 2; j <= cnt; j++)
		{
			cin >> fst;
			G[i][fst] = G[fst][i] = true;
		}
	}

	int res = dijkstra(a, b, n);

	if (res > 0x3f3f3f3f / 2) cout << -1 << '\n';
	else cout << res << '\n';

	return 0;
}