#include <iostream>
#include <cstring>

using namespace std;

struct edge
{
	int to, next;
}e[50010];
int head[550], tot;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

bool vis[550];
int matched[550];
bool find(int u)
{
	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (!vis[j])
		{
			vis[j] = true;
			if (!matched[j] || find(matched[j]))
			{
				matched[j] = u;
				return true;
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	while (k--)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(vis, false, sizeof(vis));
		if (find(i)) res++;
	}

	cout << res << '\n';
}