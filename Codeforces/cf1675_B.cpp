#include <iostream>

using namespace std;

long long a[50];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	long long cnt = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		while (a[i] >= a[i + 1] && a[i] != 0)
		{
			a[i] /= 2;
			cnt++;
		}

		if (a[i] == a[i + 1])
		{
			cout << -1 << '\n';
			return;
		}
	}

	cout << cnt << '\n';
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