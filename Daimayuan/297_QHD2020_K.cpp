#include <iostream>

using namespace std;

const int N = 10010;

int dp[N][2]; //0down

struct edge
{
	int to, next;
}e[N];
int head[N], tot;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

void dfs(int u)
{
	for (int i = head[u]; i; i = e[i].next)
	{
		int to = e[i].to;
		dfs(to);
	}
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		add_edge(x, i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}