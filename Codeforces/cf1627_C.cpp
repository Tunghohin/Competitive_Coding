#include <iostream>
#include <vector>
#include <map>

using namespace std;
using PII = pair<int, int>;

vector<int> G[100010];
map<PII, int> mp;

bool dfs(int u, int from, int type)
{
	bool statue = true;
	if (G[u].size() > 2) statue = false;
	for (auto v : G[u])
	{
		if (!statue || v == from) continue;
		type ^= 1;
		mp[{min(u, v), max(u, v)}] = type;
		statue = dfs(v, u, type);
		if (!statue) break;
	}
	return statue;
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) G[i].clear();
	mp.clear();

	vector<PII> v;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (b < a) swap(a, b);
		v.push_back({a, b});
		G[a].push_back(b);
		G[b].push_back(a);
	}

	if (!dfs(1, 0, 0))
	{
		cout << -1 << '\n';
		return;
	}
	for (auto i : v)
	{
		if (mp[i] == 0) cout << 2 << ' ';
		else if (mp[i] == 1) cout << 3 << ' ';
	}
	cout << '\n';
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