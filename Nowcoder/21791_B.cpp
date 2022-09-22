#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

int n;
int C[110][110];
int c_cnt[110], r_cnt[110];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char c;
			cin >> c;
			if (c == 'C')
			{
				r_cnt[i]++;
				c_cnt[j]++;
			}
		}
	}

	LL res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (c_cnt[i] >= 2) res += C[c_cnt[i]][2];
		if (r_cnt[i] >= 2) res += C[r_cnt[i]][2];
	}

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 3 && j <= i; j++)
		{
			if (j == 0) C[i][j] = 1;
			else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	solve();
}