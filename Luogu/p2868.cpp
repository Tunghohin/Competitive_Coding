#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iomanip>

using namespace std;

int f[1010];

struct edge
{
	int to, val, next;
}e[5050];
int head[1010], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

bool vis[1010];
double dist[1010];
int cnt[1010];
bool check(double mid, int n)
{
	memset(dist, 0, sizeof(dist));
	memset(vis, false, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
		vis[i] = true;
	}

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (dist[j] < dist[u] + f[u] - mid * e[i].val)
			{
				dist[j] = dist[u] + f[u] - mid * e[i].val;
				cnt[j] = cnt[u] + 1;
				if (cnt[j] >= n) return true;
				if (!vis[j])
				{
					q.push(j);
					vis[j] = true;
				}
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int L, P;
	cin >> L >> P;

	for (int i = 1; i <= L; i++) cin >> f[i];

	while (P--)
	{
		int F, T, V;
		cin >> F >> T >> V;
		add_edge(F, T, V);
	}

	double l = 0, r = 1e6;
	while (r - l > 1e-4)
	{
		double mid = (l + r) / 2;
		if (check(mid, L)) l = mid;
		else r = mid;
	}

	cout << fixed << setprecision(2) << l << '\n';
}