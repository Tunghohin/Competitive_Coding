#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int arr[200010];

void solve()
{
	int n;
	cin >> n;

	long long HP = 0;
	priority_queue<long long, vector<long long>, greater<long long>> q;

	for (int i = 1; i <= n; i++)
	{
		long long x;
		cin >> x;
		HP += x;
		q.push(x);

		while (HP < 0)
		{
			HP -= q.top();
			q.pop();
		}
	}

	cout << q.size() << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	T = 1;

	while (T--)
	{
		solve();
	}
}