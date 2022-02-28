#include <iostream>

using namespace std;

int a[200010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	if (a[n] < a[n - 1])
	{
		cout << -1 << '\n';
		return;
	}

	if (a[n] < 0)
	{
		bool ok = true;
		for (int i = 1; i < n && ok; i++) ok = (a[i] <= a[i + 1]);

		if (ok) cout << 0 << '\n';
		else cout << -1 << '\n';

		return;
	}

	cout << n - 2 << '\n';
	for (int i = n - 2; i >= 1; i--)
	{
		cout << i << ' ' << n - 1 << ' ' << n << '\n';
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