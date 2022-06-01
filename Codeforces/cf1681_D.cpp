#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

typedef unsigned long long ull;

void solve()
{
	int n;
	ull x;
	cin >> n >> x;

	map<ull, int> mp;
	queue<ull> q;

	mp[x] = 0;
	q.push(x);

	while (!q.empty())
	{
		auto u = q.front();
		q.pop();
		string num = to_string(u);

		if (num.length() == n)
		{
			cout << mp[u] << '\n';
			return;
		}

		for (int i = 0; i < (int)num.length(); i++)
		{
			if (num[i] == '0') continue;
			ull target = u * (int)(num[i] - '0');
			if (!mp.count(target))
			{
				mp[target] = mp[u] + 1;
				q.push(target);
			}
		}
	}
	cout << -1 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	T = 1;

	while (T--)
	{
		solve();
	}
}