#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int a[200010];
int b[200010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	b[1] = 0;
	for (int i = 1; i < n; i++)
	{
		int now = a[i] ^ b[i];
		int nxt = a[i + 1];

		int res = 0;
		for (int j = 30; j >= 0; j--)
		{
			int fst = now >> j & 1;
			int sec = nxt >> j & 1;

			if (fst && !sec)
			{
				res += 1 << j;
			}
		}

		b[i + 1] = res;
	}

	for (int i = 1; i <= n; i++) cout << b[i] << ' ';
	cout << '\n';
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}