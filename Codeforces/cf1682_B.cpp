#include <iostream>

using namespace std;

int a[200010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int cnt = (1 << 30) - 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != i - 1) cnt &= a[i];
	}

	cout << cnt << '\n';
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