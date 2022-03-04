#include <iostream>

using namespace std;

int p[200010];
int size[200010];

int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

struct edge
{
	int from, to;
	int val;
}e[400010];

bool check(int k, int n, int m, int cur)
{
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
		size[i] = 1;
	}

	for (int i = 0; i < m; i++)
	{
		bool enable = true;
		for (int j = 30; j >= k; j--)
		{
			if (((cur >> j) & 1) == 0 && ((e[i].val >> j) & 1) == 1)
			{
				enable = false;
				break;
			}
		}
		if (!enable) continue;

		int a = e[i].from, b = e[i].to;
		int fa = find(a), fb = find(b);

		if (fa != fb)
		{
			size[fa] += size[fb];
			p[fb] = fa;
		}
	}

	if (size[find(1)] == n) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int f, t, v;
		cin >> f >> t >> v;

		e[i] = {f, t, v};
	}

	int res = 0;
	for (int k = 30; k >= 0; k--)
	{
		if (!check(k, n, m, res)) res += (1 << k);
	}

	cout << res;

	return 0;
}