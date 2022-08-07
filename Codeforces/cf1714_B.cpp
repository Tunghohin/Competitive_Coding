#include <iostream>
#include <queue>

using namespace std;

int a[200010];
int cnt[200010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cnt[i] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = n; i >= 1; i--)
	{
		if (!cnt[a[i]])
		{
			cnt[a[i]]++;
			continue;
		}
		if (cnt[a[i]])
		{
			cout << i << '\n';
			return;
		}
	}
	cout << 0 << '\n';
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
