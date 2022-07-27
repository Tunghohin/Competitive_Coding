#include <iostream>

using namespace std;

int C[110][110];
int row_cnt[110];
int col_cnt[110];
void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= min(i, 2); j++)
		{
			if (j == 0) C[i][j] = 1;
			else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char x;
			cin >> x;
			if (x == 'C')
			{
				row_cnt[i]++;
				col_cnt[j]++;
			}
		}
	}

	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (col_cnt[i] >= 2) res += C[col_cnt[i]][2];
		if (row_cnt[i] >= 2) res += C[row_cnt[i]][2];
	}

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}