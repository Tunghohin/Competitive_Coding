#include <iostream>

using namespace std;

int a[200010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int length = 1;
	int tmp = a[n];
	int cnt = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		if (a[i] == tmp) length++;
		else
		{
			cnt++;
			i = i - length + 1;
			length += length;
		}
		if (i < 1) break;
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