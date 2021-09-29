#include <iostream>
#include <cstring>
#include <cstdio>
#define nullptr 0

using namespace std;

int G[110][110];

int dist[110];
bool vis[110];
int dijkstra(int n)
{
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;

	for (int i = 1; i < n; i++)
	{
		int t = -1;

		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && (t == -1 || dist[j] < dist[t])) t = j;
		}

		for (int j = 1; j <= n; j++)
		{
			if (G[t][j] && dist[j] > dist[t] + G[t][j])
			{
				dist[j] = dist[t] + G[t][j];
			}
		}

		vis[t] = true;
	}

	int res = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] < 0x3f3f3f3f / 2) res = max(res, dist[i]);
	}

	return res;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			int x = 0x3f3f3f3f;
			char ch = 'x';

			if (!scanf("%d", &x))
			{
				scanf("%c", &ch);
			}

			if (x != 0x3f3f3f3f) G[i][j] = G[j][i] = x;
		}
	}

	cout << dijkstra(n);

	return 0;
}