#include <iostream>

using namespace std;

int a[2010];
int b[2010];
int res[2010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = n; i >= 1; i--)
	{
		int idx = 0;
		for (int j = 1; j <= i; j++)
		{
			idx = a[j] == i? j : idx;
		}

		for (int j = 1; j <= i; j++)
		{
			b[(j - idx + i) % i] = a[j];
		}

		for (int j = 1; j <= i; j++) a[j] = b[j];

		res[i] = i == 1? 0 : idx % i;
	}

	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
	cout << '\n';
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