#include <iostream>
#include <queue>
#include <iomanip>
#include <cstring>

using namespace std;

struct edge
{
	int t, next;
	double val;
}e[10010];
int head[3010], tot = 0;

void add_edge(int from, int to, double val)
{
	e[++tot].t = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

double dist[3010];
bool vis[3010];
int cnt[3010];
bool check(double mid, int n)
{
	memset(dist, 0, sizeof(dist));
	memset(vis, false, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	queue<int> q;
	int in_cnt = 0;

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
			int j = e[i].t;
			double v = e[i].val - mid;
			if (dist[j] > dist[u] + v)
			{
				dist[j] = dist[u] + v;
				cnt[j] = cnt[u] + 1;

				if (cnt[j] >= n || in_cnt > (4 * n)) return true;

				if (!vis[j])
				{
					q.push(j);
					vis[j] = true;
					in_cnt++;
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

	int n, m;
	cin >> n >> m;

	while(m--)
	{
		int f, t;
		double v;
		cin >> f >> t >> v;
		add_edge(f, t, v);
	}

	double l = -1e8, r = 1e8;

	while (r - l > 1e-10)
	{
		double mid = (l + r) / 2;
		if (check(mid, n)) r = mid;
		else l = mid;
	}

	cout << fixed << setprecision(8) << l << '\n';
}
