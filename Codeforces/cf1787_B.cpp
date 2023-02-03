#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

vector<PII> mp;

void solve()
{
	mp.clear();

	int n;
	cin >> n;

	for (LL i = 2; i * i <= n; i++)
	{
		if (n % i) continue;
		int cnt = 0;
		while (n % i == 0)
		{
			n /= i;
			cnt++;
		}
		mp.emplace_back(cnt, i);
	}
	if (n > 1) mp.emplace_back(1, n);

	sort(mp.begin(), mp.end());

	// for (auto v : mp)
	// {
	// 	cout << v.first << ' ' << v.second << '\n';
	// }
	// cout << '\n';

	LL res = 0;
	for (int i = 0; i < mp.size(); i++)
	{
		if (mp[i].first == 0) continue;
		LL tmp = 1;
		LL co = mp[i].first;
		for (int j = i; j < mp.size(); j++)
		{
			tmp *= mp[j].second;
			mp[j].first -= co;
		}

		res += tmp * co;
		// cout << tmp << ' ' << co << '\n';
	}

	cout << res << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}