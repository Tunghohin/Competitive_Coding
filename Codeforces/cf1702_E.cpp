#include <iostream>
#include <vector>

using namespace std;

vector<int> G[200010];

int color[200010];
bool dfs(int u, int type)
{
	color[u] = type;
	for (auto v : G[u])
	{
		if (!color[v])
		{
			if (!dfs(v, 3 - type)) return false;
		}
		else if (color[v] == type) return false;
	}

	return true;
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		color[i] = 0;
		G[i].clear();
	}

	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);

		if (a == b) flag = false;
		if (G[a].size() > 2 || G[b].size() > 2) flag = false;
	}

	if (!flag)
	{
		cout << "No\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!color[i])
		{
			if (!dfs(i, 1))
			{
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
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