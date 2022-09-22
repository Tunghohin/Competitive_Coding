#include <iostream>

using namespace std;

typedef long long LL;

const int MOD = 998244353;
const int N=100010;

int qpow(int a, int k, int p)
{
    int res=1%p;
    while (k)
    {
        if (k&1) res=(LL)res*a%p;
        k>>=1;
        a=(LL)a*a%p;
    }
    return res % MOD;
}

int C(int a, int b, int p)
{
    if (b>a) return 0;

    int res=1;
    for (int i=1,j=a;i<=b;i++,j--)
    {
        res=(LL)res*j%p;
        res=(LL)res*qpow(i, p-2, p)%p;
    }

    return res % MOD;
}

int lucas(LL a, LL b, int p)
{
    if (a<p && b<p) return C(a, b, p);
    return (LL)C(a%p, b%p, p)* lucas(a/p, b/p, p)%p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int A, B;
	cin >> A;
	int tmp;
	for (int i = 1; i <= 7; i++) cin >> tmp;
	cin >> B;
	for (int i = 1; i <= 7; i++) cin >> tmp;

	A = (A / 10) + (A % 10 != 0);
	B = (B / 10) + (B % 10 != 0);

	LL res = 0;
	for (int i = 0; i < A; i++)
	{
		res = (res + ((lucas(i + B - 1, i, MOD) * qpow(qpow(2, B + i, MOD) % MOD, MOD - 2, MOD))) % MOD) % MOD;
	}
	cout << res % MOD << '\n';
}