#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define int long long

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int a[200010];

queue<PII> GL, GR;

void solve()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> a[i];

	if (k == 1 || k == n)
	{
		cout << "Yes\n";
		return;
	}

	while (!GL.empty()) GL.pop();
	while (!GR.empty()) GR.pop();

	for (int l = k + 1; l <= n; l++)
	{
		int sum = a[l];
		int min_num = sum;
		while (sum < 0 && l < n)
		{
			sum += a[++l];
			min_num = min(min_num, sum);
		}
		GR.push({sum, min_num});
	}
	for (int l = k - 1; l >= 1; l--)
	{
		int sum = a[l];
		int min_num = sum;
		while (sum < 0 && l > 1)
		{
			sum += a[--l];
			min_num = min(min_num, sum);
		}
		GL.push({sum, min_num});
	}

	// while (!GL.empty())
	// {
	// 	cout << GL.front().first << ' ' << GL.front().second << '\n';
	// 	GL.pop();
	// }

	// cout << '\n';

	// while (!GR.empty())
	// {
	// 	cout << GR.front().first << ' ' << GR.front().second << '\n';
	// 	GR.pop();
	// }

	int HP_cnt = a[k];
	while (!GR.empty() && !GL.empty())
	{
		//cout << HP_cnt << '\n';
		bool flag = false;
		//cout << GL.front().first << ' ' << GL.front().second << '\n';
		if (HP_cnt + GL.front().second >= 0)
		{
			HP_cnt += GL.front().first;
			GL.pop();
			flag = true;
		}
		//cout << HP_cnt << '\n';
		if (HP_cnt + GR.front().second >= 0)
		{
			HP_cnt += GR.front().first;
			GR.pop();
			flag = true;
		}
		//cout << HP_cnt << '\n';
		//cout << GR.front().first << ' ' << GR.front().second << '\n';
		//cout << '\n';
		if (!flag) break;
	}

	if (GL.empty() || GR.empty()) cout << "Yes\n";
	else cout << "No\n";
}

signed main()
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