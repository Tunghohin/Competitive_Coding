#include <iostream>
#include <iomanip>

using namespace std;

double dp[1010][1010];

int main()
{
	int n, s;
	cin >> n >> s;

	dp[n][s] = 0;
	for (int i = n; i >= 0; i--)
	{
		for (int j = s; j >= 0; j--)
		{
			if (i == n && j == s) continue;
			dp[i][j] = ((((double)i / (double)n) * ((double)j / (double)s))
					 + (((double)i / (double)n) * (1.0 - (double)j / (double)s) * (dp[i][j + 1] + 1.0))
					 + (((double)j / (double)s) * (1.0 - (double)i / (double)n) * (dp[i + 1][j] + 1.0))
					 + ((1.0 - (double)j / (double)s) * (1.0 - (double)i / (double)n) * (dp[i + 1][j + 1] + 1.0)))
					 / (1.0 - ((double)i / (double)n) * ((double)j / (double)s));			
		}
	}

	cout << fixed << setprecision(4) << dp[0][0] << '\n';
}