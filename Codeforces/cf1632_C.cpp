#include <iostream>

using namespace std;

//根据 | 的性质，（1）op3(a) >= b, 且（2）使得 a 至少增加 1，所以多次进行 op3 一定是负收益的。
//最优操作一定是形如 111.....3....222
//我们调整 op3 执行的位置，根据（2）每次进行 op3，若提早/延后做，可抵消最少 1 个操作 a/b，因此我们只对两种方法的结果取 min

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