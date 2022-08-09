#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 210;

int cyc_cnt;
vector<int> cyc[N];
vector<int> G[N];
bool vis[N];

void dfs(int u)
{
	vis[u] = true;
	cyc[cyc_cnt].push_back(u);
	for (auto v : G[u])
	{
		if (!vis[v]) dfs(v);
	}
}

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	cyc_cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cyc[i].clear();
		G[i].clear();
		vis[i] = false;
	}

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		G[i].push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			cyc_cnt++;
			dfs(i);
		}
	}

	long long res = 1;
	for (int i = 1; i <= cyc_cnt; i++)
	{
		string tmp;
		for (auto i : cyc[i])
		{
			tmp += s[i - 1];
		}
		
		long long cur_cyc = (long long)tmp.length();
		for (long long split_cnt = 2; split_cnt <= tmp.length(); split_cnt++)
		{
			if (tmp.length() % split_cnt != 0) continue;
			long long cur_len = (long long)tmp.length() / split_cnt;
			string cur_str = tmp.substr(0, cur_len);
			bool flag = true;
			for (int i = cur_len; i < tmp.length(); i += cur_len)
			{
				if (tmp.substr(i, cur_len) != cur_str)
				{
					flag = false;
					break;
				}
			}
			if (flag) cur_cyc = (long long)tmp.length() / split_cnt;
		}
		
		res = res / __gcd(cur_cyc, res) * cur_cyc;
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