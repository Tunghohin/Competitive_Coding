#include <iostream>
#include <cmath>

using namespace std;

const int N = 150001;

int a[N];
int tag[401][401];

void solve()
{
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		for (int p = 1; p <= 400; p++)
		{
			tag[p][i % p] += a[i];
		}
	}

	for (int i = 1; i <= q; i++)
	{
		char op;
		cin >> op;

		if (op == 'A')
		{
			int x, y;
			cin >> x >> y;

			if (x > 400)
			{
				long long res = 0;
				for (int j = y; j <= n; j += x)
				{
					res += a[j];
				}
				cout << res << '\n';
			}
			else
			{
				cout << tag[x][y] << '\n';
			}
		}
		else
		{
			int x, y;
			cin >> x >> y;

			for (int p = 1; p <= 400; p++)
			{
				tag[p][x % p] = tag[p][x % p] - a[x] + y;
			}

			a[x] = y;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}