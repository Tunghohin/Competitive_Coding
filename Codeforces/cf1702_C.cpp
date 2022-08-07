#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

using PII = pair<int, int>;

map<int, PII> mp;

void solve()
{
	int n, q;
	cin >> n >> q;

	mp.clear();
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (!mp.count(x)) mp[x] = {i, i};
		else mp[x].second = i;
	}

	for (int i = 1;i <= q; i++)
	{
		int a, b;
		cin >> a >> b;
		if (!mp.count(a) || !mp.count(b) || mp[a].first > mp[b].second)
		{
			cout << "No\n";
		}
		else cout << "Yes\n";
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