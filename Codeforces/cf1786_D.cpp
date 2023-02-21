#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

struct res_node
{
	int a, b, c, d;
};

map<PII, int> mp;//need get
char const* refc = "win";
int now = 0;
void solve()
{
	int n;
	cin >> n;

	vector<string> v;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int i = 0; i < 3; i++)
		{
			if (s[i] == 'w') s[i] = 'a'; //0 1 2
			if (s[i] == 'i') s[i] = 'b';
			if (s[i] == 'n') s[i] = 'c';
		}
		v.push_back(s);
	}

	// for (auto val : v)
	// {
	// 	cout << val << '\n';
	// }

	vector<res_node> res_op;

	vector<int> idx[6];
	for (int i = 0; i < 6; i++) idx[i].clear();

	map<PII, int> cnt;
	for (int i = 0; i < (int)v.size(); i++)
	{
		int types[3] = {0, 0, 0}; // a b c
		string s = v[i];
		for (int j = 0; j < 3; j++)
		{
			if (s[j] == 'a') types[0]++;
			if (s[j] == 'b') types[1]++;
			if (s[j] == 'c') types[2]++;
		}

		int max_val = 0;
		for (int j = 0; j < 3; j++) max_val = max(max_val, types[j]);

		if (max_val == 1) continue;
		else if (max_val == 2)
		{
			int need, get;
			for (int j = 0; j < 3; j++)
			{
				if (types[j] == 2) get = j;
				if (types[j] == 0) need = j;
			}
			cnt[{need, get}]++;
			idx[mp[{need, get}]].push_back(i + 1);
		}
		else if (max_val == 3)
		{
			for (int j = 0; j < 3; j++)
			{
				if (types[j] == 3)
				{
					cnt[{(j - 1 + 3) % 3, j}]++;
					cnt[{(j + 1) % 3, j}]++;
					idx[mp[{(j - 1 + 3) % 3, j}]].push_back(i + 1);
					idx[mp[{(j + 1) % 3, j}]].push_back(i + 1);
				}
			}
		}
	}

	// for (int i = 0; i < 3; i++)
	// {
	// 	for (int j = 0; j < 3; j++)
	// 	{
	// 		if (i == j) continue;
	// 		if (idx[mp[{i, j}]].empty()) continue;
	// 		cout << refc[i] << ' ' << refc[j] << "!!!\n";
	// 		for (auto v : idx[mp[{i, j}]])
	// 		{
	// 			cout << v << ' ';
	// 		}
	// 		cout << '\n';
	// 	}
	// }

	int res = 0;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j == i) continue;

				while (!idx[mp[{i, j}]].empty())
				{
					if (!idx[mp[{j, i}]].empty())
					{
						res++;
						res_op.push_back({idx[mp[{i, j}]].back(), refc[j], idx[mp[{j, i}]].back(), refc[i]});
						cnt[{i, j}]--;
						idx[mp[{i, j}]].pop_back();
						cnt[{j, i}]--;
						idx[mp[{j, i}]].pop_back();
					}
					else
					{	
						int other;
						for (int ii = 0; ii < 3; ii++)
						{
							if (ii != j && ii != i)
							{
								other = ii;
								break;
							}
						}
						res++;
						int popo = idx[mp[{j, other}]].back();
						res_op.push_back({idx[mp[{j, other}]].back(), refc[other], idx[mp[{other, i}]].back(), refc[i]});
						cnt[{j, other}]--;
						idx[mp[{j, other}]].pop_back();
						cnt[{other, i}]--;
						idx[mp[{other, i}]].pop_back();
						idx[mp[{j, i}]].push_back(popo);
					}
				}
			}
		}
	}
	cout << res << '\n';
	for (auto nd : res_op)
	{
		cout << nd.a << ' ' << (char)nd.b << ' ' << nd.c << ' ' << (char)nd.d << '\n';
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j) continue;
			mp[{i, j}] = now++;
		}
	}

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}