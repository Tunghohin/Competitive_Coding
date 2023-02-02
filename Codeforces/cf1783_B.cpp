#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	deque<int> dq;
	for (int i = 1; i <= n * n; i++) dq.push_back(i);

	int op = 1;
	vector<int> v;
	while (!dq.empty())
	{
		if (op) v.push_back(dq.back()), dq.pop_back();
		else v.push_back(dq.front()), dq.pop_front();
		op = 1 - op;
	}

	for (int i = 0; i < n; i += 2)
	{
		reverse(v.begin() + i * n, v.begin() + i * n + n);
	}

	int cnt = 0;
	for (auto val : v)
	{
		cnt++;
		cout << val << ' ';
		if (cnt == n)
		{
			cout << '\n';
			cnt = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
}