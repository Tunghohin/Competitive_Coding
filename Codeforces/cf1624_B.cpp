#include <iostream>

using namespace std;

void solve()
{
	long long a, b, c;
	cin >> a >> b >> c;

	bool flag = false;
	int d = c - b;
	int need_a = b - d;
	if (need_a >= a && need_a % a == 0) flag = true;
	d = b - a;
	int need_c = b + d;
	if (need_c >= c && need_c % c == 0) flag = true;
	d = c - a;
	int need_b = a + (d / 2);
	if (d % 2 == 0 && need_b >= b && need_b % b == 0) flag = true;

	flag? cout << "Yes\n" : cout << "No\n"; 
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