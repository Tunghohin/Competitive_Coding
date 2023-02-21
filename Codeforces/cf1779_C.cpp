#include <bits/stdc++.h>

#define int long long

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

constexpr int N = 200010;
constexpr LL inf64 = 0x3f3f3f3f3f3f3f3f;

int a[N];

void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int res = 0;
	priority_queue<int> pq_g;
	int sum = 0;
	for (int i = m; i > 1; i--)
	{
		pq_g.push(a[i]);
		sum += a[i];
		if (sum > 0)
		{
			auto u = pq_g.top();
			pq_g.pop();
			sum -= 2 * u;
			res++;
		}
	}

	//cout << res << '\n';
	sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq_l;
	for (int i = m + 1; i <= n; i++)
	{
		sum += a[i];
		pq_l.push(a[i]);

		if (sum < 0)
		{
			sum -= 2 * pq_l.top();
			res++;
			pq_l.pop();
		}
	}

	cout << res << '\n';
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