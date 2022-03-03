#include <iostream>

using namespace std;

void solve()
{
	int a, b;
	cin >> a >> b;

	int cur_a = a;
	while ((cur_a | b) != b)
	{
		cur_a++;
	}

	long long res_1 = cur_a - a + (cur_a != b);

	int cur_b = b;
	while ((a | cur_b) != cur_b)
	{
		cur_b++;
	}

	long long res_2 = cur_b - b + 1;

	cout << min(res_1, res_2) << '\n';
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