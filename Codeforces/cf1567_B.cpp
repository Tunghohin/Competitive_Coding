#include <iostream>

using namespace std;

int xor_prefix[300010];

void solve()
{
	int a, b;
	cin >> a >> b;

	if (xor_prefix[a - 1] == b) cout << a << '\n';
	else if ((xor_prefix[a - 1] ^ b) != a) cout << a + 1 << '\n';
	else cout << a + 2 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	xor_prefix[0] = 0;
	for (int i = 1; i <= 300000; i++)
	{
		xor_prefix[i] = i ^ xor_prefix[i - 1];
	}

	while (T--)
	{
		solve();
	}
}