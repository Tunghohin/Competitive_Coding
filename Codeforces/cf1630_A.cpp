#include <iostream>
#include <vector>
#include <map>

using namespace std;
using PII = pair<int, int>;

int inv(int x, int n)
{
	return (n - 1) ^ x;
}

void solve()
{
	int n, k;
	cin >> n >> k;

	vector<PII> res;
	if (k == 0)
	{
		for (int i = 0; i < n / 2; i++)
		{
			res.push_back({i, inv(i, n)});
		}
	}
	if (k > 0 && k < n - 1)
	{
		int cur = min(k, inv(k, n));
		for (int i = 1; i < n / 2; i++)
		{
			if (i != cur)
			{
				res.push_back({i, inv(i, n)});
			}
		}
		res.push_back({k, n - 1});
		res.push_back({inv(k, n), 0});
	}
	if (k == n - 1)
	{
		if (n == 4)
		{
			cout << -1 << '\n';
			return;
		}

		for (int i = 3; i < n / 2; i++)
		{
			res.push_back({i, inv(i, n)});
		}
		res.push_back({n - 1, n - 2});
		res.push_back({n - 3, 1});
		res.push_back({2, 0});
	}

	for (auto i : res)
	{
		cout << i.first << ' ' << i.second << '\n';
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