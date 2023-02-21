#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

void solve()
{
	int n;
	cin >> n;

	int one_cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == 1) one_cnt++;
	}

	cout << n - (one_cnt / 2) * 2 + one_cnt / 2 << '\n';
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