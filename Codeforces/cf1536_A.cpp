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
		int n;
		cin >> n;

		bool flag = true;

		for (int i = 0; i < n;i++)
		{
			int x;
			cin >> x;
			if (x < 0) flag = false;
		}

		if (!flag) cout << "No\n";
		else
		{
			cout << "Yes\n";
			cout << 101 << '\n';
			for (int i = 0; i <= 100; i++) cout << i << ' ';
			cout << '\n';
		}
	}
}