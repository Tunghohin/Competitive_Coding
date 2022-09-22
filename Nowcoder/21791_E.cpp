#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

const int MOD = 998244353;

int C[5010][5010];
int fact[5010];

void solve()
{
	LL a, b, c;
	cin >> a >> b >> c;

	LL res_ab = 0;
	for (int k = 0; k <= min(a, b); k++)
	{
		LL fst = C[a][k];
		LL sec = ((LL)C[b][k] * fact[k]) % MOD;
		res_ab = (res_ab + fst * sec % MOD) % MOD;
	}

	int res_ac = 0;
	for (int k = 0; k <= min(a, c); k++)
	{
		LL fst = C[a][k];
		LL sec = ((LL)C[c][k] * fact[k]) % MOD;
		res_ac = (res_ac + fst * sec % MOD) % MOD;
	}

	int res_bc = 0;
	for (int k = 0; k <= min(c, b); k++)
	{
		LL fst = C[b][k];
		LL sec =((LL)C[c][k] * fact[k]) % MOD;
		res_bc = (res_bc + fst * sec % MOD) % MOD;
	}

	LL res = ((res_ab * res_ac) % MOD * res_bc) % MOD;
	cout << res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	for (int i = 0; i <= 5000; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) C[i][j] = 1;
			else C[i][j] = ((LL)C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}

	fact[0] = 1;
	for (int i = 1; i <= 5000; i++)
	{
		fact[i] = ((LL)fact[i - 1] * i) % MOD;
		fact[i] = fact[i] % MOD;
	}

	solve();
}