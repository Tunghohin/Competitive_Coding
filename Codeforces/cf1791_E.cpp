#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

constexpr int N = 200010;

int a[N];
int dp[N][2]; //0uc

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i], dp[i][0] = dp[i][1] = 0;

	dp[1][0] = a[1];
	dp[1][1] = -a[1];
	dp[2][0] = a[1] + a[2];
	dp[2][1] = -a[1] - a[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
		dp[i][1] = max(dp[i - 1][0] - 2 * a[i - 1] - a[i], dp[i - 1][1] + 2 * a[i - 1] - a[i]);
	}

	// for (int i = 1; i <= n; i++)
	// {
	// 	cout << dp[i][0] << ' ' << dp[i][1] << '\n';
	// }
	cout << max(dp[n][0], dp[n][1]) << '\n';
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