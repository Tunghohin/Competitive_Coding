#include <iostream>
#include <cstring>
#define int long long

using namespace std;

int G[110][110];
int dist[110][110];

int floyd(int &n)
{
	memcpy(dist, G, sizeof(G));
	int res = 0x3f3f3f3f;

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i < k; i++)
		{
			for (int j = i + 1; j < k; j++)
			{
				res = min(res, dist[i][j] + G[i][k] + G[k][j]);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					dist[j][i] = dist[i][j];
				}
			}
		}
	}

	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) G[i][j] = 0x3f3f3f3f;
	}

	while (m--)
	{
		int f, t, v;
		cin >> f >> t >> v;
		G[f][t] = G[t][f] = min(G[t][f], v);
	}

	for (int i = 1; i <= n; i++) G[i][i] = 0;

	int res = floyd(n);
	if (res == 0x3f3f3f3f) cout << "No solution.";
	else cout << res << '\n';
}