#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int n;
int a[2010];

int find(int idx, long long sum)
{
	int cur_res = idx - 1;
	for (int i = idx, j = idx; i <= n; i++)
	{
		long long cur_sum = 0;
		while (cur_sum < sum && j <= n)
		{
			cur_sum += a[j++];
		}
		if (cur_sum != sum) return n;
		else
		{
			cur_res = max(cur_res, j - i);
			i = j - 1;
			cur_sum = 0;
		}
	}
	return cur_res;
}

void solve()
{
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	long long sum = 0;
	int res = n;
	for (int len = 1; len <= n; len++)
	{
		sum += a[len];
		res = min(res, find(len + 1, sum));
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