#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

const int MOD = 998244353;
const int N = 5001;

int fact[N * N], inv[N * N];

int qpow(int a, int k)
{
    int res=1%MOD;
    while (k)
    {
        if (k&1) res=((LL)res*a)%MOD;
        k>>=1;
        a=((LL)a*a)%MOD;
    }
    return res;
}

LL C(int a, int b)
{
    return (LL)fact[a] * inv[a - b] % MOD * inv[b] % MOD;
}

void solve()
{
    int n;
    cin >> n;

    LL res = 0;
    for (int i = 1; i <= n; i++)
    {
        LL cur = 1;
        for (int j = 1; j <= i; j++) cur = (cur * fact[n]) % MOD;
        res = (res + (C(n, i) * C(n - 1, i - 1) % MOD * fact[i] % MOD * cur % MOD * fact[n * n - n] % MOD * i % MOD) % MOD);
        //cout << res << '\n';
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;

    const LL f = 5000;
    fact[0] = 1;
    for (int i = 1; i <= f * f; i++)
    {
        fact[i] = ((LL)fact[i - 1] * i) % MOD; 
    }
    inv[f * f] = qpow(fact[f * f], MOD - 2);
    for (int i = f * f - 1; i >= 0; i--)
    {
        inv[i] = ((LL)inv[i + 1] * (i + 1)) % MOD;
    }

    while (T--)
    {
        solve();
    }
}