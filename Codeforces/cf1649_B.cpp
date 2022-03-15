#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	long long maxn = -1, sum = 0;

	for (int i = 1; i <= n; i++)
	{
		long long x;
		cin >> x;

		sum += x;
		maxn = max(maxn, x);
	}

	if (sum == 0) cout << 0 << '\n';
	else
	{
		sum -= maxn;
		if (maxn > sum) cout << maxn - sum << '\n';
		else cout << 1 << '\n';
	}
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