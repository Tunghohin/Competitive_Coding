#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;

int num_cnt[10];
LL fact[20];
LL ans = 0;

void dfs(int step, string &s)
{
	//cout << s << '\n';
	if (step == 10)
	{
		int sum = 0;
		for (int i = 0; i < 10; i++)
		{
			sum += (s[i] - '0');
		}
		LL res = fact[sum];
		for (int i = 0; i < 10; i++)
		{
			if (s[i] != '0') res /= fact[s[i] - '0'];
		}

		if (s[0] != '0')
		{
			LL sub_res = fact[sum - 1] / fact[s[0] - '0' - 1];
			for (int i = 1; i < 10; i++)
			{
				if (s[i] != '0') sub_res /= fact[s[i] - '0'];
			}
			res -= sub_res;
		}

		ans += res;
		return;
	}

	if (!num_cnt[step]) return dfs(step + 1, s);
	for (int i = 1; i <= num_cnt[step]; i++)
	{
		s[step] = i + '0';
		dfs(step + 1, s);
	}
}

void solve()
{
	string num;
	cin >> num;

	for (auto c : num)
	{
		num_cnt[c - '0']++;
	}

	string s = "0000000000";

	dfs(0, s);
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	T = 1;

	fact[0] = 1;
	for (int i = 1; i <= 19; i++)
	{
		fact[i] = fact[i - 1] * (LL)i;
		//cout << fact[i] << '\n';
	}

	while (T--)
	{
		solve();
	}
}