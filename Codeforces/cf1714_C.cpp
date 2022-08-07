#include <iostream>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	string num;
	for (int i = 9; i >= 1; i--)
	{
		if (!n) break;
		if (n >= i)
		{
			num.push_back('0' + i);
			n -= i;
		}
		else
		{
			num.push_back('0' + n);
			break;
		}
	}

	for (int i = num.length() - 1; i >= 0; i--) cout << num[i];
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}