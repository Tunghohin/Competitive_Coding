#include <iostream>

const int MOD = 998244353;

using namespace std;

bool vis[60];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	long long res = 0;

	long long cur = (1ll << k);
	int zero_cnt = k - 1;
	for (int i = 1; i <= n; i++)
	{
		long long x;
		cin >> x;

		int cnt = 0;
		for (long long p = 0; p < k; p++)
		{
			if ((x >> p) & 1ll) zero_cnt--;
			else if (!vis[p]) cnt++;
		}

		res = (res + (i * ((cur - (1ll << cnt) + MOD) % MOD)) % MOD) % MOD;
		cur = (1ll << cnt);
	}

	cout << res;
}