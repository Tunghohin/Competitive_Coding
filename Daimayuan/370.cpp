#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long f[(1 << 24) + 10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;

		int num = 0;
		for (int j = 0; j < 3; j++) num |= 1 << (int)(s[j] - 'a');

		for (int j = num; j; j = (j - 1) & num)
		{
			if (__builtin_popcount(j) & 1) f[j]++;
			else f[j]--;
		}
	}

	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < (1 << 24); j++)
		{
			if (j & (1 << i)) f[j] += f[j - (1 << i)];
		}
	}

	long long res = 0;
	for (int i = 0; i < (1 << 24); i++)
	{
		res ^= (f[i] * f[i]);
	}

	cout << res;
}