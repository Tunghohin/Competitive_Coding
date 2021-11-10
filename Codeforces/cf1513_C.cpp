#include <map>
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int mod = 1000000007;
int dp[15][200010];

void solve()
{
	int n, m;
	cin >> n >> m;

	int res = 0;
	while (n)
	{
		int x = n % 10;
		res = (res + dp[x][m]) % mod;
		n /= 10;
	}

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i <= 9; i++) dp[i][0] = 1;
	for (int i = 1; i <= 200000; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			dp[j][i] = dp[j + 1][i - 1];
		}
		dp[9][i] = (dp[0][i - 1] + dp[1][i - 1]) % mod;
	}

	while (T--)
	{
		solve();
	}
}