#include <bits/stdc++.h>

using namespace std;

int arr[100010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		if (arr[i] % (i + 1) != 0) continue;

		bool flag = false;
		for (int j = 2; j <= 20 && j <= i; j++)
		{
			if (arr[i] % j != 0) flag = true;
		}
		if (flag) continue;

		cout << "NO\n";
		return;
	}

	cout << "YES\n";
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}