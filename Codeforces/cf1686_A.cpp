#include <iostream>
#include <algorithm>

using namespace std;

int a[110];

void solve()
{
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		if ((sum - a[i]) % (n - 1) == 0)
		{
			if ((sum - a[i]) / (n - 1) == a[i])
			{
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
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