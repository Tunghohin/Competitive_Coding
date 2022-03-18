#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int G[N][N];
int dist[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	memset(dist, 0x3f, sizeof(dist));
	memset(G, 0x3f, sizeof(G));

	for (int i = 1; i <= m; i++)
	{
		int f, t, v;
		cin >> f >> t >> v;
		G[f][t] = min(G[f][t], v);
	}

	dist[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dist[i] = min(dist[i], dist[j] + G[j][i]);
		}
	}

	cout << dist[n];
}