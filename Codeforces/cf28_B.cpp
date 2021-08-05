#include <iostream>

using namespace std;

int fav_num[110], aim[110], p[110];

int find(int x)
{
	if (p[x] != x) return p[x] = find(p[x]);
	return p[x];
}

void uni(int x, int y)
{
	int px = find(x), py = find(y);
	if (px != py) p[py] = px;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
		cin >> aim[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> fav_num[i];
		if (i > fav_num[i]) uni(i, i - fav_num[i]);
		if (i + fav_num[i] <= n) uni(i, i + fav_num[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (find(i) != find(aim[i]))
		{
			cout << "NO" << '\n';
			return 0;
		}
	}

	cout << "YES" << '\n';

	return 0;
}