#include <iostream>

using namespace std;

char a[2010][2010];
int one_cnt[2010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		one_cnt[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '1') one_cnt[i]++;
		}
	}

	int res = 0x3f3f3f3f;
	for (int i = 0; i < n; i++)
	{
		int cur_res = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j][(i + j) % n] == '1')
			{
				cur_res += one_cnt[j] - 1;
			}
			else
			{
				cur_res += one_cnt[j] + 1;
			}
		}

		res = min(res, cur_res);
	}

	cout << res << '\n';
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