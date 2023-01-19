#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;
using LL = long long;

const int N = 200010;
const int MOD = 998244353;

int two_pow[N];

int qpow(int a, int k, int p)
{
    int res=1%p;
    while (k)
    {
        if (k&1) res=((LL)res*a)%p;
        k>>=1;
        a=((LL)a*a)%p;
    }
    return res;
}

int C(int a, int b, int p)//因为b一定小于p，所以单次计算裸式展开为blogb显然比方法二快
{
    if (b>a) return 0;

    int res=1;
    for (int i=1,j=a;i<=b;i++,j--)
    {
        res=(LL)res*j%p;
        res=(LL)res*qpow(i, p-2, p)%p;
    }

    return res;
}

int lucas(LL a, LL b, int p)
{
    if (a<p && b<p) return C(a, b, p);
    return ((LL)C(a%p, b%p, p)*lucas(a/p, b/p, p))%p;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	cout << ((lucas(m, n - 1, MOD) * (n - 2) % MOD) % MOD * two_pow[n - 3]) % MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	two_pow[0] = 1;
	for (int i = 1; i <= 199997; i++)
	{
		two_pow[i] = (2ll * (LL)two_pow[i - 1]) % MOD; 
	}

	solve();
}