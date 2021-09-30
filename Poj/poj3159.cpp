#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
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
}e[300010];
int head[30010], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

int dist[30010];
bool in_que[30010];
void spfa()
{
	stack<int> q;
	memset(dist, 0x3f, sizeof(dist));
	memset(in_que, false, sizeof(in_que));

	q.push(1);
	in_que[1] = true;
	dist[1] = 0;

	while (!q.empty())
	{
		int u = q.top();
		q.pop();
		in_que[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
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

	int n, m;
	n = read(), m = read();

	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		a = read(), b = read(), c = read();

		add_edge(a, b, c);
	}

	spfa();

	cout << dist[n] - dist[1] << '\n';

	return 0;
}