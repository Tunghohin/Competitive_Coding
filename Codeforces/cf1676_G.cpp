#include <iostream>
#include <vector>

using namespace std;

const int N = 4010;

int s[N];
int dfn[N], timestamp = 0;
int L[N], R[N];
int val[N];
vector<int> G[N];

void dfs(int u, int from)
{
	L[u] = ++timestamp;
	dfn[timestamp] = u;

	for (auto v : G[u])
	{
		if (v == from) continue;
		dfs(v, u);
	}

	R[u] = timestamp;
}

void solve()
{
	int n;
	cin >> n;

	timestamp = 0;
	for (int i = 1; i <= n; i++) G[i].clear();

	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		G[i].push_back(x);
		G[x].push_back(i);
	}

	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		if (c == 'W') val[i] = 1;
		else val[i] = 0;
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + val[dfn[i]];
	}

	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		int len = R[i] - L[i] + 1;
		int sum = s[R[i]] - s[L[i] - 1];

		if (sum * 2 == len) res++;
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