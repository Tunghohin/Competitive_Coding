#include <iostream>

using namespace std;

int n, m, qs;
const int N = 510, M = 510;

typedef long long ll;

ll a[N][M];
ll tr[N][M];

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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m >> qs;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			modify(i, j, a[i][j]);
		}
	}

	while (qs--)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			int x, y;
			ll d;
			cin >> x >> y >> d;

			modify(x, y, d - a[x][y]);
			a[x][y] = d;
		}
		else
		{
			int x, y;
			cin >> x >> y;

			cout << query(x, y) << '\n';
		}
	}
}