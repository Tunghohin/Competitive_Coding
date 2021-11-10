#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int a[510];
int res[510][510];
int dx[2] = {0, 1};
int dy[2] = {-1, 0};

int cnt;
void insert(int x, int y, int val, int n)
{
	if (cnt >= val) return;
	res[x][y] = val;
	cnt++;

	for (int i = 0; i < 2; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (!res[xx][yy] && xx <= n && yy >= 1)
		{
			insert(xx, yy, val, n);
		}
	}
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		cnt = 0;
		insert(i, i, a[i], n);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	T = 1;

	while (T--)
	{
		solve();
	}
}