#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using PII = pair<int, int>;

void solve()
{
	int n, H, M;
	cin >> n >> H >> M;

	vector<PII> v;
	for (int i = 1; i <= n; i++)
	{
		int h, m;
		cin >> h >> m;
		v.push_back({h, m});
	}

	sort(v.begin(), v.end());
	if (H > v.back().first || (H == v.back().first && M > v.back().second))
	{
		int res_H = (v[0].first - H + 24) % 24, res_M = (v[0].second - M + 60) % 60;
		if (v[0].second < M) res_H = (res_H - 1 + 24) % 24;
		cout << res_H << ' ' << res_M << '\n';
		return;
	}
	else
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] < make_pair(H, M)) continue;

			int res_H = (v[i].first - H + 24) % 24, res_M = (v[i].second - M + 60) % 60;
			if (v[i].second < M) res_H = (res_H - 1 + 24) % 24;
			cout << res_H << ' ' << res_M << '\n';
			return;
		}
	}
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