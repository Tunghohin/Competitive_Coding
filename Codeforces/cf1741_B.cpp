#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int a[200010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) a[i] = n - i + 1;

	if (n == 3)
	{
		cout << -1 << '\n';
		return;
	}
	for (int i = 3; i <= n; i++) cout << i << ' ';
	cout << "2 1\n";
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