#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

const int N = 60000001;
const int MOD = 1000000007;
int fact[N];
int inv[N];

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

    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = ((LL)fact[i - 1] * i) % MOD;
    }
    inv[n] = qpow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
    {
        inv[i] = ((LL)inv[i + 1] * (i + 1)) % MOD;
    }
        
    LL res = 0;
    LL two = qpow(2, n);
    LL big_fact = fact[n - 2];
    LL co = ((n % 2 == 1)? -1 : 1);
    for (int i = n; i >= 0; i--)
    {
        big_fact = big_fact * (2 * n - 1 - i) % MOD;
        res = (res + co * C(n, i) * big_fact % MOD * two % MOD + MOD) % MOD;
        two = two * inv[2] % MOD;
        co = -co;
    }
    
    cout << res << '\n';
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