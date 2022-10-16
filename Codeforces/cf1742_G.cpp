#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int a[200010];
bool vis[200010];

void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		vis[i] = false;
	}

	vector<int> res;
	int mx_or = 0;
	for (int k = 1; k <= min(30, n); k++)
	{
		int cur_or = mx_or;
		int num = 0;
		int idx = -1;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i]) continue;
			if ((mx_or | a[i]) > cur_or)
			{
				cur_or = (mx_or | a[i]);
				num = a[i];
				idx = i;
			}
		}

		if (idx != -1)
		{
			res.push_back(num);
			vis[idx] = true;
			mx_or |= num;
		}
	}

	for (int i = 1; i <= n; i++) if (!vis[i]) res.push_back(a[i]);

	for (auto u : res) cout << u << ' ';
	cout << '\n';
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