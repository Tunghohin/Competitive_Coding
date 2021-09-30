#include <iostream>
#define int long long

using namespace std;

long long a[100010];
long long tr1[100010], tr2[100010];

int low_bit(int x)
{
	return x & -x;
}

void add(int x, int k, long long t[], int n)
{
	while (x <= n)
	{
		t[x] += k;
		x += low_bit(x);
	}
}

long long get_prefix(int x, int const *t)
{
	long long res = 0;

	while (x >= 1)
	{
		res += t[x];
		x -= low_bit(x);
	}

	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		add(i, a[i], tr1, n);
		add(i, a[i] * i, tr2, n);
	}

	for (int i = 1; i <= m; i++)
	{
		string q;
		cin >> q;

		if (q[0] == 'Q')
		{
			int x;
			cin >> x;

			cout << (x + 1) * get_prefix(x, tr1) - get_prefix(x, tr2) << '\n';
		}

		else
		{
			int x, k;
			cin >> x >> k;

			add(x, k - a[x], tr1, n);
			add(x, (k - a[x]) * x, tr2, n);

			a[x] = k;
		}
	}

	return 0;
}