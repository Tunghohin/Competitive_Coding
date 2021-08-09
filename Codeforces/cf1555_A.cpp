#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		cout << max(6LL, n + 1) / 2 * 5 << '\n';
	}

	return 0;
}