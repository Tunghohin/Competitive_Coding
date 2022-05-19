#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, q;

void solve()
{
	cin >> n >> q;
	map<long long, long long> mp;
	long long sum = 0;
	long long last_sec = 0;

	for (int i = 1; i <= n; i++)
	{
		long long x;
		cin >> x;
		sum += x;
		mp[i] = x;
	}

	for (int i = 1; i <= q; i++)
	{
		int op;
		cin >> op;

		if (op == 2)
		{
			long long val;
			cin >> val;

			mp.clear();
			sum = val * (long long)n;
			last_sec = val;
		}
		else
		{
			int idx;
			long long val;
			cin >> idx >> val;

			if (mp[idx])
			{
				sum += val - mp[idx];
				mp[idx] = val;
			}
			else
			{
				mp[idx] = val;
				sum += val - last_sec;
			}
		}

		cout << sum << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}