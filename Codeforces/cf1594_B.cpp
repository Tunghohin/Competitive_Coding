#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;

	long long res = 0;
	long long p = 1;
	while (k)
	{
		if (k & 1)
		{
			res = (res + p) % 1000000007;
		}
		k >>= 1;
		p = p * n;
		p %= 1000000007;
	}

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}