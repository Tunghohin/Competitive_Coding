#include <iostream>

using namespace std;

typedef long long ll;

int n, m, k;
char mp[1010][1010];
ll tr[1010][1010];

int low_bit(int x)
{
	return x & (-x);
}

void modify(int x, int y, long long v)
{
	for (int p = x; p <= n; p += low_bit(p))
	{
		for (int q = y; q <= m; q += low_bit(q))
		{
			tr[p][q] += v;
		}
	}
}

ll query(int x, int y)
{
	ll res = 0;
	for (int p = x; p; p -= low_bit(p))
	{
		for (int q = y; q; q -= low_bit(q))
		{
			res += tr[p][q];
		}
	}

	return res;
}

void solve()
{
	cin >> n >> m >> k;

	int icon_cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> mp[i][j];
			if (mp[i][j] == '*')
			{
				icon_cnt++;
				modify(i, j, 1);
			}
		}
	}

	int full_col = icon_cnt / n;
	int left_cnt = icon_cnt % n;
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;

		if (mp[x][y] == '*')
		{
			modify(x, y, -1);
			icon_cnt--;
			full_col = icon_cnt / n;
			left_cnt = icon_cnt % n;
			mp[x][y] = '.';
		}
		else
		{
			modify(x, y, 1);
			icon_cnt++;
			full_col = icon_cnt / n;
			left_cnt = icon_cnt % n;
			mp[x][y] = '*';
		}

		cout << icon_cnt - (query(n, full_col) + (query(left_cnt, full_col + 1) - query(left_cnt, full_col))) << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}