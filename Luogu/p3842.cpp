#include <iostream>

using namespace std;

int a[20010][10];
int dp[20010][2];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][0] >> a[i][1];
	}

	a[0][0] = a[0][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		int len = abs(a[i][0] - a[i][1]);
		dp[i][0] = min(dp[i - 1][0] + abs(a[i - 1][0] - a[i][1]), dp[i - 1][1] + abs(a[i - 1][1] - a[i][1])) + len;
		dp[i][1] = min(dp[i - 1][0] + abs(a[i - 1][0] - a[i][0]), dp[i - 1][1] + abs(a[i - 1][1] - a[i][0])) + len;
	}

	long long res = min(dp[n][0] + n - a[n][0], dp[n][1] + n - a[n][1]);
	res += n - 1;
	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}