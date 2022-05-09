#include <iostream>
#include <algorithm>

using namespace std;

long long a[200010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + 1 + n);

	a[n] - a[n - 1] <= 1? cout << "YES\n" : cout << "NO\n";
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