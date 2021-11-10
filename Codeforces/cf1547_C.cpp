#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int a[110], b[110];
bool vis[110];

void solve()
{
	int k, n, m;
	cin >> k >> n >> m;

	vector<int> res;

	memset(vis, false, sizeof(vis));

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int pa = 0, pb = 0;
	int tot = k;
	for (int i = 0; i < m + n; i++)
	{
		if (!a[pa] && pa < n)
		{
			res.push_back(0);
			tot++;
			pa++;
			continue;
		}
		if (!b[pb] && pb < m)
		{
			res.push_back(0);
			tot++;
			pb++;
			continue;
		}
		if (a[pa] && a[pa] <= tot && pa < n)
		{
			res.push_back(a[pa]);
			pa++;
			continue;
		}
		if (b[pb] && b[pb] <= tot && pb < m)
		{
			res.push_back(b[pb]);
			pb++;
			continue;
		}

		cout << -1 << '\n';
		return;
	}

	int cnt = 0;
	for (auto i : res)
	{
		cout << i << ' ';
	}
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