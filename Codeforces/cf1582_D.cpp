#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long a[100010];
long long b[100010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	if (n % 2 == 0)
	{
		for (int i = 1; i <= n; i += 2)
		{
			b[i] = -a[i + 1];
			b[i + 1] = a[i];
		}
	}

	else
	{
		for (int i = 4; i <= n; i += 2)
		{
			b[i] = -a[i + 1];
			b[i + 1] = a[i];
		}

		long long pos1 = a[1], pos2 = a[2], pos3 = a[3];
		if (pos1 + pos2 != 0)
		{
			b[1] = pos3, b[2] = pos3, b[3] = -(pos1 + pos2);
		}
		else if (pos1 + pos3 != 0)
		{
			b[1] = pos2, b[3] = pos2, b[2] = -(pos1 + pos3);
		}
		else
		{
			b[2] = pos1, b[3] = pos1, b[1] = -(pos2 + pos3);
		}
	}

	for (int i = 1; i <= n; i++) cout << b[i] << ' ';
	cout << '\n';
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