#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		int half = abs(a - b);
		int full = half * 2;

		if (c > full || a > full || b > full) cout << -1 << '\n';
		else
		{
			if (c + half > full) cout << (c + half) % full << '\n';
			else cout << c + half << '\n';
		}
	}
}