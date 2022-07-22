#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long a[50010];
long long b[50010];

void solve()
{
	long long n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) cin >> b[i];

	vector<pair<int, long long>> aa;
	vector<pair<int, long long>> bb;

	for (int i = 1; i <= n; i++)
	{
		long long cur = a[i];
		long long cnt = 1;

		while (cur % m == 0)
		{
			cur /= m;
			cnt *= m;
		}

		if (!aa.empty() && aa.back().first == cur)
		{
			auto u = aa.back();
			aa.pop_back();
			u.second += cnt;
			aa.push_back(u);
		}
		else aa.push_back({cur, cnt});
	}

	for (int i = 1; i <= k; i++)
	{
		long long cur = b[i];
		long long cnt = 1;
		while (cur % m == 0)
		{
			cur /= m;
			cnt *= m;
		}
		if (!bb.empty() && bb.back().first == cur)
		{
			auto u = bb.back();
			bb.pop_back();
			u.second += cnt;
			bb.push_back(u);
		}
		else bb.push_back({cur, cnt});
	}


//	for (auto i : aa)
//	{
//		cout << i.first << ' ' << i.second << '\n';
//	}

	if (aa.size() != bb.size())
	{
		cout << "No\n";
		return;
	}
	for (int i = 0; i < aa.size(); i++)
	{
		if (aa[i] != bb[i])
		{
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
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