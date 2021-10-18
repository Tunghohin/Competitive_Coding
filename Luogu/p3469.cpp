#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;

struct edge
{
	int to, next;
}e[M];
int head[N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int dfn[N], low[N], timestamp = 0;
long long size[N];
long long res[N];
void tarjan(int u, int n)
{
	dfn[u] = low[u] = ++timestamp;
	long long sum = 0;
	size[u] = 1;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (!dfn[j])
		{
			tarjan(j, n);
			size[u] += size[j];

			if (dfn[u] <= low[j])
			{
				res[u] += size[j] * sum;
				sum += size[j];
			}
			low[u] = min(low[u], low[j]);
		}

		else
		{
			low[u] = min(low[u], dfn[j]);
		}
	}

	res[u] += (n - sum - 1) * sum;
	res[u] += n - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b), add_edge(b, a);
	}

	tarjan(1, n);

	for (int i = 1; i <= n; i++) cout << res[i] * 2 << '\n';
}