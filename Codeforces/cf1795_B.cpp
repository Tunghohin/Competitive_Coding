#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

constexpr int N = 100;

int covered_l[N];
int covered_r[N];

void solve()
{
	int n, k;
	cin >> n >> k;

	memset(covered_l, 0, sizeof(covered_l));
	memset(covered_r, 0, sizeof(covered_r));//

	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		covered_l[l]++;
		covered_r[r]++;
	}
	//cout << covered_l[k] << ' ' << covered_r[k] << '\n';
	if (covered_l[k] >= 1 && covered_r[k] >= 1)
	{
		cout << "Yes\n";
		return;
	}
	cout << "No\n";
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