#include <iostream>

using namespace std;

void init(int a[], int n)
{
	for (int i = 0; i <= n; i++) a[i] = 0;
}

void init(bool a[], int n)
{
	for (int i = 0; i <= n; i++) a[i] = false;
}

int a[2010];
int bucket[2010];
int change[2010][2010];
void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int q;
	cin >> q;

	for (int i = 1; i <= n; i++) change[0][i] = a[i];

	for (int i = 1; i <= n; i++)
	{
		init(bucket, n);
		for (int j = 1; j <= n; j++) bucket[change[i - 1][j]]++;
		for (int j = 1; j <= n; j++) change[i][j] = bucket[change[i - 1][j]];
	}

	while (q--)
	{
		int x, k;
		cin >> x >> k;
		if (k <= n)
		{
			cout << change[k][x] << '\n';
			continue;
		}
		else
		{
			cout << change[n][x] << '\n';
		}
	}
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