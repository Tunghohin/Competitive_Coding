#include <map>
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int a[100010];
int b[100010];

void solve()
{
	int n;
	cin >> n;

	map<int, int> mp;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		mp[b[i]] = i;
	}

	for (int i = 2 * n - 2; i >= 2; i-= 2) mp[i] = min(mp[i], mp[i + 2]);

	int res = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		res = min(res, mp[a[i] + 1] + i - 2);
	}

	cout << res << '\n';
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