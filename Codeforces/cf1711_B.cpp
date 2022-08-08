#include <iostream>
#include <vector>

using namespace std;

using PII = pair<int, int>;

long long inf64 = (1ll << 60);
vector<PII> edges;
int dg[100010];
int val[100010];

void solve()
{
	int n, m;
	cin >> n >> m;

	edges.clear();

	for (int i = 1; i <= n; i++)
	{
		dg[i] = 0;
		cin >> val[i];
	}

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
		dg[u]++, dg[v]++;
	}

	if (m % 2 == 0)
	{
		cout << 0 << '\n';
		return;
	}

	long long res = inf64;
	for (int i = 1; i <= n; i++)
	{
		if (dg[i] % 2 == 1) res = min(res, (long long)val[i]);
	}

	for (auto [u, v] : edges)
	{
		if (dg[u] % 2 == 0 && dg[v] % 2 == 0) res = min(res, (long long)val[u] + val[v]);
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