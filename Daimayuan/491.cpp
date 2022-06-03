#include <iostream>

using namespace std;

int p, n;
unsigned int A, B, C;
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
int a[10000010];
int s[10000010];
int sv[10000010];
int inv[10000010];

int q_pow(int x, int k)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (long long)res * x % p;
		x = (long long)x * x % p;
		k >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> p >> n >> A >> B >> C;
	for (int i = 1; i <= n; i++)
	{
		a[i] = rng61() % p;
	}

	s[0] = 1;
	for (int i = 1; i <= n; i++) s[i] = (long long)s[i - 1] * a[i] % p;
	sv[n] = q_pow(s[n], p - 2);
	for (int i = n; i >= 1; i--)
	{
		sv[i - 1] = (long long)sv[i] * a[i] % p;
	}

	for (int i = 1; i <= n; i++)
	{
		inv[i] = (long long)sv[i] * s[i - 1] % p;
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res ^= inv[i];
	}
	cout << res << '\n';
}