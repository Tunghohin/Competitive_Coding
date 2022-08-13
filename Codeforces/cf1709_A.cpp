#include <iostream>
#include <array>

using namespace std;

int a[10];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= 3; i++) cin >> a[i];

	if (a[n] == 0) cout << "No\n";
	else if (a[a[n]] == 0) cout << "No\n";
	else cout << "Yes\n";
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