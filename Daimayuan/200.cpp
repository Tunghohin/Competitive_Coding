#include <iostream>

using namespace std;

const int N = 510;

int dp[N][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;

	for (int length = 0; length < n; length++)
	{
		for (int i = 0; i < n; i++)
		{
			int l = i, r = i + length;
			if (r >= n) continue;
			if ((s[l] == '(' && s[r] == ')') || (s[l] == '[' && s[r] == ']'))
			{
				dp[l][r] = dp[l + 1][r - 1] + 2;
			}

			for (int k = l; k < r; k++)
			{
				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
			}
		}
	}

	cout << dp[0][n - 1];
}