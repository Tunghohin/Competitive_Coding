#include <iostream>
#include <algorithm>

using namespace std;

int a[110], b[110];

void solve()
{
	int n, m;
	cin >> n;
	int mx_a = -1, mx_b = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mx_a = max(mx_a, a[i]);
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
		mx_b = max(mx_b, b[i]);
	}

	if (mx_a != mx_b)
	{
		mx_a > mx_b? cout << "Alice\nAlice\n" : cout << "Bob\nBob\n";
	}
	else
	{
		cout << "Alice\nBob\n";
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