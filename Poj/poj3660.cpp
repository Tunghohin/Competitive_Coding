#include <iostream>
#include <cstring>
#define nullptr 0

using namespace std;

bool G[110][110];
bool closure[110][110];


void floyd(int n)
{
	memcpy(closure, G, sizeof(G));
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				closure[i][j] |= closure[i][k] && closure[k][j];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;

		G[a][b] = true;
	}

	floyd(n);

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		bool flag = true;
		for (int j = 1; j <= n; j++)
		{
			if (closure[i][j] || closure[j][i] || i == j) continue;
			else
			{
				flag = false;
				break;
			}
		}

		if (flag) cnt++;
	}

	cout << cnt;

	return 0;
}