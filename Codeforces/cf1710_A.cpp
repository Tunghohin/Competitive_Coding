#include <iostream>

using namespace std;

int color[100010];
void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	bool flag = true;
	for (int i = 1; i <= k; i++)
	{
		cin >> color[i];
		if (color[i] < 4) flag = false;
	}
	if (!flag)
	{
		cout << "No\n";
		return;
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