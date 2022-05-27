#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int a[200010];

void solve()
{
	int n, k;
	cin >> n >> k;

	long long tot_damage = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		tot_damage += a[i];
		a[i] += i;
	}

	sort(a + 1, a + 1 + n);

	for (int i = n; i > n - k; i--) tot_damage -= a[i];

	for (int i = 0; i < k; i++)
	{
		tot_damage += n;
		tot_damage -= i;
	}

	cout << tot_damage << '\n';
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