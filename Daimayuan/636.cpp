#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

typedef long long ll;
typedef unsigned long long ull;

int n, q;
long long a[N];
long long tr[N];

int low_bit(int x)
{
	return x & (-x);
}

void modify(int x, long long v)
{
	for (; x <= n; x += low_bit(x))
	{
		tr[x] += v;
	}
}

int query(long long x)
{
	long long tmp = 0;
	int pos = 0;
	for (int i = 18; i >= 0; i--)
	{
		if (pos + (1 << i) <= n && tmp + tr[pos + (1 << i)] <= x)
		{
			pos += (1 << i);
			tmp += tr[pos];
		}
	}

	return pos;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		tr[i] += a[i];
		int j = i + low_bit(i);
		if (j <= n) tr[j] += tr[i];
	}

	while (q--)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			int x;
			long long d;
			cin >> x >> d;
			modify(x, d - a[x]);
			a[x] = d;
		}

		else
		{
			long long s;
			cin >> s;
			cout << query(s) << '\n';
		}
	}
}