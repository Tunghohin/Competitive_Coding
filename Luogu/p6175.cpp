#include <iostream>
#include <cstring>

using namespace std;

int G[110][110];
int dist[110][110];

long long floyd(int &n)
{
	memcpy(dist, G, sizeof(G));
	long long res = 0x3f3f3f3f3f3f3f3f;

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i < k; i++)
		{
			for (int j = i + 1; j < k; j++)
			{
				if ((long long)dist[i][j] + G[j][k] + G[k][i] < res)
				{
					res = dist[i][j] + G[j][k] + G[k][i];
				}
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	memset(G, 0x3f, sizeof(G));
	for (int i = 1; i <= n; i++) G[i][i] = 0;

	while (m--)
	{
		int f, t, v;
		cin >> f >> t >> v;
		G[f][t] = G[t][f] = min(G[f][t], v);
	}

	long long res = floyd(n);
	if (res == 0x3f3f3f3f3f3f3f3f) cout << "No solution.\n";
	else cout << res << '\n';
}