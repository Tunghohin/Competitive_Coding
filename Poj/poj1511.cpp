#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define nullptr 0

using namespace std;

inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-')w = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

struct edge
{
	int to, val, next;
	bool type;
}e[2000010];
int head[1000010], tot = 0;

void add_edge(int from, int to, int val, bool type)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].type = type;
	e[tot].next = head[from];
	head[from] = tot;
}

int dist[1000010];
bool in_que[1000010];
void spfa(int type)
{
	queue<int> q;
	memset(dist, 0x3f, sizeof(dist));
	memset(in_que, false, sizeof(in_que));

	q.push(1);
	in_que[1] = true;
	dist[1] = 0;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		in_que[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			if (e[i].type != type) continue;

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

void solve(int kase)
{
	memset(head, 0, sizeof(head));
	tot = 0;

	int n, m;
	n = read(), m = read();

	for (int i = 1; i <= m; i++)
	{
		int f, t, v;
		f = read(), t = read(), v = read();

		add_edge(f, t, v, true);
		add_edge(t, f, v, false);
	}

	long long res = 0;
	spfa(true);
	for (int i = 1; i <= n; i++) res += dist[i];

	spfa(false);
	for (int i = 1; i <= n; i++) res += dist[i];

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	T = read();

	for (int i = 1; i <= T; i++)
	{
		solve(i);
	}

	return 0;
}