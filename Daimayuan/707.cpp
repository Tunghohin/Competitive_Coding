#include <iostream>
#include <stack>

using namespace std;

typedef long long LL;

const int N = 10000010;
string s;
LL dp[N];
LL matched[N];

void solve()
{
	cin >> s;
	stack<pair<char, int>> stk;

	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] == '(') stk.push({s[i], i + 1});
		else
		{
			if (!stk.empty() && stk.top().first == '(')
			{
				matched[stk.top().second] = i + 1;
				stk.pop();
			}
			else stk.push({s[i], i + 1});
		}
	}

	for (int i = (int)s.length(); i >= 1; i--)
	{
		if (matched[i] == 0) continue;
		dp[i] = dp[matched[i] + 1] + 1;
	}

	unsigned long long res = 0;
	for (int i = 1; i <= (int)s.length(); i++)
	{
		res += dp[i];
	}

	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T = 1;
	while (T--)
	{
		solve();
	}
}