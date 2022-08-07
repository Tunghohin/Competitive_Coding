#include <iostream>
#include <algorithm>

using namespace std;

int a[200010];
int s[200010];

void solve()
{
	int n, q;
	cin >> n >> q;

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		sum += a[i];
	}

	if (sum < q)
	{
		cout << "-1\n";
		return;
	}
	else if (sum == q)
	{
		cout << 0 << '\n';
		return;
	}

	int res = -1;
	for (int i = 1; i <= n; i++)
	{
		int l = i, r = n;
		while (l < r)
		{
			int mid = (l + r + 1) / 2;
			if (s[mid] - s[i - 1] <= q) l = mid;
			else r = mid - 1;
		}
		if (s[l] - s[i - 1] == q)
		{
			res = max(res, l - i + 1);
		}
	}
	cout << n - res << '\n';
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