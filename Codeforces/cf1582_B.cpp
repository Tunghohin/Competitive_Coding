#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int a[100];

void solve()
{
	int n;
	cin >> n;

	int one_cnt = 0, zero_cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 1) one_cnt++;
		else if (a[i] == 0) zero_cnt++;
	}

	if (!one_cnt)
	{
		cout << 0 << '\n';
		return;
	}

	else
	{
		long long two_pow = 1;
		for (int i = 1; i <= zero_cnt; i++) two_pow *= 2;

		cout << two_pow * one_cnt << '\n';
	}
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