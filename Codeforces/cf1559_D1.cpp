#include <iostream>
#include <vector>

using namespace std;

int p1[1010];
int p2[1010];
int p1_s[1010];
int p2_s[1010];

int find(int x, int *p)
{
	if (p[x] != x) p[x] = find(p[x], p);
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m1, m2;
	cin >> n >> m1 >> m2;

	for (int i = 0; i <= n; i++) p1[i] = i, p2[i] = i, p1_s[i] = 1, p2_s[i] = 1;

	int max_1 = 1, max_2 = 2;
	for (int i = 1; i <= m1; i++)
	{
		int x, y;
		cin >> x >> y;
		p1_s[find(x, p1)] += p1_s[find(y, p1)];
		p1[find(y, p1)] = find(x, p1);
		max_1 = max(max_1, p1_s[find(x, p1)]);
	}

	for (int i = 1; i <= m2; i++)
	{
		int x, y;
		cin >> x >> y;
		p2_s[find(x, p2)] += p2_s[find(y, p2)];
		p2[find(y, p2)] = find(x, p2);
		max_2 = max(max_2, p2_s[find(x, p2)]);
	}

	if (max_1 == n || max_2 == n) cout << 0 << '\n';
	else
	{
		int cnt = 0;
		vector<pair<int, int>> res;
		bool flag = true;

		for (int i = 1; i <= n && flag; i++)
		{
			for (int j = 1; j < i && flag; j++)
			{
				if (find(i, p1) != find(j, p1) && find(i, p2) != find(j, p2))
				{
					p1_s[find(i, p1)] += p1_s[find(j, p1)];
					p1[find(j, p1)] = find(i, p1);
					max_1 = max(max_1, p1_s[find(i, p1)]);

					p2_s[find(i, p2)] += p2_s[find(j, p2)];
					p2[find(j, p2)] = find(i, p2);
					max_2 = max(max_2, p2_s[find(i, p2)]);

					res.push_back({i, j});
					cnt++;

					if (max_1 == n || max_2 == n)
					{
						flag = false;
						break;
					}
				}
			}
		}

		cout << cnt << '\n';
		for (auto i : res) cout << i.first << ' ' << i.second << '\n';
	}

	return 0;
}