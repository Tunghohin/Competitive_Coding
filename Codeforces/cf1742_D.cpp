#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int num[1010];
map<PII, int> mp;

void solve()
{
	int n;
	cin >> n;

	map<int, int> pos;
	memset(num, 0, sizeof(num));

	int max_num = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		max_num = max(max_num, x);
		num[x]++;
		pos[x] = i;
	}

	//for (int i = 1; i <= 20; i++) cout << num[i];

	int res = -1;
	for (int i = max_num; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--)
		{
			if (!num[i] || !num[j]) continue;
			if (mp[{i, j}])
			{
				res = max(res, pos[i] + pos[j]);
			}
		}
	}

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (__gcd(i, j) == 1) mp[{i, j}]++;
		}
	}

	while (T--)
	{
		solve();
	}
}