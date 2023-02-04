#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

constexpr double PI = acos(-1);

void solve()
{
	int n, q;
	cin >> n >> q;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++)
	{
		int cost;
		cin >> cost;
		pq.push(cost + i);
	}

	int res = 0;
	while (!pq.empty())
	{
		auto u = pq.top();
		pq.pop();

		if (u <= q)
		{
			q -= u;
			res++;
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