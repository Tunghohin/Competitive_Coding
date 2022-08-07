#include <iostream>

using namespace std;

char mp[110][110];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) cin >> mp[i][j];
	}

	int cnt = 0;
	for (int i = 1; i <= n / 2 + (n % 2 == 1); i++)
	{
		for (int j = i; j <= n - i; j++)
		{
			if (true)
			{
				int one_cnt = (mp[i][j] == '1');
				if (mp[j][n - i + 1] == '1')
				{
					one_cnt++;
				}
				if (mp[n - j + 1][i] == '1')
				{
					one_cnt++;
				}
				if (mp[n - i + 1][n - j + 1] == '1')
				{
					one_cnt++;
				}
				cnt += min(one_cnt, 4 - one_cnt);
			}
		}
	}
	cout << cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}