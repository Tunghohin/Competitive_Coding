#include <iostream>

using namespace std;

long long calc(long long n, long long m, long long t)
{
	return n - m + (m - 1) / t * t;
}

void solve()
{
	long long n, m;
	cin >> n >> m;

	if (m % n == 0)
	{
		cout << 0 << '\n';
		return;
	}
	if (n > m)
	{
		cout << n - m << '\n';
		return;
	}

	long long res = 0x3f3f3f3f3f3f3f3f;
	for (long long l = 1; l <= min(n, m - 1); l++)
	{
		long long r = min(min(n, m - 1), (m - 1) / ((m - 1) / l));
		long long cur_res = calc(n, m, l);
		if (cur_res >= 0) res = min(res, cur_res);
		l = r;
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