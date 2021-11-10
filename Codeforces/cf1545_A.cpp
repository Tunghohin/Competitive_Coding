#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int arr[100010];
int A[100010][2];

void solve()
{
	int n;
	cin >> n;

	memset(A, 0, sizeof(A));

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		A[arr[i]][i % 2]++;
	}

	sort(arr + 1, arr + 1 + n);

	for (int i = 1; i <= n; i++)
	{
		A[arr[i]][i % 2]--;
	}

	for (int i = 1; i <= n; i++)
	{
		if (A[arr[i]][1] || A[arr[i]][0])
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