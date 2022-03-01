#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		long long n, x, y;
		cin >> n >> x >> y;

		long long sum = 0;
		for (long long i = 1; i <= n; i++)
		{
			long long num;
			cin >> num;
			sum += num;
		};

		if ((sum + x + y) % 2 == 0)
		{
			cout << "Alice\n";
		}
		else cout << "Bob\n";
	}
}