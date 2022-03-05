#include <iostream>
#include <unordered_map>
#include <deque>
#define int long long

using namespace std;

int a[200010];
long long pre_s[200010];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	unordered_map<long long, int> mp;
	deque<int> dq;

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pre_s[i] = pre_s[i - 1] + a[i];
	}

	mp[0] = 1;
	dq.push_back({0});
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dq.front() < i - k + 1)
		{
			mp[(pre_s[dq.front()] - dq.front()) % k]--;
			dq.pop_front();
		}

		res += mp[(pre_s[i] - i) % k];
		dq.push_back(i);
		mp[(pre_s[i] - i) % k]++;
	}

	cout << res;
}