#include <iostream>

using namespace std;

long long pow2[31623];

int main()
{
	int T;
	cin >> T;

	for (long long i = 1; i <= 31623; i++)
	{
		pow2[i] = i * i;
	}

	while (T--)
	{
		long long x;
		cin >> x;

		long long pos = 1;
		for (int i = 1; i <= 31623; i++)
		{
			pos = i;
			if (pow2[i] >= x) break;
		}

		long long cnt = 0;
		for (long long i = pow2[pos]; i >= pow2[pos] - pos - pos + 1; i--)
		{
			cnt ++;
			if (i == x) break;
		}

		if (cnt <= pos)
		{
			cout << pos << ' ' << cnt << '\n';
		}
		else
		{
			cout << pos - (cnt - pos) << ' ' << pos << '\n';
		}
	}

}