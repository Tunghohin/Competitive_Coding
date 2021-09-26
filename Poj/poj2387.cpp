#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct edge
{
	int to, val, next;
}e[4010];
int head[1010], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

int dist[1010];
bool in_que[1010];
void spfa(int st)
{
	memset(dist, 0x3f, sizeof(dist));
	memset(in_que, false, sizeof(in_que));

	queue<int> q;
	q.push(st);
	in_que[st] = true;
	dist[st] = 0;

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
	int T, N;
	cin >> T >> N;

	while (T--)
	{
		int a, b, v;
		cin >> a >> b >> v;
		add_edge(a, b, v);
		add_edge(b, a, v);
	}

	spfa(N);

	cout << dist[1];

	return 0;
}