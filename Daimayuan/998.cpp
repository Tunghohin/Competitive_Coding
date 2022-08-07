#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 10010;

int n, m;

struct edge
{
	int to, next;
	int val;
} e[2 * N];
int head[N], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot] = {to, head[from], val}; head[from] = tot;
}

int dist[10010];
bool vis[10010];
int cnt[10010];
int q[10010];

bool spfa(int &n)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
		vis[i] = true;
	}

	while (!q.empty())
	{
		auto u = q.front();
		vis[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if (dist[v] < dist[u] + e[i].val)
			{
				dist[v] = dist[u] + e[i].val;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] >= n + 1) return false;
				if (!vis[v])
				{
					q.push(v);
					vis[v] = true;
				}
			}
		}

		q.pop();
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b, v;
		cin >> a >> b >> v;
		add_edge(a, b, -v);
	}

	bool flag = spfa(n);
	if (!flag)
	{
		cout << -1;
	}
	else for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
}