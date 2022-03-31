#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 110, M = 1010;
int mod = 1000000007;

long long res[N];

long long q_pow(long long a, int k, const long long p)
{
	long long res = 1;
	while (k)
	{
		if (k & 1)
		{
			res = res * a % p;
		}
		a = a * a % p;
		k >>= 1;
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> son[N];
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		son[a].push_back(b);
	}

	for (int i = n - 1; i >= 1; i--)
	{
		long long size = (int)son[i].size();
		res[i] = 1;
		for (auto to : son[i])
		{
			res[i] += res[to] * q_pow(size, mod - 2, mod);
			res[i] %= mod;
		}
	}

	cout << res[1];
}