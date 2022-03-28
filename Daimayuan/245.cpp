#include <iostream>

using namespace std;

long long pow_10[20];
long long num[22];
long long res[10];

void calc(long long n, int xs)
{
	int m = 0;
	while (n)
	{
		num[++m] = n % 10;
		n /= 10;
	}

	for (int i = 1, j = m; i < j; i++, j--) swap(num[i], num[j]);

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j < i; j++) res[num[j]] += num[i] * pow_10[m - i] * xs;

		for (int j = 1; j < num[i]; j++) res[j] += pow_10[m - i] * xs;
		if (i != 1 && num[i]) res[0] += pow_10[m - i] * xs;

		if (i != m)
		{
			for (int j = 1; j < 10; j++) res[j] += pow_10[m - i - 1] * (m - i) * num[i] * xs;
			if (i != 1) res[0] += pow_10[m - i - 1] * (m - i) * num[i] * xs;
		}

		if (i == 1)
		{
			if (m >= 2)
			{
				res[0] += (num[i] - 1) * pow_10[m - 2] * (m - 1) * xs;
			}
			for (int j = 2; j < m; j++)
			{
				res[0] += 9 * (m - j) * pow_10[m - j - 1] * xs;
			}
		}
	}

	for (int i = 1; i <= m; i++) res[num[i]] += xs;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	pow_10[0] = 1;
	for (int i = 1; i <= 16; i++) pow_10[i] = pow_10[i - 1] * 10;

	long long l, r;
	cin >> l >> r;

	calc(r, 1);
	calc(l - 1, -1);

	for (int i = 0; i <= 9; i++) cout << res[i] << ' ';
}