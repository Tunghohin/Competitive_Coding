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

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a.begin() + 1, a.end());
	
	int res = 0;
	if (a[1] != 0) res++;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= i - 1 && (i == n || a[i + 1] > i)) res++;
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