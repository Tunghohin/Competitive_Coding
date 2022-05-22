#include <iostream>

using namespace std;

int a[200010];

bool check(int x, int n)
{

}

void solve()
{
	int n, d;
	cin >> n >> d;

	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = d + 1;

	int l = 0, r = d + 1;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (check(mid, n)) l = mid;
		else r = mid - 1;
	}

	cout << l << '\n';
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