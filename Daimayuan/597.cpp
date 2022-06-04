#include <iostream>

using namespace std;

int d[1010];

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
		d[a]++, d[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		cout << d[i] << ' ';
	}
	cout << '\n';
}
