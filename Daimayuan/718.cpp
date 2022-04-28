#include <iostream>

using namespace std;

const int N = 1000010;
unsigned int a[N];
int n, q;
unsigned int spt[N][29];

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

int main(){
	scanf("%d%d%u%u%u", &n, &q, &A, &B, &C);
	for (int i = 1; i <= n; i++) {
		a[i] = rng61();
		spt[i][0] = a[i];
	}

	for (int j = 1; j <= 20; j++)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			spt[i][j] = max(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
		}
	}

	unsigned int res = 0;
	for (int i = 1; i <= q; i++) {
		unsigned int l = rng61() % n + 1, r = rng61() % n + 1;
		if (l > r) swap(l, r);
		int len = __lg(r - l + 1);
		res ^= max(spt[l][len], spt[r - (1 << len) + 1][len]);
	}

	cout << res;
}