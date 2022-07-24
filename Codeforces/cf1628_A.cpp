#include <iostream>
#include <vector>

using namespace std;


void solve()
{
	int n;
	cin >> n;

	vector<int> a(200010);
	vector<vector<int>> pos(200010);

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pos[a[i]].push_back(i);
	}

	vector<int> b;
	for (int l = 1, r; l <= n; l = r + 1)
	{
		r = l;
		int mex = 0;
		for (; mex <= n + 1; mex++)
		{
			auto it = lower_bound(pos[mex].begin(), pos[mex].end(), l);
			if (it == pos[mex].end()) break;
			r = max(*it, r);
		}
		b.push_back(mex);
	}

	cout << b.size() << '\n';
	for (auto i : b) cout << i << ' ';
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