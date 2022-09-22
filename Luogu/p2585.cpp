#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 500010;

string s;
int tr[N][2];
LL mx_dp[N][3]; //r g b;
LL mn_dp[N][3];

int timestamp = 0;
int build()
{
	int now = ++timestamp;
	if (s[timestamp - 1] == '2')
	{
		tr[now][0] = build();
		tr[now][1] = build();
	}
	else if (s[timestamp - 1] == '1')
	{
		tr[now][0] = build();
	}

	return now;
}

void dfs(int u)
{
	int ls = tr[u][0], rs = tr[u][1];

	if (ls) dfs(ls);
	if (rs) dfs(rs);

	if (!ls && !rs)
	{
		mx_dp[u][1] = mn_dp[u][1] = 1;
		mx_dp[u][0] = mn_dp[u][0] = 0;
		mx_dp[u][2] = mn_dp[u][2] = 0;
		return;
	}

	mx_dp[u][0] = max(mx_dp[ls][1] + mx_dp[rs][2], mx_dp[ls][2] + mx_dp[rs][1]);
	mx_dp[u][1] = max(mx_dp[ls][0] + mx_dp[rs][2], mx_dp[ls][2] + mx_dp[rs][0]) + 1;
	mx_dp[u][2] = max(mx_dp[ls][1] + mx_dp[rs][0], mx_dp[ls][0] + mx_dp[rs][1]);

	mn_dp[u][0] = min(mn_dp[ls][1] + mn_dp[rs][2], mn_dp[ls][2] + mn_dp[rs][1]);
	mn_dp[u][1] = min(mn_dp[ls][0] + mn_dp[rs][2], mn_dp[ls][2] + mn_dp[rs][0]) + 1;
	mn_dp[u][2] = min(mn_dp[ls][1] + mn_dp[rs][0], mn_dp[ls][0] + mn_dp[rs][1]);
}

void solve()
{
	cin >> s;

	build();

	dfs(1);

	mx_dp[0][0] = mx_dp[0][1] = mx_dp[0][2] = 0;


	cout << max({mx_dp[1][0], mx_dp[1][1], mx_dp[1][2]}) << ' ';
	cout << min({mn_dp[1][0], mn_dp[1][1], mn_dp[1][2]});
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}