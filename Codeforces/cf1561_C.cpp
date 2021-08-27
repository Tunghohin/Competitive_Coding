#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int cave[100010];

void solve()
{
	int n;
	cin >> n;

	vector<PII> v;
	for (int i = 0; i < n; i++)
	{
		int tot;
		cin >> tot;

		int in = - 0x3f3f3f3f;
		for (int j = 0; j < tot; j++)
		{
			int x;
			cin >> x;
			in = max(in, x - j);
		}

		v.push_back({in + 1, tot});
	}

	sort(v.begin(), v.end());

	int pre_size = 0;
	int res = -0x3f3f3f3f;
	for (int i = 0; i < v.size(); i++)
	{
		res = max(res, v[i].first - pre_size);
		pre_size += v[i].second;
	}

	cout << res  << '\n';
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