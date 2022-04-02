#include <iostream>

using namespace std;

const int N = (1 << 22) + 10;

long long a[N];
long long f[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < (1 << 22); i++) f[i] = n + 1;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[i] = x;
		f[x] = min(f[x], (long long)i);
	}

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < (1 << 22); j++)
		{
			if (j & (1 << i)) f[j] = min(f[j], f[j - (1 << i)]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int x = (1 << 22) - 1 - a[i];
		f[x] > n? cout << -1 << ' ' : cout << f[x] << ' ';
	}
}