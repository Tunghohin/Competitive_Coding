#include <iostream>
#include <algorithm>

using namespace std;

int a[110];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);

	long long res = 0;
	for (int i = 2; i <= n; i++)
	{
		res += a[i] - a[i - 1];
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