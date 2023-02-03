#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

constexpr int N = 200010;
LL a[N];
LL mx[N], mn[N];
LL dp[N][2]; //x y

void solve()
{
	int n, s;
	cin >> n >> s;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= 2 * s) mn[i] = s, mx[i] = a[i] - s;
		else if (a[i] >= s) mn[i] = a[i] - s, mx[i] = s;
		else mx[i] = a[i], mn[i] = 0;
	}

	dp[2][0] = a[1] * mx[2];
	dp[2][1] = a[1] * mn[2];
	for (int i = 3; i < n; i++)
	{
		dp[i][0] = min(dp[i - 1][0] + mn[i - 1] * mx[i],
					   dp[i - 1][1] + mx[i - 1] * mx[i]);
		dp[i][1] = min(dp[i - 1][0] + mn[i - 1] * mn[i],
					   dp[i - 1][1] + mx[i - 1] * mn[i]);
	}
	cout << min(dp[n - 1][0] + mn[n - 1] * a[n],
		        dp[n - 1][1] + mx[n - 1] * a[n]) << '\n';
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