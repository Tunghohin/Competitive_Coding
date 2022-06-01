#include <iostream>

using namespace std;

int main()
{
	long long n;
	cin >> n;

	long long res = 0;
	for (long long l = 1; l <= n; l++)
	{
		long long d = n / l, r = n / d;
		res += d * (r - l + 1);
		l = r;
	}
	cout << res << '\n';
}