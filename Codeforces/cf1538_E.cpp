#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

long long num_11[20];

void solve()
{
	string l, r;
	cin >> l >> r;

	reverse(l.begin(), l.end());
	reverse(r.begin(), r.end());

	while (l.size() < r.size()) l.push_back('0');

	long long res = 0;
	for (int i = (int)l.length() - 1; i >= 0; i--)
	{
		res += ((r[i] - '0') - (l[i] - '0')) * num_11[i];
	}

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	num_11[0] = 1;
	for (int i = 1; i <= 9; i++)
	{
		num_11[i] = (10 * num_11[i - 1]) + 1;
	}

	while (T--)
	{
		solve();
	}
}