#include <iostream>

using namespace std;

int a[100010];
int c[100010];

void solve()
{
	int n;
	cin >> n;

	int odd_cnt = 0, even_cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] %= 2;
		if (a[i]) odd_cnt++;
		else even_cnt++;
	}

	if (abs(odd_cnt - even_cnt) > 1)
	{
		cout << -1 << '\n';
		return;
	}
	else if (n == 1)
	{
		cout << 0 << '\n';
		return;
	}

	long long res = 0x3f3f3f3f3f3f3f3f;
	if (odd_cnt >= even_cnt)
	{
		c[1] = 1, c[0] = 2;
		long long cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += abs(c[a[i]] - i);
			c[a[i]] += 2;
		}
		res = min(res, cnt);
	}

	if (odd_cnt <= even_cnt)
	{
		c[1] = 2, c[0] = 1;
		long long cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += abs(c[a[i]] - i);
			c[a[i]] += 2;
		}
		res = min(res, cnt);
	}

	cout << res / 2 << '\n';
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