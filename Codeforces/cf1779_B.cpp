#include <iostream>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	if (n == 3)
	{
		cout << "NO";
	}
	else if (n % 2 == 0)
	{
		cout << "YES\n";
		for (int i = 1; i <= n; i++)
		{
			if (i & 1) cout << 1 << ' ';
			else cout << -1 << ' ';
		}
	}
	else
	{
		cout << "YES\n";
		for (int i = 1; i <= n; i++)
		{
			if (i & 1) cout << 1 - (n / 2) << ' ';
			else cout << n / 2 << ' ';
		}
	}

	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}