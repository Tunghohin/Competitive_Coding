#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int a[100010];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	priority_queue<int, vector<int>> max_q;
	priority_queue<int, vector<int>, greater<int>> min_q;

	int mid = a[1];
	cout << a[1] << '\n';
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			if (a[i] >= mid) min_q.push(a[i]);
			else max_q.push(a[i]);
		}
		else
		{
			if (a[i] >= mid) min_q.push(a[i]);
			else max_q.push(a[i]);
			if (max_q.size() == min_q.size())
			{
				cout << mid << '\n';
				continue;
			}
			if (min_q.size() > max_q.size())
			{
				max_q.push(mid);
				mid = min_q.top();
				min_q.pop();
			}
			else
			{
				min_q.push(mid);
				mid = max_q.top();
				max_q.pop();
			}
			cout << mid << '\n';
		}
	}
}