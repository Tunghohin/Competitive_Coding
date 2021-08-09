#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int n, maxn = -1e9;
		long long sum = 0;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			sum += x;
			maxn = max(maxn, x);
		}

		sum -= maxn;
		cout << fixed << setprecision(10) << maxn + static_cast<double>(sum) / (n - 1) << '\n';
	}

	return 0;
}