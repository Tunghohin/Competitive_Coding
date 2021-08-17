#include <iostream>

using namespace std;

int a[100010];
long long tr[100010], s[100010];

int low_bit(int x)
{
	return x & -x;
}

void add(int x, long long k, int n)
{
	while (x <= n + 1)
	{
		tr[x] += k;
		x += low_bit(x);
	}
}

long long get(int x)
{
	long long res = 0;
	while (x > 0)
	{
		res += tr[x];
		x -= low_bit(x);
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		a[i]++;
		s[a[i]] += i - 1 - get(a[i]);
		add(a[i], 1, n);
	}

	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		cout << res << '\n';
		res += s[i];
	}
}