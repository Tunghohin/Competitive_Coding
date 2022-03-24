#include <iostream>
#include <vector>

using namespace std;

const int N = 2010;

int dp[N][N];
int depth[N];

vector<int> son[N];
vector<pair<int, int>> paths[N];

void get_depth(int u, int from)
{
	if (u == 1) depth[u] = 1;
	else depth[u] = depth[from] + 1;

	for (auto to : son[u])
	{
		get_depth(to, u);
	}
}

void dfs(int u)
{

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		son[x].push_back(i);
	}

	get_depth(1, 0);

	for (int i = 1; i <= m; i++)
	{
		int a, b, v;
		cin >> a >> b >> v;
		if (depth[a] < depth[b]) swap(a, b);

		paths[a].emplace_back(b, v);
	}

	dfs(1);

	if (dp[1][1] <= 0x3f3f3f3f / 2) cout << dp[1][1];
	else cout << -1;
}