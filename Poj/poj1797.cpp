#include <iostream>
#include <queue>
#include <cstring>
#define nullptr 0

using namespace std;

struct edge
{
	int to, val, next;
}e[2000010];
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
bool spfa(int mid, int n)
{
	memset(dist, 0x3f, sizeof(dist));
	memset(in_que, false, sizeof(in_que));

	queue<int> q;

	dist[1] = 0;
	q.push(1);
	in_que[1] = true;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		in_que[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (e[i].val >= mid && dist[j] > dist[u] + e[i].val)
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


	if (dist[n] > 0x3f3f3f3f / 2) return false;
	else return true;
}

void solve(int kase)
{
	memset(head, 0, sizeof(head));
	tot = 0;

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int f, t, v;
		cin >> f >> t >> v;
		add_edge(f, t, v), add_edge(t, f, v);
	}

	int l = 0, r = 1000001;

	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (spfa(mid, n)) l = mid;
		else r = mid - 1;
	}

	cout << "Scenario #" << kase << ':' << '\n';
	cout << l << "\n\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		solve(i);
	}

	return 0;
}