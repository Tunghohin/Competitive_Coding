#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		string s;
		cin >> s;

		int maxn = 0;
		for (auto i : s)
		{
			maxn = max(maxn, i - '0');
		}

		cout << maxn << '\n';
	}
}