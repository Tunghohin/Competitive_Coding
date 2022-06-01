#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cnt = 0;
vector<int> son[100010];
vector<int> cycles[100010];
int ca[100010], cb[100010];
bool vis[100010];
int val_c[100010];

bool comp(vector<int> &A, vector<int> &B)
{
	return A.size() > B.size();
}

void dfs(int u)
{
	vis[u] = true;
	cycles[cnt].push_back(u);
	for (auto to : son[u])
	{
		if (!vis[to])
		{
			dfs(to);
		}
	}
}

void solve()
{
	int n;
	cin >> n;

	cnt = 0;
	for (int i = 0; i <= n; i++)
	{
		vis[i] = false;
		val_c[i] = 0;
		cycles[i].clear();
		son[i].clear();
	}

	for (int i = 1; i <= n; i++) cin >> ca[i];
	for (int i = 1; i <= n; i++) cin >> cb[i];

	for (int i = 1; i <= n; i++)
	{
		son[ca[i]].push_back(cb[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			cnt++;
			dfs(i);
		}
	}

	sort(cycles + 1, cycles + 1 + cnt, comp);

	int min_num = 1, max_num = n;
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 0; j < cycles[i].size() - (cycles[i].size() % 2 == 1); j++)
		{
			if (j % 2 == 0)
			{
				val_c[cycles[i][j]] = min_num++;
			}
			else val_c[cycles[i][j]] = max_num--;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!val_c[i]) val_c[i] = min_num++;
	}

	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += abs(val_c[ca[i]] - val_c[cb[i]]);
	}

	cout << res << '\n';
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