#include <iostream>

using namespace std;

int add_pre[3010];
int min_pre[3010];

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	for (int i = 1; i <= n; i++)
	{
		add_pre[i] = (s[i - 1] == '+') + add_pre[i - 1];
		min_pre[i] = (s[i - 1] == '-') + min_pre[i - 1];
	}

	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int add_cnt = add_pre[j] - add_pre[i - 1];
			int min_cnt = min_pre[j] - min_pre[i - 1];

			if (min_cnt >= add_cnt && (min_cnt - add_cnt) % 3 == 0)
			{
				res++;
			}
		}
	}

	cout << res << '\n';
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}