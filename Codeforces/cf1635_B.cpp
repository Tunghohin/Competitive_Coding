#include <iostream>

using namespace std;

int a[200010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int cnt = 0;
	for (int i = 2; i <= n - 1; i++)
	{
		int pr = a[i - 1];
		int nx = a[i + 1];

		if (a[i] > pr && a[i] > nx)
		{
			cnt++;
			a[i + 1] = max(a[i], a[i + 2]);
		}
	}

	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
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