#include <iostream>

using namespace std;

const int N = 200010, M = 510;
long long val[N];
long long tag[M + 10][M + 10];

void solve()
{
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= q; i++)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x, y, d;
			cin >> x >> y >> d;
			if (x > M)
			{
				for (int j = y; j <= n; j += x)
				{
					val[j] += d;
				}
			}
			else
			{
				tag[x][y] += d;
			}
		}
		else
		{
			int x;
			cin >> x;
			long long res = val[x];

			for (int j = 1; j <= M; j++)
			{
				res += tag[j][x % j];
			}

			cout << res << '\n';
		}
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