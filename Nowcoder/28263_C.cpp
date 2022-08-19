#include <iostream>
#include <iomanip>

using namespace std;

int a[110];
double dp[110];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	dp[n] = (double)a[n];
	for (int i = n - 1; i >= 1; i--)
	{
		double tot = 0.0;
		for (int j = 1; i + j <= n && j <= 6; j++)
		{
			tot += dp[i + j];
		}

		dp[i] = tot / (double)(min(n - i, 6)) + a[i];
	}

	cout << fixed << setprecision(4) << dp[1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}