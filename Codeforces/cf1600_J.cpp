#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int G[1010][1010];
bool vis[1010][1010];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int size = 0;

void dfs(int x, int y)
{
	vis[x][y] = true;
	size++;

	int tmp = G[x][y];
	for (int i = 0; i < 4; i++)
	{
		if (!(tmp >> i & 1))
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (!vis[xx][yy])
			{
				dfs(xx, yy);
			}
		}
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> G[i][j];
		}
	}

	vector<int> res;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!vis[i][j])
			{
				size = 0;
				dfs(i, j);
				res.push_back(size);
			}
		}
	}

	sort(res.begin(), res.end(), greater<int>());
	for (auto i : res) cout << i << ' ';
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T = 1;

	while (T--)
	{
		solve();
	}
}