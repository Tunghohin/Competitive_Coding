#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

int C[110][110];

void solve()
{
	int n, m, t;
	cin >> n >> m >> t;

	LL res = 0;
	for (int k = 1; k <= t - 4; k++)
	{
		res += C[m][k] * C[n][t - k];
	}

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) C[i][j] = 1;
			else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	solve();
}