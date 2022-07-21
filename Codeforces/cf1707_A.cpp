#include <iostream>

using namespace std;

int a[200010];
int vis[200010];

void solve()
{
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int cur_q = 0;
	for (int i = n; i >= 1; i--)
	{
		if (a[i] <= cur_q) vis[i] = 1;
		else if (cur_q < q) cur_q++, vis[i] = 1;
		else vis[i] = 0;
	}
	for (int i = 1; i <= n; i++) cout << vis[i];
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