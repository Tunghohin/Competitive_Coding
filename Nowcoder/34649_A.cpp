#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 200010;

vector<int> G[N];
vector<PII> coup;

int color[N];
bool bio_graph(int u, int type)
{
	color[u] = type;
	for (auto to: G[u])
		if (!color[to])
		{
			if (!bio_graph(to, 3 - type)) return false;
		}
		else if (color[to] == type) return false;
	return true;
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		coup.push_back({a, b});
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= 2 * n; i += 2)
	{
		G[i].push_back(i + 1);
		G[i + 1].push_back(i);
	}

	for (int i = 1; i <= 2 * n; i++)
	{
		if (!color[i]) bio_graph(i, 1);
	}

	for (auto u : coup)
	{
		cout << color[u.first] << ' ' << color[u.second] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}