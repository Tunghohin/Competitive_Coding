#include <iostream>

using namespace std;

int a[5001];
int f[5001];
int pre[5001];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) f[i] = 0;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] < a[i]) f[i]++;
		}
	}

	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[j] > a[i]) f[j]--;
			pre[j] = pre[j - 1] + f[j];
		}

		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i]) res += pre[i - 1] - pre[j];
		}

	}

	cout << res << '\n';
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