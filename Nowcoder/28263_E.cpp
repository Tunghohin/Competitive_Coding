#include <iostream>

using namespace std;

double dp[2010][2010];

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	double p1, p2, p3, p4;
	cin >> p1 >> p2 >> p3 >> p4;

	dp[1][1] = p4 / (1.0 - p1 - p2);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j <= k) 
		}
	}

	cout << dp[n][m] << '\n';
}