#include <iostream>

using namespace std;

const int N = 200010;

unsigned long long tr1[N], tr2[N];

int n, q;

int low_bit(int x)
{
	return x & (-x);
}

void modify(int x, long long d, unsigned long long *tr)
{
	for (; x <= n; x += low_bit(x))
	{
		tr[x] += d;
	}
}

unsigned long long query(int x, const unsigned long long *tr)
{
	unsigned long long res = 0;
	for (; x; x -= low_bit(x))
	{
		res += tr[x];
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> q;

	for (int i = 1; i <= q; i++)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int l, r;
			long long d;
			cin >> l >> r >> d;
			modify(l, d, tr1), modify(r + 1, -d, tr1);
			modify(l, d * l, tr2), modify(r + 1, (r + 1) * (-d), tr2);
		}
		else
		{
			int x;
			cin >> x;

			unsigned long long res;
			res = query(x, tr1) * (x + 1) - query(x, tr2);
			cout << res << '\n';
		}
	}
}