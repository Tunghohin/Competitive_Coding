#include <iostream>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long ull;

int main()
{
	ull n;
	cin >> n;

	ull res = n * n;
	for (ull l = 1; l <= n; l++)
	{
		ull d = n / l, r = n / d;
		res -= d * (r - l + 1) * (r + l) / 2;
		l = r;
	}
	cout << res % (1ll << 60) << '\n';
}