#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

long long a[2010];
long long prefix_xor[2010];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) prefix_xor[i] = a[i] ^ prefix_xor[i - 1];

	if (prefix_xor[n] == 0)
	{
		cout << "YES\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (prefix_xor[i] == (prefix_xor[j] ^ prefix_xor[i]) && (prefix_xor[i] == (prefix_xor[n] ^ prefix_xor[j])))
			{
				cout << "YES\n";
				return;
			}
		}
	}

	cout << "NO\n";
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