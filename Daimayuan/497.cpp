#include <iostream>
#include <vector>
#define int long long

using namespace std;

long long dp[32][2];
int a[300010];
int t[31 * 300010][2], idx;
vector<int> g[31 * 300010];

void add(int num, int pos)
{
	int u = 0;
	for (int i = 29; i >= 0; i--)
	{
		int bit = (num >> i) & 1;
		if (!t[u][bit]) t[u][bit] = ++idx;
		u = t[u][bit];
		g[u].push_back(pos);
	}
}

void cal(int u, int b)
{
	int L = t[u][0], R = t[u][1];
	if (L) cal(L, b - 1);
	if (R) cal(R, b - 1);

	int res = 0;
	int i = 0;
	for (int x : g[L])
	{
		while (i < g[R].size() && x > g[R][i]) i++;
		res += i;
	}

	dp[b][0] += res;
	dp[b][1] += (long long)g[L].size() * (long long)g[R].size() - res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		add(a[i], i);
	}

	cal(0, 29);

	int inv = 0, res = 0;
	for (int i = 0; i <= 29; i++)
	{
		inv += min(dp[i][0], dp[i][1]);
		if (dp[i][1] < dp[i][0]) res += (1 << i);
	}

	cout << inv << ' ' << res << '\n';
}