#include <iostream>

using namespace std;

const int N = 1010;

int a[N];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int length = 1;
		for (int j = i - 1, k = i + 1; j >= 1 && k <= n && a[j] == a[k]; j--, k++)
		{
			length += 2;
		}
		res = max(res, length);

		length = 0;
		for (int j = i, k = i + 1; j >= 1 && k <= n && a[j] == a[k]; j--, k++)
		{
			length += 2;
		}
		res = max(res, length);
	}

	cout << res << '\n';
}