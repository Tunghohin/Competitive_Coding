#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

constexpr int N = 200010;

int a[N];
int pos[N];

void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i], pos[a[i]] = i;

	int l = (n + 1) / 2, r = (n + 2) / 2;
	while (l > 0 && (l == r || pos[l] < pos[l + 1] && pos[r - 1] < pos[r]))
	{
		l--;
		r++;
	}
	cout << (n - r + l + 1) / 2 << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}