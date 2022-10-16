#include <bits/stdc++.h>

using namespace std;

void solve()
{
	long long n, k;
	cin >> n >> k;

	vector<long long> a(n + 1), s(n + 1);
	for (int i = n - k + 1; i <= n; i++) cin >> s[i];

	for (int i = n - k + 2; i <= n; i++)
	{
		a[i] = s[i] - s[i - 1];
	}

	if (k == 1)
	{
		cout << "Yes\n";
		return;
	}

	if (!is_sorted(a.begin() + n - k + 2, a.end()))
	{
		cout << "No\n";
		return;
	}

	if (s[n - k + 1] > a[n - k + 2] * (n - k + 1))
	{
		cout << "No\n";
		return;
	}

	cout << "Yes\n";
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