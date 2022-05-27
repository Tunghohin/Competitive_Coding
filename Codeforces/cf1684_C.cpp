#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mp[200010];

void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) mp[i].clear();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num;
			cin >> num;
			mp[i].push_back(num);
		}
	}

	vector<int> res;
	for (int i = 0; i < n && res.empty(); i++)
	{
		vector<int> tmp = mp[i];
		sort(tmp.begin(), tmp.end());
		for (int j = 0; j < m; j++)
		{
			if (mp[i][j] != tmp[j]) res.push_back(j);
		}
	}

	if (res.size() == 0)
	{
		cout << 1 << ' ' << 1 << '\n';
		return;
	}
	if (res.size() > 2)
	{
		cout << -1 << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		swap(mp[i][res[0]], mp[i][res[1]]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (mp[i][j] > mp[i][j + 1])
			{
				cout << -1 << '\n';
				return;
			}
		}
	}
	cout << res[0] + 1 << ' ' << res[1] + 1 << '\n';
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