#include <iostream>

using namespace std;

struct edge
{
	int to, next;
}e[200010];
int head[10010], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int color[10010];
int type_1 = 0, type_2 = 0;
bool dfs(int u, int type)
{
	color[u] = type;
	if (type == 1) type_1++;
	else type_2++;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (!color[j])
		{
			if (!dfs(j, 3 - type)) return false;
		}
		else if (color[j] == type) return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int sum = 0;
	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int f, t;
		cin >> f >> t;
		add_edge(f, t), add_edge(t, f);
	}

	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		if (color[i]) continue;
		else
		{
			type_1 = 0, type_2 = 0;
			flag = dfs(i, 1);
			sum += min(type_1, type_2);
			if (!flag) break;
		}
	}

	if (!flag) cout << "Impossible\n";
	else cout << sum << '\n';
}