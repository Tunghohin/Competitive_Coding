#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int u_id[200010];
int skill[200010];

void solve()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%d", &u_id[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &skill[i]);

	vector<vector<int>> v(n + 10);
	for (int i = 1; i <= n; i++) v[u_id[i]].push_back(skill[i]);
	for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end(), greater<int>());

	vector<vector<long long>> s(n + 10, vector<long long>(1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (auto u : v[i]) s[i].push_back(s[i].back() + u);
	}

	vector<long long> res(n + 10);
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= int(v[i].size()); k++)
		{
			res[k] += s[i][v[i].size() / k * k];
		}
	}

	for (int i = 1; i <= n; i++) printf("%lld ", res[i]);
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		solve();
	}
}