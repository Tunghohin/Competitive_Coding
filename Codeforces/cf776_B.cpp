#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int primes[1000010], cnt;
bool vis[1000010];

void linear_sieve(int n)
{
	memset(vis, false, sizeof(vis));
	vis[1] = true;
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i]) primes[cnt++] = i;

		for (int j = 0; primes[j] <= n / i; j++)
		{
			vis[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int main()
{
	int n;
	cin >> n;

	linear_sieve(n + 1);

	n > 2? cout << 2 << '\n' : cout << 1 << '\n';

	for (int i = 2; i <= n + 1; i++)
	{
		if (!vis[i]) cout << 1 << ' ';
		else cout << 2 << ' ';
	}

	return 0;
}