#include <iostream>

using namespace std;

const int N = 200010;

int n, q;
long long tr[N];
int a[N];

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

long long query(int x)
{
	long long res = 0;
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

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		tr[i] += a[i];
		int f = i + low_bit(i);
		if (f <= n) tr[f] += tr[i];
	}

	while (q--)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			int x, d;
			cin >> x >> d;
			modify(x, (long long)d - a[x]);
			a[x] = d;
		}
		else
		{
			int x;
			cin >> x;
			cout << query(x) << '\n';
		}
	}
}