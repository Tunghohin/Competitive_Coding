#include <iostream>
#include <cstring>

using namespace std;

struct edge
{
	int to, val, next;
}e[200010];
int head[100010], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

int color[100010];
bool dfs(int u, int type, int mid)
{
	color[u] = type;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (e[i].val < mid) continue;

		if (!color[j])
		{
			if (!dfs(j, 3 - type, mid)) return false;
		}
		else if (color[j] == type) return false;
	}

	return true;
}

bool check(int mid, int n)
{
	memset(color, 0, sizeof(color));
	for (int i = 1; i <= n; i++)
	{
		if (!color[i])
		{
			if (!dfs(i, 1, mid))
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add_edge(a, b, c);
		add_edge(b, a, c);
	}

	int l = 0, r = 1000000010;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (check(mid, n)) r = mid - 1;
		else l = mid;
	}

	cout << l << '\n';
}