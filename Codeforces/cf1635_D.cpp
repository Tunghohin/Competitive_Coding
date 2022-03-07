#include <iostream>
#include <algorithm>
#include <map>
#define int long long

using namespace std;

int dp[200010];
int a[200010];
const int MOD = 1000000007;

signed main()
{
	int n, p;
	cin >> n >> p;

	map<string, int> s;

	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n; i++)
	{
		int x;
		x = a[i];

		int length = 0;
		string tmp;
		for (int k = 30; k >= 0; k--)
		{
			int bit = (x >> k) & 1;
			if (bit && !length) length = k + 1;
			if (length) tmp.push_back((char)(bit + '0'));
		}
		s[tmp]++;
		dp[tmp.size()]++;

		string last_change = tmp;
		while (true)
		{
			bool has_change = false;

			if (tmp.back() == '1' && tmp.size() > 1)
			{
				tmp.pop_back();
				has_change = true;
			}
			else if (tmp[tmp.size() - 1] == '0' && tmp[tmp.size() - 2] == '0' && tmp.size() > 2)
			{
				tmp.pop_back();
				tmp.pop_back();
				has_change = true;
			}

			if (has_change && s[tmp])
			{
				dp[last_change.size()]--;
				s[last_change]--;
				s[tmp]++;
				last_change = tmp;
			}

			if (!has_change) break;
		}
	}

	int sum = dp[1];
	for (int i = 2; i <= p; i++)
	{
		dp[i] = (dp[i] + dp[i - 1] + dp[i - 2]) % MOD;
		sum = (sum + dp[i]) % MOD;
	}

	cout << sum;
}