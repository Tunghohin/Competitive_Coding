#include <iostream>
#include <queue>
#include <cstring>
#define nullptr 0

using namespace std;

struct edge
{
	int to, val, next;
	bool d;
}e[200010];
int head[1010], tot = 0;

int res[1010];

void add_edge(int from, int to, int val, bool d)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].d = d;
	e[tot].next = head[from];
	head[from] = tot;
}

int dist[1010];
bool in_que[1010];
void spfa(int st, bool d)
{
	memset(dist, 0x3f, sizeof(dist));
	memset(in_que, false, sizeof(in_que));

	queue<int> q;
	dist[st] = 0;
	q.push(st);
	in_que[st] = true;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		in_que[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			if (e[i].d != d) continue;

			int j = e[i].to;

			if (dist[j] > dist[u] + e[i].val)
			{
				dist[j] = dist[u] + e[i].val;

				if (!in_que[j])
				{
					q.push(j);
					in_que[j] = true;
				}
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, x;
	cin >> n >> m >> x;

	for (int i = 1; i <= m; i++)
	{
		int f, t, v;
		cin >> f >> t >> v;
		add_edge(f, t, v, true);
		add_edge(t, f, v, false);
	}

	int maxn = 0;
	spfa(x, true);
	for (int i = 1; i <= n; i++) res[i] += dist[i];

	spfa(x, false);
	for (int i = 1; i <= n; i++) maxn = max(maxn, res[i] + dist[i]);


	cout << maxn << '\n';

	return 0;
}