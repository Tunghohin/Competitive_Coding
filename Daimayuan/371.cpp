#include <iostream>

using namespace std;

const int mod = 1000000007;

int n;
long long f[1 << 23], g[1 << 23];

unsigned int A,B,C;
inline unsigned int rng61() {
	A ^= A << 16;
	A ^= A >> 5;
	A ^= A << 1;
	unsigned int t = A;
	A = B;
	B = C;
	C ^= t ^ A;
	return C;
}

int main(){
	scanf("%d%u%u%u", &n, &A, &B, &C);
	for (int i = 0; i < (1 << n); i++)
	{
		f[i] = rng61();
	}
	for (int i = 0; i < (1 << n); i++)
	{
		g[i] = rng61();
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (1 << n); j++)
		{
			if ((j & (1 << i)) == 0)
			{
				f[j] = f[j] + f[j + (1 << i)];
				g[j] = g[j] + g[j + (1 << i)];
			}
		}
	}

	for (int i = 0; i < (1 << n); i++)
	{
		f[i] %= mod;
		g[i] %= mod;
		f[i] = f[i] * g[i] % mod;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (1 << n); j++)
		{
			if ((j & (1 << i)) == 0)
			{
				f[j] = f[j] - f[j + (1 << i)];
			}
		}
	}

	for (int i = 0; i < (1 << n); i++)
	{
		f[i] %= mod;
		if (f[i] < 0) f[i] += mod;
	}

	long long res = 0;
	for (int i = 0; i < (1 << n); i++) res ^= f[i];

	cout << res;
}
