#include <iostream>

using namespace std;

int a[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		bool all_one = true;

		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (i == 1 || i == n) continue;
			if (all_one) all_one = (a[i] == 1);
		}

		if (all_one)
		{
			cout << -1 << '\n';
			continue;
		}

		if (n == 3 && (a[2] % 2))
		{
			cout << -1 << '\n';
			continue;
		}

		if (n == 2)
		{
			cout << 0 << '\n';
			continue;
		}

		long long res = 0;
		for (int i = 2; i <= n - 1; i++)
		{
			res += (a[i] + 1) / 2;
		}

		cout << res << '\n';
	}
}