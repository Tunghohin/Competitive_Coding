#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int n, k, cnt = 0;
		cin >> n >> k;

		int a[100010], b[100010];

		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			b[i] = a[i];
		}

		sort(b + 1, b + 1 + n);

		for (int i = 1; i <= n; i++)
		{
			a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - &b[0];
		}

		for (int i = 1; i <= n; i++)
		{
			cnt++;
			while (i < n && a[i + 1] == a[i] + 1) i++;
		}

		cnt <= k? cout << "Yes\n" : cout << "No\n";
	}

	return 0;
}