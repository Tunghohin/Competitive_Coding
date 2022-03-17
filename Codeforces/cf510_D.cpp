#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> PII;

int l[310];
int c[310];

int dijkstra(int n)
{
	map<int, int> vis;
	map<int, int> dist;
	priority_queue<PII, vector<PII>, greater<PII>> q;

	for (int i = 1; i <= n; i++)
	{
		dist[0] = 0;
		q.push({0, 0});
	}

	while (!q.empty())
	{
		auto u = q.top();
		q.pop();

		if (u.second == 1)
		{
			return dist[u.second];
		}

		if (vis[u.second]) continue;
		vis[u.second] = true;

		for (int i = 1; i <= n; i++)
		{
			int j = __gcd(u.second, l[i]);

			if (!dist[j] || dist[j] > dist[u.second] + c[i])
			{
				dist[j] = dist[u.second] + c[i];
				q.push({dist[j], j});
			}
		}
	}

	return -1;
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> l[i];
	for (int i = 1; i <= n; i++) cin >> c[i];

	cout << dijkstra(n);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	T = 1;

	while (T--)
	{
		solve();
	}
}