#include <iostream>
#include <vector>

using namespace std;

int a[100010];
vector<int> pos[1000010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pos[a[i]].push_back(i);
	}

	long long res = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		if (a[i] != a[i - 1]) res++;
	}

	for (int i = 1; i <= m; i++)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			int x, y;
			cin >> x >> y;

			if (x == y) continue;
			if (pos[x].size() > pos[y].size())
			{
				swap(pos[x], pos[y]);
			}
			if (pos[y].empty()) continue;
			auto modify = [&](int p, int col)
			{
			  res -= (a[p - 1] != a[p]) + (a[p] != a[p + 1]);
			  a[p] = col;
			  res += (a[p - 1] != a[p]) + (a[p] != a[p + 1]);
			};

			int col = a[pos[y][0]];
			for (int p : pos[x])
			{
				modify(p, col);
				pos[y].push_back(p);
			}
			pos[x].clear();
		}
		else
		{
			cout << res - 1 << '\n';
		}
	}
}