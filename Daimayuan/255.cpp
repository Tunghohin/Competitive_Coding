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

	res[1] = 1;
	for (int i = 1; i < n; i++)
	{
		long long size = (int)son[i].size();
		for (auto to : son[i])
		{
			res[to] += res[i] * q_pow(size, mod - 2, mod);
			res[to] %= mod;
		}
	}

	cout << res[n];
}