#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int a[1000010];

int main()
{
	int n, k, c;
	cin >> n >> k >> c;

	bool flag = false;

	for (int i = 0; i < n; i++) cin >> a[i];

	deque<int> max;
 	deque<int> minn;

	for (int i = 0; i < n; i++)
	{
		if (!max.empty() && max.front() < i - k + 1) max.pop_front();
		while (!max.empty() && a[max.back()] <= a[i]) max.pop_back();
		max.push_back(i);

		if (!minn.empty() && minn.front() < i - k + 1) minn.pop_front();
		while (!minn.empty() && a[minn.back()] >= a[i]) minn.pop_back();
		minn.push_back(i);

		if (i >= k - 1 && abs(a[max.front()] - a[minn.front()]) <= c)
		{
			flag = true;
			cout << i - k + 2 << '\n';
		}
	}

	if (!flag) cout << "NONE";

	return 0;
}