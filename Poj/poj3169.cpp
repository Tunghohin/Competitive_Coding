#include <iostream>
#include <queue>
#include <cstring>
#define nullptr 0

using namespace std;

struct edge
{
	int to, val, next;
}e[40010];
int head[1010], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

bool in_que[1010];
int dist[1010];
int cnt[1010];
bool spfa(int type, int n) //1 for negative circle, 2 for dist
{
	queue<int> q;
	memset(cnt, 0, sizeof(cnt));
	memset(in_que, false, sizeof(in_que));
	memset(dist, 0x3f, sizeof(dist));

	if (type == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			q.push(i);
			in_que[i] = true;
			dist[i] = 0;
		}
	}

	else
	{
		q.push(1);
		in_que[1] = true;
		dist[1] = 0;
	}

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		in_que[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (dist[j] > dist[u] + e[i].val)
			{
				dist[j] = dist[u] + e[i].val;
				cnt[j] = cnt[u] + 1;

				if (cnt[j] >= n) return false;
				if (!in_que[j])
				{
					q.push(j);
					in_que[j] = true;
				}
			}
		}
	}

	if (dist[n] > 0x3f3f3f3f / 2) return false;
	else return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, ml, md;
	cin >> n >> ml >> md;

	for (int i = 2; i <= n; i++) add_edge(i, i - 1, 0);

	for (int i = 1; i <= ml; i++)
	{
		int a, b, v;
		cin >> a >> b >> v;

		add_edge(a, b, v);
	}

	for (int i = 1; i <= md; i++)
	{
		int a, b, v;
		cin >> a >> b >> v;

		add_edge(b, a, -v);
	}

	if (!spfa(1, n)) cout << -1 << '\n';
	else
	{
		if (!spfa(2, n)) cout << -2 << '\n';
		else cout << dist[n] << '\n';
	}

	return 0;
}