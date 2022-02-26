#include <iostream>

using namespace std;

int a[110];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += i * (n - i + 1);
		if (a[i] == 0) res += i * (n - i + 1);
	}

	cout << res << '\n';
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