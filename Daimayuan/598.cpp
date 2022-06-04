#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	long long tot = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		tot += x;
	}
	if (tot & 1)
	{
		cout << "No\n";
	}
	else cout << "Yes\n";
}