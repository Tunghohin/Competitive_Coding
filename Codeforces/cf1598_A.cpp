#include <iostream>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	string fst, scd;
	cin >> fst >> scd;


	for (int i = 0; i < n; i++)
	{
		if (fst[i] == '1' && scd[i] == '1')
		{
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
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