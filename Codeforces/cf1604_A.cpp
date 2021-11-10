#include <bits/stdc++.h>

using namespace std;

int arr[110];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	unsigned long long res = 0;
	arr[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] - arr[i - 1] > 1)
		{
			res += arr[i] - arr[i - 1] - 1;

		}
		else
		{
			arr[i] = arr[i - 1] + 1;
		}
	}

	cout << res << '\n';
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