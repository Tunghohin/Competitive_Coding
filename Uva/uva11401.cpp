#include <iostream>

using namespace std;

unsigned long long f[1000010];

int main()
{
	for (int i = 4; i <= 1000000; i++)
	{
		f[i] = f[i - 1] + ((unsigned long long)(i - 1) * (i - 2) / 2 - (i - 1) / 2) / 2;
	}

	int n;
	while (cin >> n)
	{
		if (n < 3) return 0;

		cout << f[n] << '\n';
	}
}