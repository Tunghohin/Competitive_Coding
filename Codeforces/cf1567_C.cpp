#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	string s;
	cin >> s;
	int sum_odd = 0;
	int sum_even = 0;

	int base = 1;
	for (int i = s.length() - 1; i >= 0; i -= 2)
	{
		sum_odd += base * (s[i] - '0');
		base *= 10;
	}

	base = 1;
	for (int i = s.length() -2; i >= 0; i -= 2)
	{
		sum_even += base * (s[i] - '0');
		base *= 10;
	}

	int sum = (sum_odd + 1) * (sum_even + 1) - 2;

	cout << sum << '\n';
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