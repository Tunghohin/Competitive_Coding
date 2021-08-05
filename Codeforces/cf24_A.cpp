#include <iostream>
#include <cstring>

using namespace std;

int n;
bool vis[110];
int minn = 0x3f3f3f3f;

struct edge {
	int to, next, val;
} e[220];
int head[110], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

void dfs(int st, int en, int sum, int step)
{
	if (st == en && step == n)
	{
		minn = min(minn, sum);
	}

	for (int i = head[st]; i; i = e[i].next)
	{
		if (vis[e[i].to]) continue;

		else
		{
			vis[e[i].to] = true;
			dfs(e[i].to, en, sum + e[i].val, step + 1);
			vis[e[i].to] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;

	int f, t, v;
	for (int i = 1; i <= n; i++)
	{
		cin >> f >> t >> v;
		add_edge(f, t, v);
		add_edge(t, f, 0);
	}

	dfs(1, 1, 0, 0);

	cout << minn;

	return 0;
}