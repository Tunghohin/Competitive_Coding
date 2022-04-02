#include <cstdio>

using namespace std;

int n;
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

long long f[1 << 22];
int main(){
	scanf("%d%u%u%u", &n, &A, &B, &C);
	for (int i = 0; i < (1 << n); i++)
	{
		f[i] = rng61();
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (1 << n); j++)
		{
			if (j & (1 << i)) f[j] += f[j - (1 << i)];
		}
	}
	long long res = 0;
	for (int i = 0; i < (1 << n); i++) res ^= f[i];

	printf("%lld", res);
}