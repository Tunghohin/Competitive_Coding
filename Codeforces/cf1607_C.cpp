#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long a[200010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	if (n == 1)
	{
		cout << a[1] << '\n';
		return;
	}

	sort(a + 1, a + 1 + n);

	long long max_n = -0x3f3f3f3f;

	for (int i = 1; i <= n; i++)
	{
		max_n = max(max_n, a[i] - a[i - 1]);
	}

	cout << max_n << '\n';
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