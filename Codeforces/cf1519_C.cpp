#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	int team_cnt = 0;

	while (T--)
	{
		int n;
		cin >> n;

		vector<int> u(n), s(n);

		for (int i = 0; i < n; i++)
		{
			cin >> u[i];
			u[i]--;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}

		vector<vector<int>> u_s(n);

		for (int i = 0; i < n; i++) u_s[u[i]].push_back(s[i]);

		for (int i = 0; i < n; i++) sort(u_s[i].begin(), u_s[i].end(), cmp);

		vector<vector<long long>> pre_fix(n, vector<long long>(1, 0));

		for (int i = 0; i < n; i++)
		{
			for (auto x : u_s[i])
			{
				pre_fix[i].push_back(pre_fix[i].back() + x);
			}
		}

		vector<long long> ans(n);

		for (int i = 0; i < n; i++)
		{
			for (int k = 1; k <= int(u_s[i].size()); k++)
			{
				ans[k - 1] += pre_fix[i][u_s[i].size() / k * k];
			}
		}

		for (auto i : ans) cout << i << '\n';

		cout << '\n';
	}
}