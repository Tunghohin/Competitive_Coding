#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 80000;

int dp[1 << 18];
void solve()
{
	int x;
	cin >> x;

	cout << dp[x] << ' ';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	memset(dp, 0x3f, sizeof(dp));

	dp[0] = 0;
	for (int j = 1; j <= 16; j++)
	{
		for (int i = (1 << 16) - 1; i >= 0; i--)
		{
			dp[i] = min({dp[i], dp[(i + 1) % 32768] + 1, dp[(i * 2) % 32768] + 1});
		}
	}

	while (T--)
	{
		solve();
	}
}