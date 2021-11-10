#include <bits/stdc++.h>

using namespace std;

int arr[100010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	if (n % 2 == 0)
	{
		cout << "YES\n";
		return;
	}

	for (int i = 1; i < n; i++)
	{
		if (arr[i] >= arr[i + 1])
		{
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
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