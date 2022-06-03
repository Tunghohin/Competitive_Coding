#include <iostream>

using namespace std;

int p, n;
int inv[10000010];

int main()
{
	cin >> p >> n;
	inv[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		inv[i] = (long long)(p - p / i) * inv[p % i] % p;
	}
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		res ^= inv[i];
	}
	cout << res;
}