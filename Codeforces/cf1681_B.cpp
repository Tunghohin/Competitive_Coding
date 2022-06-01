#include <iostream>

using namespace std;

int a[200010];

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int idx = 0;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		idx = (idx + x) % n;
	}

	cout << a[idx] << '\n';
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