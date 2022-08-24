#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int MOD = 1e9 + 7;
const int N = 1000010;

int n;
LL dp[N];
LL res[N];
vector<int> G[N];

int q_pow(int a, int k, int p)
{
    int res=1%p;

    while (k)
    {
        if (k&1) res=(LL)res*a%p;
        k>>=1;
        a=(long long)a*a%p; 
    }

    return res % MOD;
}


void dfs_1(int u, int from)
{
	dp[u] = 1;
	for (auto v : G[u])
	{
		if (v == from) continue;
		dfs_1(v, u);
		dp[u] = dp[u] * (dp[v] + 1) % MOD;
	}
}

void dfs_2(int u, int from)
{
	if ((dp[u] + 1) % MOD == 0)
	{
		dfs_1(u, u);
		res[u] = dp[u];
	}
	else
	{
		res[u] = (1ll + res[from] * q_pow(dp[u] + 1, MOD - 2, MOD)) % MOD * dp[u] % MOD;
	}

	for (auto v : G[u])
	{
		if (v == from) continue;
		dfs_2(v, u);
	}
}

void solve()
{
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs_1(1, 0);
	dfs_2(1, 0);

	for (int i = 1; i <= n; i++)
	{
		cout << res[i] % MOD << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}