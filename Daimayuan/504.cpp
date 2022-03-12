#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

int a[200010];
int dp[200010];
int pre[200010];
int max_num[200010];

void solve()
{
	unordered_map<int, int> mp;
	memset(max_num, 0x3f, sizeof(max_num));

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int max_res = -1;
	int max_idx = -1;
	for (int i = 1; i <= n; i++)
	{
		if (mp.count(a[i] - 1))
		{
			dp[i] = dp[mp[a[i] - 1]] + 1;
			pre[i] = mp[a[i] - 1];
		}
		else
		{
			dp[i] = 1;
			pre[i] = -1;
		}

		mp[a[i]] = i;

		if (dp[i] > max_res)
		{
			max_res = dp[i];
			max_idx = i;
			max_num[dp[i]] = a[i];
		}
		else if (dp[i] == max_res && a[i] < max_num[dp[i]])
		{
			max_idx = i;
			max_num[dp[i]] = a[i];
		}
	}

	vector<int> nums;
	while (true)
	{
		nums.push_back(a[max_idx]);
		if (pre[max_idx] == -1) break;
		max_idx = pre[max_idx];
	}

	cout << nums.size() << '\n';
	while (!nums.empty())
	{
		cout << nums.back() << ' ';
		nums.pop_back();
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	T = 1;

	while (T--)
	{
		solve();
	}
}