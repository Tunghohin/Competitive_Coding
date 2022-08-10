#include <iostream>

using namespace std;

int a[100010];
int64_t dw[100010], up[100010];
void solve()
{
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] >= a[i - 1])
		{
			up[i] = up[i - 1] + (a[i] - a[i - 1]);
			dw[i] = dw[i - 1];
		}
		else
		{
			dw[i] = dw[i - 1] + (a[i - 1] - a[i]);
			up[i] = up[i - 1];
		}
	}

	for (int i = 1; i <= q; i++)
	{
		int l, r;
		cin >> l >> r;
		if (l <= r)
		{
			cout << dw[r] - dw[l] << '\n';
		}
		else cout << up[l] - up[r] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}