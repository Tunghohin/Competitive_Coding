#include <bits/stdc++.h>

#define int long long

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

const int N = 200010;

int a[N];

int dg_sum(int x)
{
	int res = 0;
	while (x)
	{
		res += x % 10;
		x /= 10;
	}
	return res;
}

struct BIT
{
	int low_bit(int x)
	{
		return x & -x;
	}

	int size = 5;
	int tr[N];

	void update(int x, int k)
	{
		for (; x <= size; x += low_bit(x))
		{
			tr[x] += k;
		}
	}

	void update(int l, int r, int k)
	{
		update(l, k);
		update(r + 1, -k);
	}

	int query(int x)
	{
		int res = 0;
		for (; x; x -= low_bit(x))
		{
			res += tr[x];
		}
		return res;
	}

	void to_zero(int x)
	{
		int now = query(x);
		update(x, x, -now);
	}
};
BIT t;

void solve()
{
	int n, q;
	cin >> n >> q;

	t.size = n + 5;

	for (int i = 0; i <= n; i++) t.tr[i] = 0;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= q; i++)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int l, r;
			cin >> l >> r;
			t.update(l, r, 1);
		}
		else
		{
			int x;
			cin >> x;
			int cnt = t.query(x);
			if (cnt > 3) cnt = 3;

			while (cnt--)
			{
				a[x] = dg_sum(a[x]);
			}

			t.to_zero(x);
			cout << a[x] << '\n';
		}

		// for (int i = 1; i <= n; i++) cout << a[i] << ' ';
		// cout << '\n';
		// for (int i = 1; i <= n; i++) cout << t.query(i) << ' ';
		// cout << "\n\n";
	}
}


/*
1
5 8
1 420 69 1434 2023
1 2 3
2 2
2 3
2 4
1 2 5
2 1
2 3
2 5

1
5 2
1 420 69 1434 2023
1 2 3
2 2
*/

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}