#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;
using LL = long long;

const int MOD = 1000003;

LL a[1010];
LL prefix_mul[1010], inv[1010];
LL dp[1010][1010];

int q_pow(int a, int k, int p)
{
    int res=1%p;
    while (k)
    {
        if (k&1) res=((LL)res*a)%p;
        k>>=1;
        a=((LL)a*a)%p;
    }
    return res % p;
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	prefix_mul[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		prefix_mul[i] = (prefix_mul[i - 1] * a[i]) % MOD;
		inv[i] = q_pow(prefix_mul[i], MOD - 2, MOD);
	}

	for (int len = 2; len <= n; len++)
	{
		for (int l = 1; l + len <= n + 1; l++)
		{
			int r = l + len - 1;
			for (int k = l; k < r; k++)
			{
				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] 
					+ ((LL)prefix_mul[r] * inv[k] % MOD - (LL)prefix_mul[k] * inv[l - 1] % MOD) 
					* ((LL)prefix_mul[r] * inv[k] % MOD - (LL)prefix_mul[k] * inv[l - 1] % MOD));
			}
		}
	}

	cout << dp[1][n] << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}