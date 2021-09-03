#include <iostream>
#include <algorithm>

using namespace std;

struct edge
{
	int f, t, v;

	bool operator < (const edge &E) const
	{
		return v < E.v;
	}
}e[10010];

int p[110];
int find(int x)
{
	if (p[x] != x) return p[x] = find(p[x]);
	return p[x];
}

bool kruskal(int l, int r, int n)
{
	int size = 1;
	for (int i = 0; i <= n; i++) p[i] = i;

	for (int i = l; i <= r; i++)
	{
		int a = e[i].f, b = e[i].t;

		a = find(a), b = find(b);
		if (a != b)
		{
			p[b] = a;
			size++;
		}
	}

	if (size == n) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;

	while (cin >> n >> m, n || m)
	{
		for (int i = 1; i <= m; i++)
		{
			int f, t, v;
			cin >> f >> t >> v;
			e[i] = {f, t, v};
		}

		sort(e + 1, e + 1 + m);
		int res = 0x3f3f3f3f;
		for (int i = 1; i <= m; i++)
		{
			for (int j = i; j <= m; j++)
			{
				if(kruskal(i, j, n))
				{
					res = min(res, e[j].v - e[i].v);
					break;
				}
			}
		}

		if (res == 0x3f3f3f3f) cout << -1 << '\n';
		else cout << res << '\n';
	}
}